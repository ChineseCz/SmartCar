#ifndef _key_H_
#define _key_H_





#ifndef NEW_377

#define KEY_DOWN P21_7
#define KEY_UP P20_3
#define KEY_RIGHT P20_2
#define KEY_LEFT P20_0
#define KEY_CENTER P21_5


#define KEY_P0 P21_4
#define KEY_P1 P22_3
#define KEY_P2 P21_3


#else

#define KEY_DOWN P33_11
#define KEY_UP P21_4
#define KEY_RIGHT P22_3
#define KEY_LEFT P21_3
#define KEY_CENTER P33_13


#define KEY_P0 P20_3
#define KEY_P1 P20_2
#define KEY_P2 P20_0
#define KEY_P3 P21_7
#define KEY_P4 P21_5
#define KEY_P5 P21_2
#endif




#define KEY_UP_Init gpio_init(KEY_UP, GPI, 1, PULLUP)
#define KEY_DOWN_Init gpio_init(KEY_DOWN, GPI, 1, PULLUP)
#define KEY_LEFT_Init gpio_init(KEY_LEFT, GPI, 1, PULLUP)
#define KEY_RIGHT_Init gpio_init(KEY_RIGHT, GPI, 1, PULLUP)
#define KEY_CENTER_Init gpio_init(KEY_CENTER, GPI, 1, PULLUP)
#define KEY0_Init gpio_init(KEY_P0, GPI, 1, PULLUP)
#define KEY1_Init gpio_init(KEY_P1, GPI, 1, PULLUP)
#define KEY2_Init gpio_init(KEY_P2, GPI, 1, PULLUP)



typedef enum
{
    KEY0,  //Ä¸°åÉÏ°´¼ü0
    KEY1,
    KEY2,
    KEYLEFT,
    KEYRIGHT,
    KEYUP,
    KEYDOWN,
    KEYCENTER
} KEYn_e;

void Key_Init(void);
int keyup(void);
int keydown(void);
int keycenter(void);
int keyleft(void);
int keyright(void);
int key1(void);
int key2(void);
int key3(void);
extern struct RATE rate;
extern struct FLAG flag;
extern struct CNT cnt;

#endif
