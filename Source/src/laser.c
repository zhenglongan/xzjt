//--------------------------------------------------------------------------------------
// 	Includes
//--------------------------------------------------------------------------------------
#include "..\inc\includes.h" 	// all files includes

//--------------------------------------------------------------------------------------
void laser_time_enable(UINT16 temp)
{
	tb5s = 0;					// stop timer B5
	tb5mr = 0x00;
	tb5 = temp;					//(SYS_FREQ/10000 - 1);// Set up Timer B4 Reload Register for 100 us interval interrupt
	tb5ic = TB5_IPL;		  	// set timer B5 interrupt priority
	tb5s = 1;					// start timer B5 
}
//--------------------------------------------------------------------------------------
void laser_time_disable(void)
{
	tb5s = 0;						// stop timer B5 
}
//--------------------------------------------------------------------------------------
