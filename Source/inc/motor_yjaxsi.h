#ifndef	MOTOR_YJAXSI_H
#define	MOTOR_YJAXSI_H


//#define	DEBUG_GO_ORIGIN_YJ		//������ʱ�������ر�YJ��ԭ�㹦��
//#define	DEBUG_MOVE_YJ_AXSI		//������ʱ�������ر�YJ�ƶ�����



extern UINT8 get_motor_yj_org_statu(void);
void movestep_yj(INT16 steps,UINT16 time);
void quickmove_yj(UINT16 time,INT32 steps);
void go_origin_yj(void);












#endif