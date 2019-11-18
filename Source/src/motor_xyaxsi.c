//--------------------------------------------------------------------------------------
// 	Includes
//--------------------------------------------------------------------------------------
#include "..\inc\includes.h" 	// all files includes

//--------------------------------------------------------------------------------------
//	XY轴电机 功能函数
//--------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------
// 获取X轴原点状态
//--------------------------------------------------------------------------------------
UINT8 get_motor_x_org_statu(void)
{
  return app_GpioXGetVal(XORG);
}
//--------------------------------------------------------------------------------------
// 获取Y轴原点状态
//--------------------------------------------------------------------------------------
UINT8 get_motor_y_org_statu(void)
{
  return app_GpioXGetVal(YORG);
}
//--------------------------------------------------------------------------------------
//  Name:	     movestep_x
//  Parameters:	 None
//  Returns:	 None
//  Description: move x step motor ,movestepx_time
//--------------------------------------------------------------------------------------
#ifndef	DEBUG_MOVE_X_AXSI
void movestep_x(INT16 steps,UINT16 time)
{ 
  UINT16 command;
  //出错或0数据不发给驱动
  if((sys.status == ERROR) || (steps == 0))
    return;
  //协议时间做限定
  if(time > fabsm(steps)*20) time = fabsm(steps)*20;
  if(time > 63) time = 63;
  
  if(steps>0)
  {
    if(x_motor_dir == 0)		
      command = (UINT16)0x0000+((UINT16)steps<<6)+(UINT16)time;
    else
      command = (UINT16)0x4000+((UINT16)steps<<6)+(UINT16)time;
  }	
  else 
  {
    steps = -steps;		
    if(x_motor_dir == 0)	
      command = (UINT16)0x4000+((UINT16)steps<<6)+(UINT16)time;		
    else
      command = (UINT16)0x0000+((UINT16)steps<<6)+(UINT16)time;	
  }
  if(command == 0x5555) command++;
  command_direct_to_dspn(DSP_NUM_1,command);
}
//--------------------------------------------------------------------------------------
void quickmove_x(UINT16 time,INT32 steps)
{
  UINT16 low16,hig16;
  UINT32 tmp32;
  send_dspn_command(DSP_NUM_1,0x0000);
  delay_us(500);
  
  if(steps > 0)
  {
    tmp32 = steps;
    low16  = tmp32 & 0xffff;
    if(x_motor_dir == 0)	
      hig16 = (UINT16)0x0000 + ((tmp32>>16)&0xff);
    else
      hig16 = (UINT16)0x4000 + ((tmp32>>16)&0xff);
  }
  else
  {
    tmp32 = - steps;
    low16  = tmp32 & 0xffff;		
    if(x_motor_dir == 0)		
      hig16 = (UINT16)0x4000 + ((tmp32>>16)&0xff);
    else
      hig16 = (UINT16)0x0000 + ((tmp32>>16)&0xff);
  }
  
  if(fabsm(steps)<(time>>3))
  {
    hig16 |= (1<<13);//强制使用闭环横幅值
  }
  
  send_dspn_command(DSP_NUM_1,hig16);	
  //delay_ms(1);
  
  if(low16 == 0x5555) low16++;
  
  send_dspn_command(DSP_NUM_1,low16);
  //delay_ms(1);
  
  if(time == 0x5555) time++;
  
  send_dspn_command(DSP_NUM_1,time);
  //delay_ms(1);
}
#else
void movestep_x(INT16 steps,UINT16 time)
{
  
}
void quickmove_x(UINT16 time,INT32 steps)
{
  
}
#endif
//--------------------------------------------------------------------------------------
//  Name:	     movestep_y
//  Parameters:	 None
//  Returns:	 None
//  Description: move y step motor ,movestepy_time
//--------------------------------------------------------------------------------------
#ifndef	DEBUG_MOVE_Y_AXSI
void movestep_y(INT16 steps,UINT16 time)
{ 
  UINT16 command;
  //出错或0数据不发给驱动
  if((sys.status == ERROR) || (steps == 0))
    return;
  //协议时间做限定
  if(time > fabsm(steps)*20) time = fabsm(steps)*20;
  if(time > 63) time = 63;
  
  if(steps>0)
  {
    if(y_motor_dir == 0)		
      command =(UINT16)0x8000+((UINT16)steps<<6)+(UINT16)time;
    else
      command =(UINT16)0xC000+((UINT16)steps<<6)+(UINT16)time;
  }	
  else 
  {
    steps = -steps;
    
    if(y_motor_dir == 0)	
      command =(UINT16)0xC000+((UINT16)steps<<6)+(UINT16)time;	
    else			 
      command =(UINT16)0x8000+((UINT16)steps<<6)+(UINT16)time;
  }
  
  if(command == 0x5555) command++;
  command_direct_to_dspn(DSP_NUM_1,command);
}
//--------------------------------------------------------------------------------------
void quickmove_y(UINT16 time,INT32 steps)
{
  UINT16 low16,hig16;
  UINT32 tmp32;
  send_dspn_command(DSP_NUM_1,0x0000);	
  delay_us(500);
  
  if(steps > 0)
  {
    tmp32 = steps;
    low16  = tmp32 & 0xffff;
    if(y_motor_dir == 0)
      hig16 = (UINT16)0x8000 + ((tmp32>>16)&0xff);
    else
      hig16 = (UINT16)0xc000 + ((tmp32>>16)&0xff);
  }
  else
  {
    tmp32 = - steps;
    low16  = tmp32 & 0xffff;		
    if(y_motor_dir == 0)
      hig16 = (UINT16)0xc000 + ((tmp32>>16)&0xff);
    else
      hig16 = (UINT16)0x8000 + ((tmp32>>16)&0xff);
  }
  
  if(fabsm(steps)<(time>>3))
  {
    hig16 |= (1<<13);//强制使用闭环横幅值
  }
  send_dspn_command(DSP_NUM_1,hig16);	
  //delay_ms(1);
  if(low16 == 0x5555)	low16++;
  
  send_dspn_command(DSP_NUM_1,low16);	
  //delay_ms(1);
  if(time == 0x5555)	time++;
  
  send_dspn_command(DSP_NUM_1,time);
  //delay_ms(1);
}
#else
void movestep_y(INT16 steps,UINT16 time)
{
  
}
void quickmove_y(UINT16 time,INT32 steps)
{
  
}
#endif
//--------------------------------------------------------------------------------------
//  Name:		go_origin_x
//  Parameters:	None
//  Returns:	None
//  Description: x motor go origin
//--------------------------------------------------------------------------------------
#ifndef	DEBUG_GO_ORIGIN_X
void go_origin_x(void)
{
  UINT8 i;
  UINT16 temp16;
  UINT16 speed_time,run_time;
  UINT16 j=1;
  
  if(para.x_origin_mode == AUTO_FIND_START_POINT)
  {
    delay_ms(1);
    allx_step = 0;
    return;
  }
  pause_flag = 0;
  //speed_time = 292;//(300- (UINT16)(50/(11-go_origin_speed)));
  speed_time = (300- (UINT16)(50/(11 - go_origin_speed)));
  
  if(get_motor_x_org_statu() == para.x_sensor_open_level)		//not working
  {
    temp16 = 0;
    run_time = 12000;
    j = 1;
    while(get_motor_x_org_statu() == para.x_sensor_open_level)
    {
      if(j < 40)
        movestepx_time = OPEN_LOOP_TIME;
      else
        movestepx_time = CLOSE_LOOP_TIME;
      
      if(x_sensor_pos == X_SENSOR_AT_LEFT)
        movestep_x( 1,movestepx_time);
      else
        movestep_x(-1,movestepx_time);
      
      if(run_time < 400)
        run_time = 400;
      
      delay_us(run_time);
      if(j<= 40)
      {
        run_time -= speed_time;
        j ++ ;
      }
      temp16 = temp16 + 1;
      if(temp16 > 30000)
      {
        sys.status = ERROR;
        StatusChangeLatch = ERROR;
        if(sys.error == ERROR_OK)
          sys.error = ERROR_25;
        return;
      }
      if(app_GpioXGetVal(PAUSE) == PAUSE_ON)
      {
        delay_ms(10);
        if(app_GpioXGetVal(PAUSE) == PAUSE_ON)
        {
          pause_flag = 1;
          return;
        }
      }
      if(sys.status == ERROR)
      {
        sys.status = ERROR;
        StatusChangeLatch = ERROR;
        return;
      }
      rec_com();
    }
    
    if(j >= 40)
    {
      movestepx_time = CLOSE_LOOP_TIME;
    }
    else
    {
      movestepx_time = OPEN_LOOP_TIME;
    }
    
    for(i=5; i>0; i--)
    {
      if(x_sensor_pos == X_SENSOR_AT_LEFT)
        movestep_x( 1,movestepx_time);
      else
        movestep_x(-1,movestepx_time);
      run_time += (speed_time*8-1600);
      delay_us(run_time);
    }
    
    delay_ms(20);
    while(get_motor_x_org_statu() != para.x_sensor_open_level)
    {
      movestepx_time = OPEN_LOOP_TIME;
      if(x_sensor_pos == X_SENSOR_AT_LEFT)//退回去
        movestep_x(-1,movestepx_time);
      else
        movestep_x( 1,movestepx_time);
      delay_ms(12);
      if(sys.status == ERROR)
      {
        sys.status = ERROR;
        StatusChangeLatch = ERROR;
        return;
      }
    }
    
    for(i=0; i<5; i++)
    {
      movestepx_time = OPEN_LOOP_TIME;
      if(x_sensor_pos == X_SENSOR_AT_LEFT)
        movestep_x(-1,movestepx_time);
      else
        movestep_x( 1,movestepx_time);
      delay_ms(12);
    }
  }
  else //already in cover position
  {
    temp16 = 0;
    j = 1;
    run_time = 12000;
    while(get_motor_x_org_statu() != para.x_sensor_open_level)
    {
      if(j < 40)
      {
        movestepx_time = OPEN_LOOP_TIME;
      }
      else
      {
        movestepx_time = CLOSE_LOOP_TIME;
      }
      if(x_sensor_pos == X_SENSOR_AT_LEFT)
        movestep_x(-1,movestepx_time);
      else
        movestep_x( 1,movestepx_time);
      
      if(run_time < 400)
        run_time = 400;
      
      delay_us(run_time);
      if(j<= 40)
      {
        run_time -= speed_time;
        j ++ ;
      }
      temp16 = temp16 + 1;
      if(temp16 > 30000)
      {
        sys.status = ERROR;
        StatusChangeLatch = ERROR;
        if(sys.error == ERROR_OK)
          sys.error = ERROR_25;
        return;
      }
      if(app_GpioXGetVal(PAUSE) == PAUSE_ON)
      {
        delay_ms(10);
        if(app_GpioXGetVal(PAUSE) == PAUSE_ON)
        {
          pause_flag = 1;
          return;
        }
      }
      if(sys.status == ERROR)
      {
        sys.status = ERROR;
        StatusChangeLatch = ERROR;
        return;
      }
      rec_com();
    }
    if(j>=40)
    {
      movestepx_time = CLOSE_LOOP_TIME;
    }
    else
    {
      movestepx_time = OPEN_LOOP_TIME;
    }
    for(i=5; i>0; i--)
    {
      if(x_sensor_pos == X_SENSOR_AT_LEFT)
        movestep_x(-1,movestepx_time);
      else
        movestep_x( 1,movestepx_time);
      run_time += (speed_time*8-1600);
      delay_us(run_time);
    }
    delay_ms(20);
  }
  
  delay_ms(12);
  temp16 = 0;
  for(i=0; i<3; i++)
  {
    while(get_motor_x_org_statu() == para.x_sensor_open_level)
    {
      movestepx_time = OPEN_LOOP_TIME;
      if(x_sensor_pos == X_SENSOR_AT_LEFT)
        movestep_x( 1,movestepx_time);
      else
        movestep_x(-1,movestepx_time);
      
      delay_ms(12);
      temp16 = temp16 + 1;
      if(temp16 > 30000)
      {
        sys.status = ERROR;
        StatusChangeLatch = ERROR;
        if(sys.error == ERROR_OK)
          sys.error = ERROR_25;
        return;
      }
      if(app_GpioXGetVal(PAUSE) == PAUSE_ON)
      {
        delay_ms(10);
        if(app_GpioXGetVal(PAUSE) == PAUSE_ON)
        {
          pause_flag = 1;
          return;
        }
      }
      if(sys.status == ERROR)
      {
        sys.status = ERROR;
        StatusChangeLatch = ERROR;
        return;
      }
      rec_com();
    }
    delay_ms(20);
  }
  
  delay_ms(1);
  allx_step = 0;
  if(x_origin_offset != 0)
    go_commandpoint(x_origin_offset,ally_step);
  allx_step = 0;
}
#else
void go_origin_x(void)
{
  allx_step = 0;
}
#endif
//--------------------------------------------------------------------------------------
//  Name:		go_origin_y
//  Parameters:	None
//  Returns:	None
//  Description: y motor go origin
//--------------------------------------------------------------------------------------
#ifndef	DEBUG_GO_ORIGIN_Y
void go_origin_y(void)
{
  UINT8 i;
  UINT16 temp16;
  UINT16 speed_time,run_time;
  UINT16 j=1;
  
  //speed_time = 292;//(300- (UINT16)(50/(11-go_origin_speed)));
  speed_time = (300- (UINT16)(50/(11-go_origin_speed)));
  j = 1;
  pause_flag = 0;
  if(get_motor_y_org_statu() == para.y_sensor_open_level)
  {
    temp16 = 0;
    j = 1;
    run_time = 12000;
    while(get_motor_y_org_statu() == para.y_sensor_open_level)
    {
      if(j<40)
      {
        movestepy_time = OPEN_LOOP_TIME;
      }
      else
      {
        movestepy_time = CLOSE_LOOP_TIME;
      }
      movestep_y(-1,movestepy_time);
      
      if(run_time <850)
        run_time = 850;
      
      delay_us(run_time);
      if(j<= 40)
      {
        run_time -= speed_time;
        j++;
      }
      temp16 = temp16 + 1;
      if(temp16 > 18000)
      {
        sys.status = ERROR;
        StatusChangeLatch = ERROR;
        if(sys.error == ERROR_OK)
          sys.error = ERROR_26;     	// Y origin sensor is not normal
        return;
      }
      if(app_GpioXGetVal(PAUSE) == PAUSE_ON)
      {
        delay_ms(10);
        if(app_GpioXGetVal(PAUSE) == PAUSE_ON)
        {
          pause_flag = 1;
          return;
        }
      }
      if(sys.status == ERROR)
      {
        sys.status = ERROR;
        StatusChangeLatch = ERROR;
        return;
      }
      rec_com();
    }
    
    if(j>=40)
    {
      movestepy_time = CLOSE_LOOP_TIME;
      
    }
    else
    {
      movestepy_time = OPEN_LOOP_TIME;
      
    }
    
    for(i=5; i>0; i--)
    {
      movestep_y(-1,movestepy_time);
      run_time += (speed_time*8-1600);
      delay_us(run_time);
    }
    delay_ms(20);
    while(get_motor_y_org_statu() != para.y_sensor_open_level)
    {
      movestepy_time = OPEN_LOOP_TIME;
      
      movestep_y(1,movestepy_time);
      delay_ms(12);
      if(sys.status == ERROR)
      {
        sys.status = ERROR;
        StatusChangeLatch = ERROR;
        return;
      }
    }
    
    for(i=0; i<5; i++)
    {
      movestepy_time = OPEN_LOOP_TIME;
      
      movestep_y(1,movestepy_time);
      delay_ms(12);
    }
  }
  else            						// sensor is not covered
  {
    temp16 = 0;
    j = 1;
    run_time = 12000;
    while(get_motor_y_org_statu() != para.y_sensor_open_level)
    {
      if(j<40)
      {
        movestepy_time = OPEN_LOOP_TIME;
        
      }
      else
      {
        movestepy_time = CLOSE_LOOP_TIME;
        
      }
      movestep_y(1,movestepy_time);
      
      if(run_time < 850)
        run_time = 850;
      
      delay_us(run_time);
      if(j<= 40)
      {
        run_time -= speed_time;
        j++;
      }
      temp16 = temp16 + 1;
      if(temp16 > 18000)
      {
        sys.status = ERROR;
        StatusChangeLatch = ERROR;
        if(sys.error == ERROR_OK)
          sys.error = ERROR_26;     	// Y origin sensor is not normal
        return;
      }
      if(app_GpioXGetVal(PAUSE) == PAUSE_ON)
      {
        delay_ms(10);
        if(app_GpioXGetVal(PAUSE) == PAUSE_ON)
        {
          pause_flag = 1;
          return;
        }
      }
      if(sys.status == ERROR)
      {
        sys.status = ERROR;
        StatusChangeLatch = ERROR;
        return;
      }
      rec_com();
    }
    if(j>=40)
    {
      movestepy_time = CLOSE_LOOP_TIME;
      
    }
    else
    {
      movestepy_time = OPEN_LOOP_TIME;
      
    }
    for(i=5; i>0; i--)
    {
      movestep_y(1,movestepy_time);
      run_time += (speed_time*8-1600);
      delay_us(run_time);
    }
    
    delay_ms(20);
  }
  temp16 = 0;
  delay_ms(12);
  for(i=0; i<3; i++)
  {
    while(get_motor_y_org_statu() == para.y_sensor_open_level)
    {
      movestepy_time = OPEN_LOOP_TIME;
      
      movestep_y(-1,movestepy_time);
      delay_ms(12);
      
      temp16 = temp16 + 1;
      if(temp16 > 8000)
      {
        sys.status = ERROR;
        StatusChangeLatch = ERROR;
        if(sys.error == ERROR_OK)
          sys.error = ERROR_26;
        return;
      }
      if(app_GpioXGetVal(PAUSE) == PAUSE_ON)
      {
        delay_ms(10);
        if(app_GpioXGetVal(PAUSE) == PAUSE_ON)
        {
          pause_flag = 1;
          return;
        }
      }
      if(sys.status == ERROR)
      {
        sys.status = ERROR;
        StatusChangeLatch = ERROR;
        return;
      }
      rec_com();
    }
    delay_ms(20);
  }
  delay_ms(1);
  ally_step = 0;
  if(y_origin_offset !=0)
    go_commandpoint(allx_step,y_origin_offset);
  ally_step = 0;
}
#else
void go_origin_y(void)
{
  ally_step = 0;
}
#endif
//--------------------------------------------------------------------------------------
//  Name:		go_origin_xy_both
//  Parameters:	None
//  Returns:	None
//  Description: xy motor go origin
//--------------------------------------------------------------------------------------
#ifndef	DEBUG_GO_ORIGIN_SYNC_XY
void go_origin_xy_both(void)
{
  UINT8 i,movingx_flag,movingy_flag,movex_flag,movey_flag;
  UINT16 temp16;
  UINT16 speed_time,run_time;
  UINT8 y_cnt,x_cnt,x_over_cnt,y_over_cnt;
  
  //speed_time = 292;//(300- (UINT16)(50/(11-go_origin_speed)));
  speed_time = (300- (UINT16)(50/(11-go_origin_speed)));
  y_cnt = 1;
  x_cnt = 1;
  run_time = 12000;
  x_over_cnt = 0;
  y_over_cnt = 0;
  pause_flag = 0;
  movingx_flag = 0;
  movingy_flag = 0;
  movex_flag = 0;
  movex_flag = 0;
  //step 1
  for(temp16 = 0; temp16 <25000; temp16++)
  {
    if(movingy_flag == 0)
    {
      if(get_motor_y_org_statu() != para.y_sensor_open_level)
      {
        if(y_cnt < 40)
        {
          movestepy_time = OPEN_LOOP_TIME;
        }
        else
        {
          movestepy_time = CLOSE_LOOP_TIME;
        }
        movestep_y( 1,movestepy_time);
        delay_us(400);
        if(y_cnt < 40)
          y_cnt++;
        if((get_motor_y_org_statu() == para.y_sensor_open_level)||((get_motor_y_org_statu() != para.y_sensor_open_level)&&(movey_flag ==2)))
          movingy_flag = 2;
        movey_flag = 1;
        
      }
      else if(get_motor_y_org_statu() == para.y_sensor_open_level)
      {
        if(y_cnt < 40)
        {
          movestepy_time = OPEN_LOOP_TIME;
        }
        else
        {
          movestepy_time = CLOSE_LOOP_TIME;
        }
        movestep_y(-1,movestepy_time);
        delay_us(400);
        if(y_cnt < 40)
          y_cnt++;
        if((get_motor_y_org_statu() != para.y_sensor_open_level)||((get_motor_y_org_statu() == para.y_sensor_open_level)&&(movey_flag ==1)))
          movingy_flag =3;
        movey_flag = 2;
      }
    }
    else if(y_over_cnt<5)
    {
      y_over_cnt++;
      movestep_y( 1,movestepy_time);
      delay_us(400);
    }
    else
    {
      movingy_flag =1;
    }
    
    if(movingx_flag == 0)
    {
      if(get_motor_x_org_statu() != para.x_sensor_open_level)
      {
        if(x_cnt < 40)
        {
          movestepx_time = OPEN_LOOP_TIME;
        }
        else
        {
          movestepx_time = CLOSE_LOOP_TIME;
        }
        if(x_sensor_pos == X_SENSOR_AT_LEFT)
          movestep_x(-1,movestepx_time);
        else
          movestep_x( 1,movestepx_time);
        if(x_cnt < 40)
          x_cnt++;
        
        if((get_motor_x_org_statu() == para.x_sensor_open_level)||((get_motor_x_org_statu() != para.x_sensor_open_level)&&(movex_flag ==2)))
          movingx_flag =2;
        movex_flag = 1;
      }
      else if(get_motor_x_org_statu() == para.x_sensor_open_level)
      {
        if(x_cnt < 40)
        {
          movestepx_time = OPEN_LOOP_TIME;
        }
        else
        {
          movestepx_time = CLOSE_LOOP_TIME;
        }
        if(x_sensor_pos == X_SENSOR_AT_LEFT)
          movestep_x( 1,movestepx_time);
        else
          movestep_x(-1,movestepx_time);
        if(x_cnt < 40)
          x_cnt++;
        if((get_motor_x_org_statu() != para.x_sensor_open_level)||((get_motor_x_org_statu() == para.x_sensor_open_level)&&(movex_flag ==1)))
          movingx_flag = 3;
        movex_flag = 2;
      }
    }
    else if(x_over_cnt<5)
    {
      x_over_cnt++;
      if(x_sensor_pos == X_SENSOR_AT_LEFT)
        movestep_x(-1,movestepx_time);
      else
        movestep_x( 1,movestepx_time);
    }
    else
    {
      movingx_flag =1;
    }
    
    if(temp16 <= 40)
      run_time -= speed_time;
    if(run_time < 400)
      run_time = 400;
    delay_us(run_time);
    if(app_GpioXGetVal(PAUSE) == PAUSE_ON)
    {
      delay_ms(10);
      if(app_GpioXGetVal(PAUSE) == PAUSE_ON)
      {
        pause_flag = 1;
        return;
      }
    }
    rec_com();
    if(sys.status == ERROR)
    {
      sys.status = ERROR;
      StatusChangeLatch = ERROR;
      return;
    }
    if((movingx_flag == 1)&&(movingy_flag == 1))
      break;
  }
  
  //--------------------------------------------------------------------------------------
  temp16 = 0;
  delay_ms(12);
  
  for(i=0; i<3; i++)
  {
    while(get_motor_y_org_statu() == para.y_sensor_open_level)
    {
      movestepy_time = CLOSE_LOOP_TIME;
      
      movestep_y(-1,movestepy_time);
      delay_ms(5);
      
      temp16 = temp16 + 1;
      if(temp16 > 8000)
      {
        sys.status = ERROR;
        StatusChangeLatch = ERROR;
        if(sys.error == ERROR_OK)
          sys.error = ERROR_26;
        return;
      }
      rec_com();
      if(sys.status == ERROR)
      {
        sys.status = ERROR;
        StatusChangeLatch = ERROR;
        return;
      }
    }
    delay_ms(20);
  }
  delay_ms(12);
  ally_step = 0;
  //--------------------------------------------------------------------------------------
  //         xorg=0    xorg =1
  //left       1       -1
  //right     -1        1
  //--------------------------------------------------------------------------------------
  if(para.x_origin_mode == AUTO_FIND_START_POINT)
  {
    delay_ms(1);
    allx_step = 0;
    return;
  }
  i = 0;
  while((get_motor_x_org_statu() != para.x_sensor_open_level)||(i<5))
  {
    movestepx_time = CLOSE_LOOP_TIME;
    
    if(x_sensor_pos == X_SENSOR_AT_LEFT)
      movestep_x(-1,movestepx_time);
    else
      movestep_x( 1,movestepx_time);
    delay_ms(2);
    i++;
    if(sys.status == ERROR)
    {
      sys.status = ERROR;
      StatusChangeLatch = ERROR;
      return;
    }
  }
  temp16 = 0;
  delay_ms(5);
  for(i=0; i<3; i++)
  {
    while(get_motor_x_org_statu() == para.x_sensor_open_level)
    {
      movestepx_time = CLOSE_LOOP_TIME;
      
      if(x_sensor_pos == X_SENSOR_AT_LEFT)
        movestep_x( 1,movestepx_time);
      else
        movestep_x(-1,movestepx_time);
      delay_ms(5);
      temp16 = temp16 + 1;
      if(temp16 > 20000)
      {
        sys.status = ERROR;
        StatusChangeLatch = ERROR;
        if(sys.error == ERROR_OK)
          sys.error = ERROR_25;
        return;
      }
      if(sys.status == ERROR)
      {
        sys.status = ERROR;
        StatusChangeLatch = ERROR;
        return;
      }
      
    }
    delay_ms(20);
  }
  allx_step = 0;
  ally_step = 0;
  if((x_origin_offset != 0)||(y_origin_offset != 0))
    go_commandpoint(x_origin_offset,y_origin_offset);
  allx_step = 0;
  ally_step = 0;
  
}
#else
void go_origin_xy_both(void)
{
  allx_step = 0;
  ally_step = 0;
}
#endif
//--------------------------------------------------------------------------------------
//检测X轴动作是否完成 12xx = 完成
//--------------------------------------------------------------------------------------
UINT8 check_x_action_done(void)
{
  send_dspn_command(DSP_NUM_1,0x0012);
  send_dspn_command(DSP_NUM_1,0x5555);
  
  if((rec_x.word&0xff00) == 0x1200)
    return DEF_TRUE;
  else
    return DEF_FALSE;
}
//--------------------------------------------------------------------------------------
//检测Y轴动作是否完成 xx34 = 完成
//--------------------------------------------------------------------------------------
UINT8 check_y_action_done(void)
{
  send_dspn_command(DSP_NUM_1,0x0012);
  send_dspn_command(DSP_NUM_1,0x5555);
  
  if((rec_x.word&0x00ff) == 0x0034)
    return DEF_TRUE;
  else
    return DEF_FALSE;
}
//--------------------------------------------------------------------------------------
//检测XY动作是否完成 0x1234 = 完成
//--------------------------------------------------------------------------------------
UINT8 check_xy_action_done(void)
{
#if 0
  if((check_x_action_done() != DEF_TRUE)||(check_y_action_done() != DEF_TRUE))
  {
    return DEF_FALSE;
  }
  else
  {
    return DEF_TRUE;
  }
#else
  send_dspn_command(DSP_NUM_1,0x0012);
  send_dspn_command(DSP_NUM_1,0x5555);
  
  if(rec_x.word == 0x1234)
    return DEF_TRUE;
  else
    return DEF_FALSE;
#endif	
}
//--------------------------------------------------------------------------------------
//X轴 空送过程中急停指令下下发
//--------------------------------------------------------------------------------------
void nop_move_emergency_x(UINT16 x)
{
  //步数小于QUICKMOVE_JUDGEMENT不响应急停指令
  if(x > QUICKMOVE_JUDGEMENT)
  {
    send_dspn_command(DSP_NUM_1,0x0005);
    delay_ms(2);
  }
}
//--------------------------------------------------------------------------------------
//Y轴 空送过程中急停指令下下发
//--------------------------------------------------------------------------------------
void nop_move_emergency_y(UINT16 y)
{
  //步数小于QUICKMOVE_JUDGEMENT不响应急停指令
  if(y > QUICKMOVE_JUDGEMENT)
  {
    send_dspn_command(DSP_NUM_1,0x0009);
    delay_ms(2);
  }
}
//--------------------------------------------------------------------------------------
//XY空送过程中急停指令下下发
//--------------------------------------------------------------------------------------
void nop_move_emergency(UINT16 x, UINT16 y)
{
  //X轴 空送过程中急停指令下下发
  nop_move_emergency_x(x);
  //Y轴 空送过程中急停指令下下发
  nop_move_emergency_y(y);
  
  //  if(x > QUICKMOVE_JUDGEMENT)//
  //  {
  //    send_dspn_command(DSP_NUM_1,0x0005);
  //    delay_ms(2);
  //  }
  //  
  //  if(y > QUICKMOVE_JUDGEMENT)//
  //  {
  //    send_dspn_command(DSP_NUM_1,0x0009);
  //    delay_ms(2);
  //  }
}
//--------------------------------------------------------------------------------------
//获取X轴急停后剩余未走完步数
//--------------------------------------------------------------------------------------
UINT16 get_x_distance(void)
{
  send_dspn_command(DSP_NUM_1,0x0007);
  send_dspn_command(DSP_NUM_1,0x5555); 	 
  return rec_x.word;
}
//--------------------------------------------------------------------------------------
//获取Y轴急停后剩余未走完步数
//--------------------------------------------------------------------------------------
UINT16 get_y_distance(void)
{
  send_dspn_command(DSP_NUM_1,0x0008);
  send_dspn_command(DSP_NUM_1,0x5555); 
  return rec_x.word;
}
//--------------------------------------------------------------------------------------

