/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 *
 * @file            encoder
 * @function        ±àÂëÆ÷
 * @author          Cz
 * @date            2021-7-10
 ********************************************************************************************************************/
#include "headfile.h"
struct ENCODER enc;

void Encoder_Init ()
{
    Enc_Init;

}

void Control_Speed()
{  

        enc.pulse = Speed_Get;
        enc.distance += enc.pulse;
        Enc_Clear;
        enc.real_speed = enc.pulse * rate.encoder;
        enc.real_speed = (enc.real_speed>3400?3400:enc.real_speed);



        enc.speed_old= enc.filter_speed;
        enc.speed_new= enc.real_speed;

        enc.filter_speed = ((enc.speed_new-enc.speed_old)> 300?(enc.speed_old+300):enc.speed_new);
        enc.filter_speed = ((enc. speed_new-enc.speed_old)< -300?(enc.speed_old-300):enc.speed_new);

}
//¿ÉÒÔ³¢ÊÔ·Öµ÷×óÓÒÂÖ
#ifdef xuan1
void My_Read_Speed ()
{
    cnt5ms_Encoder++;
    if (cnt5ms_Encoder == 5)
    {
        My_Get_Speed = -gpt12_get(My_GPT);
        gpt12_clear(My_GPT);
        My_Real_Speed = (float)My_Get_Speed * 0.025 + 6.4;
        cnt5ms_Encoder = 0;
        // systick_delay_ms(STM0, 100);
    }
}
#endif
