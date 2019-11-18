//--------------------------------------------------------------------------------------
#ifndef SYSTEM_H
#define SYSTEM_H

//--------------------------------------------------------------------------------------
UINT16 identify_pattern(void);
void system_ticks_control(UINT8 cmd);
void single_move_func(void);
void shift_delay_process(void);
void shift_func(UINT8 shift_num);
void pattern_process(void);
void pre_running(void);
void process_nop_move_pause(UINT8 direction);
void trim_io_control(UINT8 action);
void trim_action(void);
void trim_pause(void);
//--------------------------------------------------------------------------------------
void ready_status(void);
void run_status(void);
void error_status(void);
void prewind_status(void);
void wind_status(void);
void poweroff_status(void);
void setout_status(void);
void preedit_status(void);
void finish_status(void);
void slack_status(void);
void checki03_status(void);
void checki04_status(void);
void checki05_status(void);
void checki06_status(void);
void checki07_status(void);
void checki08_status(void);
void checki10_status(void);
void checki11_status(void);
void checki12_status(void);
void checki13_status(void);
void multi_io_status(void);
void download_status(void);
void continue_status(void);
void download_drv_status(void);
//--------------------------------------------------------------------------------------




#endif
//--------------------------------------------------------------------------------------
