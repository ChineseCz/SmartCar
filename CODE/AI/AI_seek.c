/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 *
 * @file            AI_Seek
 * @function        AIÑ­¼£µ÷ÓÃº¯Êý
 * @author          Cz
 * @date            2021-4-23
 *
 ********************************************************************************************************************/

#include "headfile.h"

void AI_angle_limit()
{
//    if (steer.angle<0)
//    {
//         steer.duty+=steer.rate_pid*(SERVO_MIDDLE-rate.ste*rate.ste_lef*steer.angle);
//    }
//    else
//    {
//         steer.duty+=steer.rate_pid*(SERVO_MIDDLE-rate.ste*rate.ste_rig*steer.angle);
//    }


     if(steer.duty>=SERVO_MIDDLE+SERVO_DIFF)  steer.duty=SERVO_MIDDLE+SERVO_DIFF;
     if(steer.duty<=SERVO_MIDDLE-SERVO_DIFF)  steer.duty=SERVO_MIDDLE-SERVO_DIFF;

}


void ai_steer_trace()
{
    steer.duty_last=steer.duty;
    track_judge( );
    if (flag.track==3)
        steer.duty=500;
    else if (flag.track!=5)
        Run_Model_Linear();
    else
        steer.duty=steer.duty_last;
    AI_angle_limit();
}
