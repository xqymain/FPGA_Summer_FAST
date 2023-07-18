// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2022.2 (64-bit)
// Tool Version Limit: 2019.12
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// ==============================================================
// control
// 0x00 : reserved
// 0x04 : reserved
// 0x08 : reserved
// 0x0c : reserved
// 0x10 : Data signal of img_in
//        bit 31~0 - img_in[31:0] (Read/Write)
// 0x14 : Data signal of img_in
//        bit 31~0 - img_in[63:32] (Read/Write)
// 0x18 : reserved
// 0x1c : Data signal of img_out
//        bit 31~0 - img_out[31:0] (Read/Write)
// 0x20 : Data signal of img_out
//        bit 31~0 - img_out[63:32] (Read/Write)
// 0x24 : reserved
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XFAST_ACCEL_CONTROL_ADDR_IMG_IN_DATA  0x10
#define XFAST_ACCEL_CONTROL_BITS_IMG_IN_DATA  64
#define XFAST_ACCEL_CONTROL_ADDR_IMG_OUT_DATA 0x1c
#define XFAST_ACCEL_CONTROL_BITS_IMG_OUT_DATA 64

// CTRL
// 0x00 : Control signals
//        bit 0  - ap_start (Read/Write/COH)
//        bit 1  - ap_done (Read/COR)
//        bit 2  - ap_idle (Read)
//        bit 3  - ap_ready (Read/COR)
//        bit 7  - auto_restart (Read/Write)
//        bit 9  - interrupt (Read)
//        others - reserved
// 0x04 : Global Interrupt Enable Register
//        bit 0  - Global Interrupt Enable (Read/Write)
//        others - reserved
// 0x08 : IP Interrupt Enable Register (Read/Write)
//        bit 0 - enable ap_done interrupt (Read/Write)
//        bit 1 - enable ap_ready interrupt (Read/Write)
//        others - reserved
// 0x0c : IP Interrupt Status Register (Read/TOW)
//        bit 0 - ap_done (Read/TOW)
//        bit 1 - ap_ready (Read/TOW)
//        others - reserved
// 0x10 : Data signal of threshold
//        bit 31~0 - threshold[31:0] (Read/Write)
// 0x14 : reserved
// 0x18 : Data signal of rows
//        bit 31~0 - rows[31:0] (Read/Write)
// 0x1c : reserved
// 0x20 : Data signal of cols
//        bit 31~0 - cols[31:0] (Read/Write)
// 0x24 : reserved
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XFAST_ACCEL_CTRL_ADDR_AP_CTRL        0x00
#define XFAST_ACCEL_CTRL_ADDR_GIE            0x04
#define XFAST_ACCEL_CTRL_ADDR_IER            0x08
#define XFAST_ACCEL_CTRL_ADDR_ISR            0x0c
#define XFAST_ACCEL_CTRL_ADDR_THRESHOLD_DATA 0x10
#define XFAST_ACCEL_CTRL_BITS_THRESHOLD_DATA 32
#define XFAST_ACCEL_CTRL_ADDR_ROWS_DATA      0x18
#define XFAST_ACCEL_CTRL_BITS_ROWS_DATA      32
#define XFAST_ACCEL_CTRL_ADDR_COLS_DATA      0x20
#define XFAST_ACCEL_CTRL_BITS_COLS_DATA      32

