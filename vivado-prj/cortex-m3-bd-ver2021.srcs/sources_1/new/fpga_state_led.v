`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/11/29 16:15:36
// Design Name: 
// Module Name: fpga_state_led
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


module fpga_state_led(
    input sys_clk,
    input rst_n,
    output core_led
    );

    reg [31:0] cnt_500ms;
    reg core_led_reg;
    parameter CNT_500MS = 25000000 ;
    assign core_led = core_led_reg;
    always@(posedge sys_clk) begin
        if(!rst_n)begin
            cnt_500ms <= 32'd0;
            core_led_reg <= 0;
        end
        else if(cnt_500ms == CNT_500MS - 1) begin
            cnt_500ms <= 32'd0;
            core_led_reg <= ~core_led_reg;
        end
        else begin
            cnt_500ms <= cnt_500ms + 32'd1;
            core_led_reg <= core_led_reg;
        end
    end
endmodule
