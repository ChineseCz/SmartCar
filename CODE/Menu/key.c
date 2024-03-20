/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 *
 * @file            Key
 * @function        ʵ�ֳ�����ر�while���ּ�⼴�ɣ�������ϰ�ߣ������ǼӼ��������������ɡ�
 * @author          Cz
 * @date            2021-7-10
 ********************************************************************************************************************/
#include "headfile.h"

struct FLAG flag;
struct CNT cnt;
struct RATE rate;

void Key_Init()
{


    gpio_init(KEY_DOWN, GPI, 1, PULLUP);
    gpio_init(KEY_UP, GPI, 1, PULLUP);
    gpio_init(KEY_RIGHT, GPI, 1, PULLUP);
    gpio_init(KEY_LEFT, GPI, 1, PULLUP);
    gpio_init(KEY_CENTER, GPI, 1, PULLUP);

    gpio_init(KEY_P0,GPI, 1, PULLUP);
    gpio_init(KEY_P1, GPI, 1, PULLUP);
    gpio_init(KEY_P2, GPI, 1, PULLUP);
}

unsigned char KEY_Read(KEYn_e KEYno)
{
    switch(KEYno)
    {
      case KEY0:
        return gpio_get(KEY_P0);//ĸ���ϰ���0
      break;

      case KEY1:
        return gpio_get(KEY_P1);//ĸ���ϰ���1
      break;

      case KEY2:
        return gpio_get(KEY_P2);//ĸ���ϰ���2
      break;

      case KEYUP:
        return gpio_get(KEY_UP);//ĸ���ϰ���0
      break;

      case KEYDOWN:
        return gpio_get(KEY_DOWN);//ĸ���ϰ���1
      break;

      case KEYLEFT:
        return gpio_get(KEY_LEFT);//ĸ���ϰ���2
      break;

      case KEYRIGHT:
        return gpio_get(KEY_RIGHT);//ĸ���ϰ���1
      break;

      case KEYCENTER:
        return gpio_get(KEY_CENTER);//ĸ���ϰ���2
      break;

      default:
        return 0XFF;
    }
    return 0;
}


int keyup()
{
    int x=1;
    if(  KEY_Read(KEYUP) == 0)
	{
		my_delay(1000);
		if(KEY_Read(KEYUP) == 0)
		{
            x=0;
		}
	}
	while(KEY_Read(KEYUP) == 0);
	return x;
}
int keydown()
{
	int x=1;
	if(KEY_Read(KEYDOWN) == 0)
	{
		my_delay(1000);
		if(KEY_Read(KEYDOWN) == 0)
		{
            x=0;
		}
	}
	while(KEY_Read(KEYDOWN) == 0);
	return x;
}
int keycenter()
{
	int x=1;
	if(KEY_Read(KEYCENTER) == 0)
	{
		my_delay(1000);
		if(KEY_Read(KEYCENTER) == 0)
		{
            x=0;
		}
	}
	while(KEY_Read(KEYCENTER) == 0);
	return x;
}
int keyleft()
{
	int x=1;
	if(KEY_Read(KEYLEFT) == 0)
	{
		my_delay(1000);
		if(KEY_Read(KEYLEFT) == 0)
		{
            x=0;//return x;
		}
	}
	while(KEY_Read(KEYLEFT) == 0);
	return x;
}
int keyright()
{
	int x=1;
	if(KEY_Read(KEYRIGHT) == 0)
	{
		my_delay(5000);
		if(KEY_Read(KEYRIGHT) == 0)
		{
            x=0;//return x;
		}
	}
	while(KEY_Read(KEYRIGHT) == 0);
	return x;
}
int key1()
{
	int x=1;
	if(KEY_Read(KEY1) == 0)
	{
		my_delay(1000);
		if(KEY_Read(KEY1) == 0)
		{
            x=0;
		}
	}
	while(KEY_Read(KEY1) == 0);
	return x;
}
int key2()
{
	int x=1;
	if(KEY_Read(KEY0) == 0)
	{
		my_delay(1000);
		if(KEY_Read(KEY0) == 0)
		{
            x=0;
		}
	}
	while(KEY_Read(KEY0) == 0);
	return x;
}

int key3()
{
    int x=1;
    if(KEY_Read(KEY2) == 0)
    {
        my_delay(1000);
        if(KEY_Read(KEY2) == 0)
        {
            x=0;
        }
    }
    while(KEY_Read(KEY2) == 0);
    return x;
}



