//--------------------------------------------------------------------------------------
// 	Includes
//--------------------------------------------------------------------------------------
#include "..\inc\includes.h" 	// all files includes


//--------------------------------------------------------------------------------------
void app_SetDacVal(UINT8 ch,UINT8 val)
{
	switch(ch)
	{
		case DAC_CH_0:
		da0 = val;
		break;
		case DAC_CH_1:
		da1 = val;
		break;
		default:
		
		break;
	}
}
//--------------------------------------------------------------------------------------
UINT8 app_GetDacVal(UINT8 ch)
{
	UINT8 val;
	switch(ch)
	{
		case DAC_CH_0:
		val = da0;
		break;
		case DAC_CH_1:
		val = da1;
		break;
		default:
		val = 0;
		break;
	}
	return val;
}
//--------------------------------------------------------------------------------------
UINT16 app_GetAdcVal(UINT8 ch)
{
	UINT16 val;
	switch(ch)
	{
		case ADC_CH_0:
		val = ad0;
		break;
		case ADC_CH_1:
		val = ad1;
		break;
		case ADC_CH_2:
		val = ad2;
		break;
		case ADC_CH_3:
		val = ad3;
		break;
		case ADC_CH_4:
		val = ad4;
		break;
		case ADC_CH_5:
		val = ad5;
		break;
		case ADC_CH_6:
		val = ad6;
		break;
		case ADC_CH_7:
		val = ad7;
		break;
		default:
		val = 0;
		break;
	}
	return val;
}
//--------------------------------------------------------------------------------------
























