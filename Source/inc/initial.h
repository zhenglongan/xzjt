#ifndef INITIAL_H
#define INITIAL_H
//--------------------------------------------------------------------------------------
void init_system(void);


void restore_para_from_eeprom(void);

void copy_data_to_struct(UINT8* pData,
						UINT16* pAnglePositive,
						UINT8* pTimePositive,
						UINT16* pAngleNegative,
						UINT8* pTimeNegative);
void copy_struct_to_data(UINT8* pData,
						UINT16* pAnglePositive,
						UINT8* pTimePositive,
						UINT16* pAngleNegative,
						UINT8* pTimeNegative);
//--------------------------------------------------------------------------------------
#endif

