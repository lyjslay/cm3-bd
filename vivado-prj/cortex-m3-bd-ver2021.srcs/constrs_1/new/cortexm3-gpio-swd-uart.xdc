set_property IOSTANDARD LVCMOS33 [get_ports ext_clk_50m]
set_property IOSTANDARD LVCMOS33 [get_ports swclk]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO_OUT_A_tri_o[7]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO_OUT_A_tri_o[6]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO_OUT_A_tri_o[5]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO_OUT_A_tri_o[4]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO_OUT_A_tri_o[3]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO_OUT_A_tri_o[2]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO_OUT_A_tri_o[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO_OUT_A_tri_o[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports reset_in]
set_property IOSTANDARD LVCMOS33 [get_ports rx_0]
set_property IOSTANDARD LVCMOS33 [get_ports tx_0]
set_property IOSTANDARD LVCMOS33 [get_ports swd_io]
# set_property IOSTANDARD LVCMOS33 [get_ports core_led_0]

set_property PACKAGE_PIN G22 [get_ports ext_clk_50m]
set_property PACKAGE_PIN E10 [get_ports swclk]
# set_property PACKAGE_PIN H11 [get_ports {GPIO_OUT_A_tri_o[7]}]
# set_property PACKAGE_PIN F14 [get_ports {GPIO_OUT_A_tri_o[6]}]
# set_property PACKAGE_PIN G14 [get_ports {GPIO_OUT_A_tri_o[5]}]
# set_property PACKAGE_PIN F13 [get_ports {GPIO_OUT_A_tri_o[4]}]
# set_property PACKAGE_PIN G12 [get_ports {GPIO_OUT_A_tri_o[3]}]
# set_property PACKAGE_PIN F12 [get_ports {GPIO_OUT_A_tri_o[2]}]
# set_property PACKAGE_PIN G11 [get_ports {GPIO_OUT_A_tri_o[1]}]
# set_property PACKAGE_PIN F10 [get_ports {GPIO_OUT_A_tri_o[0]}]
set_property PACKAGE_PIN E25 [get_ports {GPIO_OUT_A_tri_o[7]}]
set_property PACKAGE_PIN D25 [get_ports {GPIO_OUT_A_tri_o[6]}]
set_property PACKAGE_PIN D24 [get_ports {GPIO_OUT_A_tri_o[5]}]
set_property PACKAGE_PIN C26 [get_ports {GPIO_OUT_A_tri_o[4]}]
set_property PACKAGE_PIN C24 [get_ports {GPIO_OUT_A_tri_o[3]}]
set_property PACKAGE_PIN D23 [get_ports {GPIO_OUT_A_tri_o[2]}]
set_property PACKAGE_PIN A24 [get_ports {GPIO_OUT_A_tri_o[1]}]
set_property PACKAGE_PIN A23 [get_ports {GPIO_OUT_A_tri_o[0]}]
set_property PACKAGE_PIN H26 [get_ports reset_in]
set_property PACKAGE_PIN H14 [get_ports rx_0]
set_property PACKAGE_PIN H12 [get_ports tx_0]
set_property PACKAGE_PIN B11 [get_ports swd_io]
# set_property PACKAGE_PIN A23 [get_ports core_led_0]






create_debug_core u_ila_0 ila
set_property ALL_PROBE_SAME_MU true [get_debug_cores u_ila_0]
set_property ALL_PROBE_SAME_MU_CNT 1 [get_debug_cores u_ila_0]
set_property C_ADV_TRIGGER false [get_debug_cores u_ila_0]
set_property C_DATA_DEPTH 131072 [get_debug_cores u_ila_0]
set_property C_EN_STRG_QUAL false [get_debug_cores u_ila_0]
set_property C_INPUT_PIPE_STAGES 0 [get_debug_cores u_ila_0]
set_property C_TRIGIN_EN false [get_debug_cores u_ila_0]
set_property C_TRIGOUT_EN false [get_debug_cores u_ila_0]
set_property port_width 1 [get_debug_ports u_ila_0/clk]
connect_debug_port u_ila_0/clk [get_nets [list design_main_i/sys_mmcm/inst/sys_clk]]
set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe0]
set_property port_width 1 [get_debug_ports u_ila_0/probe0]
connect_debug_port u_ila_0/probe0 [get_nets [list {design_main_i/xlconcat_0_dout[0]}]]
create_debug_port u_ila_0 probe
set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe1]
set_property port_width 1 [get_debug_ports u_ila_0/probe1]
connect_debug_port u_ila_0/probe1 [get_nets [list design_main_i/axi_uartlite_0_tx]]
create_debug_port u_ila_0 probe
set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe2]
set_property port_width 1 [get_debug_ports u_ila_0/probe2]
connect_debug_port u_ila_0/probe2 [get_nets [list design_main_i/rx_0_1]]
set_property C_CLK_INPUT_FREQ_HZ 300000000 [get_debug_cores dbg_hub]
set_property C_ENABLE_CLK_DIVIDER false [get_debug_cores dbg_hub]
set_property C_USER_SCAN_CHAIN 1 [get_debug_cores dbg_hub]
connect_debug_port dbg_hub/clk [get_nets u_ila_0_sys_clk]
