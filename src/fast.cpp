#include "fast.h"
#include <ap_int.h>

int abs_diff(int in1, int in2) {
#pragma HLS INLINE
    if(in1 > in2)
        return in1 - in2;
    else
        return in2 - in1;
}

void fast_accel(DTYPE *img_in, int threshold, DTYPE *img_out, int rows, int cols) {
#pragma HLS INTERFACE m_axi port=img_in offset=slave depth=16385
#pragma HLS INTERFACE m_axi port=img_out offset=slave depth=16385
#pragma HLS INTERFACE s_axilite port=threshold bundle=CTRL
#pragma HLS INTERFACE s_axilite port=rows bundle=CTRL
#pragma HLS INTERFACE s_axilite port=cols bundle=CTRL
#pragma HLS INTERFACE s_axilite port=return bundle=CTRL

    const int circleOffsets[16][2] = {
        {0, 3}, {1, 3}, {2, 2}, {3, 1}, {3, 0}, {3, -1}, {2, -2}, {1, -3},
        {0, -3}, {-1, -3}, {-2, -2}, {-3, -1}, {-3, 0}, {-3, 1}, {-2, 2}, {-1, 3}
    };

    const int earlyExitPoints[4] = {0, 4, 8, 12};

    // Initialize the output array to zero
    for (int i = 0; i < rows * cols; i++) {
#pragma HLS PIPELINE II=1
        img_out[i] = 0;
    }

    // Apply the FAST algorithm
    for (int y = 3; y < rows - 3; y++) {
        for (int x = 3; x < cols - 3; x++) {
#pragma HLS PIPELINE II=1
            int center = img_in[y * cols + x];
            int cIdx = y * cols + x;
            bool isCorner = false;
            int greaterCount = 0;
            int lesserCount = 0;

            for (int i = 0; i < 4; i++) {
#pragma HLS UNROLL
                int diff = img_in[cIdx + circleOffsets[earlyExitPoints[i]][0] + circleOffsets[earlyExitPoints[i]][1] * cols] - center;
                if (diff > threshold)
                    greaterCount++;
                else if (diff < -threshold)
                    lesserCount++;
            }

            if ((greaterCount + lesserCount) >= 3) {
                int numGreaterPoints = 0;
                int numLesserPoints = 0;
                for (int i = 0; i < 16; i++) {
#pragma HLS UNROLL
                    int diff = img_in[cIdx + circleOffsets[i][0] + circleOffsets[i][1] * cols] - center;
                    if (diff > threshold)
                        numGreaterPoints++;
                    else if (diff < -threshold)
                        numLesserPoints++;

                    if ((numGreaterPoints + numLesserPoints) >= 12) {
                        isCorner = true;
                        break;
                    }
                }
            }

            if (isCorner)
                img_out[cIdx] = 255;
        }
    }
}
