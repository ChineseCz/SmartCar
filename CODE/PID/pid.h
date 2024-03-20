
#ifndef _pid_H_
#define _pid_H_



void regular_revise(void);


void PID_steer_trace(void);
void PID_speed_control(void);
void ai_steer_trace(void);
extern struct PID steer,motor;
#endif



