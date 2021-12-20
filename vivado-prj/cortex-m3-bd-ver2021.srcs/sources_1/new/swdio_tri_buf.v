`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/11/28 11:58:21
// Design Name: 
// Module Name: swdio_tri_buf
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module swdio_tri_buf(
    input swd_o,
    input swd_oe,
    output swd_i,
    inout swd_io
);

    IOBUF swd_iobuf_inst(
        .O(swd_i),
        .I(swd_o),
        .IO(swd_io),
        .T(~swd_oe)//T=1 offchip --> onchip;T=0 onchip --> offchip
    );
endmodule
