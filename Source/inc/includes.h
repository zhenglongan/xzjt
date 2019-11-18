#ifndef INCLUDES_H
#define INCLUDES_H


#define  DEF_NULL                                 ((void *)0)
/* ------------------------------- BOOLEAN DEFINES -------------------------- */
#define  DEF_FALSE                                         0u
#define  DEF_TRUE                                          1u

#define  DEF_NO                                            0u
#define  DEF_YES                                           1u

#define  DEF_DISABLED                                      0u
#define  DEF_ENABLED                                       1u

#define  DEF_INACTIVE                                      0u
#define  DEF_ACTIVE                                        1u

#define  DEF_INVALID                                       0u
#define  DEF_VALID                                         1u

#define  DEF_OFF                                           0u
#define  DEF_ON                                            1u

#define  DEF_CLR                                           0u
#define  DEF_SET                                           1u

#define  DEF_FAIL                                          0u
#define  DEF_OK                                            1u

#define  DEF_LOW                                           0u
#define  DEF_HIG                                           1u

#define  DEF_OUT                                           0u
#define  DEF_IN                                            1u

/* Define --------------------------------------------------------------------*/
//绝对值函数宏定义
#define	fabsm(z)							((z >= 0) ? (z) : -(z))	
//范围限制函数定义
#define	ValueLimitMin(val,min)				((val < min) ? (min) : (val))
#define	ValueLimitMax(val,max)				((val > max) ? (max) : (val))
#define	ValueLimitMaxMin(val,max,min)		((val>max)?(max):((val<min)?(min):(val)))

/* Includes ------------------------------------------------------------------*/
#include "..\inc\sfr62p.h"         // M16C/62P special function register definitions
#include "..\inc\typedef.h"        // Data type define
#include "..\inc\common.h"         // Common constants definition
#include "..\inc\variables.h"      // External variables declaration
#include "..\inc\initial.h"        // External variables declaration
#include "..\inc\eeprom.h" 

#include "..\inc\rfid.h" 
#include "..\inc\uart1.h"
#include "..\inc\laser.h" 
#include "..\inc\motor.h"          // Motor function
#include "..\inc\delay.h"          // delay time definition
#include "..\inc\watch.h"          // System watch function


#include "..\inc\action.h"         // action function
#include "..\inc\system.h"         // External variables declaration
#include "..\inc\barcode.h"
#include "..\inc\solenoid.h"       // solenoid driver definition
#include "..\inc\step_motor.h"     // stepper motor function
#include "..\inc\communication.h"  // Communication function

#include "..\inc\function.h"
#include "..\inc\hardware.h"

#include "..\inc\motor_servor.h"
#include "..\inc\motor_rotate.h"
#include "..\inc\motor_xyaxsi.h"
#include "..\inc\motor_yjaxsi.h"
#include "..\inc\motor_zxaxsi.h"
/*----------------------------------------------------------------------------*/


#endif