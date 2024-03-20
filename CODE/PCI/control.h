  #ifndef _control_H_
#define _control_H_


/**********************************************************
#define SERVO_FREQUENCY    50

#define SERVO_MIDDLE 410
#define SERVO_DIFF 70
//#define SERVO_MIDDLE 170
//#define SERVO_DIFF 60



#define MOTOR  IfxGtm_ATOM2_6_TOUT36_P32_0_OUT
#define MOTOR1  IfxGtm_ATOM2_5_TOUT35_P33_13_OUT


#define SERVO  IfxGtm_ATOM2_4_TOUT34_P33_12_OUT
#define SERVO2       IfxGtm_ATOM0_2_TOUT33_P33_11_OUT


#define motor_init ATOM_PWM_InitConfig(MOTOR,0,MOTOR_FREQUENCY)
#define motor1_init ATOM_PWM_InitConfig(MOTOR1,0,MOTOR_FREQUENCY)
#define steer_init ATOM_PWM_InitConfig(SERVO,SERVO_MIDDLE,SERVO_FREQUENCY)
#define steer1_init ATOM_PWM_InitConfig(SERVO2,SERVO_MIDDLE,SERVO_FREQUENCY)


#define servo(a) ATOM_PWM_SetDuty(SERVO2, a , SERVO_FREQUENCY)
#define servo1(a) ATOM_PWM_SetDuty(SERVO, a , SERVO_FREQUENCY)
#define motor(a) ATOM_PWM_SetDuty(MOTOR1, a , MOTOR_FREQUENCY)
#define motor1(a) ATOM_PWM_SetDuty(MOTOR, a , MOTOR_FREQUENCY)
***********************************************************/




#define SERVO_FREQUENCY  50

#define ISLAND_ENC
#define CROSS_DEC
//#define CHE_2
#ifndef CHE_2

#define SERVO_MIDDLE 490
#define SERVO_DIFF 170.0
#define SERVO_MIN 320
#define SERVO_MAX 660
#define MOTOR_FREQUENCY 15000

#else
#define SERVO_MIDDLE 422
#define SERVO_DIFF 120.0
#define SERVO_MIN 302
#define SERVO_MAX 542
#define MOTOR_FREQUENCY 15000

#endif

//#define My_Motor0 ATOM2_CH5_P33_13
//#define My_Motor1 ATOM1_CH5_P32_4

#define NEW_377
#ifndef NEW_377

#define MOTOR1 ATOM0_CH7_P20_8
#define MOTOR  ATOM1_CH5_P20_9

#define SERVO ATOM1_CH6_P20_10
#define SERVO1 ATOM2_CH7_P20_7

#else

#define MOTOR1 ATOM0_CH7_P20_8
#define MOTOR  ATOM2_CH7_P20_7

#define SERVO1 ATOM1_CH5_P20_9
#define SERVO ATOM1_CH6_P20_10

#endif



#define motor_init gtm_pwm_init(MOTOR, MOTOR_FREQUENCY, 0)
#define motor1_init gtm_pwm_init(MOTOR1, MOTOR_FREQUENCY, 0)
#define steer_init gtm_pwm_init(SERVO, SERVO_FREQUENCY, SERVO_MIDDLE)
#define steer1_init gtm_pwm_init(SERVO1, SERVO_FREQUENCY, SERVO_MIDDLE)


#define servo(a)  pwm_duty(SERVO, a)
#define servo1(a)  pwm_duty(SERVO1, a)
#define motor(a)  pwm_duty(MOTOR, a)
#define motor1(a)  pwm_duty(MOTOR1, a)



void motor_control(void);
void steer_control(void);
void Control_Init(void);

//void ai_motor_control(void);
//void ai_steer_control(void);

#endif
