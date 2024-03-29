#ifndef EEPROM_H
#define EEPROM_H
//--------------------------------------------------------------------------------------

#include "typedef.h"      //Data type define

#define ACK		0
#define NOACK	1

#define WRITE_MODE	0
#define READ_MODE	1




typedef struct {
	UINT8 iic_DeviceAddress;
	UINT8 iic_MemoryAddress_h;
	UINT8 iic_MemoryAddress_l;
	UINT8 *iic_Data;
	UINT8 iic_NumberOfByte;
}IicPack;

void initIicBus(void);

UINT8 IicBusRead(IicPack *);
UINT8 IicBusWrite(IicPack *);

void StartCondition(void);
void StopCondition(void);

UINT8 ByteWrite(UINT8);
void ByteRead(UINT8 *, UINT8);

void init_eeprom(void);

extern UINT16 read_par(UINT16 par_num);
extern void write_par(UINT16 par_num,INT16 par);

extern void read_para_group(UINT16 add,UINT8 *point,UINT16 len);
extern void write_para_group(UINT16 add,UINT8 *point,UINT16 len);

extern UINT8 read_eeprom(UINT16 address,UINT8 *point,UINT16 len);
extern UINT8 prog_eeprom(UINT16 address,UINT8 *point,UINT16 len);

//--------------------------------------------------------------------------------------
#endif
