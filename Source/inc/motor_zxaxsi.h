#ifndef	MOTOR_ZXAXSI_H
#define	MOTOR_ZXAXSI_H


//#define	DEBUG_GO_ORIGIN_ZX		//������ʱ�������ر�ZX��ԭ�㹦��
//#define	DEBUG_MOVE_ZX_AXSI		//������ʱ�������ر�ZX�ƶ�����



UINT8 get_motor_zx_org_statu(void);

void movestep_zx(INT16 steps,UINT16 time);
void quickmove_zx(UINT16 time,INT32 steps);
void go_origin_zx(void);













#endif