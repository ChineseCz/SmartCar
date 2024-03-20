/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * @电设部分
 * @file            Openmv
 * @function        Openmv摄像头循彩线以及与单片机通信
 * @author          Cz
 * @date            2021-10-7
 * @注释            摄像头端对数字识别受光线影响过大，待优化。
 ********************************************************************************************************************/
//电设用的Openmv系列摄像头，可了解了解，比赛中没使用。
#include "headfile.h"

struct OPENMV  mv,art;
char * p=mv.str;
int i=0;
void openmv_get_str()
{

    if (uart_query(UART_1,&mv.data))
    {
//        gpio_set(P00_0,1);
        if (mv.data!='T' && mv.data!='F' && mv.data!='L'&&mv.data!='Z'&&mv.data!='X'&&mv.data!='S' )
        {
            mv.str[i]=mv.data;
            i++;
        }
        else if (mv.data=='T')
        {
            mv.str[i]='\0';
            i=0;
            mv.err = atof(mv.str);
            memset(mv.str,0,sizeof(mv.str));
            mv.track=2;
        }
        else if (mv.data=='F')
        {
            mv.str[i]='\0';
            i=0;
            mv.err = atof(mv.str);
            memset(mv.str,0,sizeof(mv.str));
            mv.track=1;
        }
        else if (mv.data=='L')
        {
            mv.str[i]='\0';
            i=0;
            mv.err = atof(mv.str);
            memset(mv.str,0,sizeof(mv.str));
            if (!cnt.left && !cnt.right && art.con_left!=2 &&art.con_right!=2) mv.track=0;
        }


    }
//    else
//    {
//        gpio_set(P00_0,0);
//    }
}




void direc_control()
{
    if (art.con_left)
    {
        cnt.left++;
        if (cnt.left>enc.speed_control_out_max*1000/5)
        {
            art.con_left=2;
            if (cnt.left>enc.speed_control_out_max*2000/5)
            {
                art.con_left=0;
                cnt.left=0;
                if (flag.drug<4&&flag.str)
                {
                    flag.turn_memory[cnt.turn_num]=1;
                    cnt.turn_num++;
                    if (cnt.turn_num==2) cnt.turn_num=1;
                }
                else if(flag.drug>3)
                {
                    cnt.turn_num--;
                }
            }

        }
    }
    else if (art.con_right)
    {
        cnt.right++;
        if (cnt.right>enc.speed_control_out_max*1000/5)
        {
            art.con_right=2;
            if (cnt.right>enc.speed_control_out_max*2000/5)
            {
                art.con_right=0;
                cnt.right=0;
                if (flag.drug<4&&flag.str)
                {
                    flag.turn_memory[cnt.turn_num]=2;
                    cnt.turn_num++;
                    if (cnt.turn_num==2) cnt.turn_num=1;
                }
                else if(flag.drug>3)
                {
                    cnt.turn_num--;
                }
            }

        }
    }

}
/*注意art是art，MV是4*/
void track_control()
{
    if (mv.track==2 &&flag.drug!=5)
    {
        if (art.num_judge==1 || art.num_judge==2)
        {
            if (art.num_judge==1 && flag.drug!=4 && flag.drug!=5)
                art.con_left=1;
            else if (art.num_judge==1 && flag.drug==4)
            {
                art.con_right=1;
                flag.drug=5;
            }

            else if (art.num_judge==2 && flag.drug!=4 && flag.drug!=5)
                art.con_right=1;
            else if (art.num_judge==2 && flag.drug==4)
            {
                art.con_left=1;
                flag.drug=5;
            }
        }
        else if(flag.drug==4 && cnt.turn_num == 1)
        {
            if(flag.turn_memory[cnt.turn_num]==1)
                art.con_right=1;
            else if (flag.turn_memory[cnt.turn_num]==2)
                art.con_left=1;
            cnt.turn_num--;
        }
        else if(flag.drug==4 && cnt.turn_num == 0)
        {
            if(flag.turn_memory[cnt.turn_num]==1)
                art.con_right=1;
            else if (flag.turn_memory[cnt.turn_num]==2)
                art.con_left=1;

            flag.drug=5;

        }

        else if (flag.turn_direc==1)
        {
            art.con_left=1;
        }
        else if (flag.turn_direc==2)
        {
            art.con_right=1;
        }




    }

}




void openart_get_str()
{
    if (uart_query(UART_0,&art.data))
    {
        if (art.data=='l')
        {
            art.con_left=1;

        }
        else if (art.data=='r')
        {
            art.con_right=1;
        }
        else if (art.data=='a')
        {
            art.num_judge=1;
        }
        else if (art.data=='b')
        {
            art.num_judge=2;
        }
        else if (art.data=='c')
        {
            art.num_judge=3;
        }
        else if (art.data=='d')
        {
            art.num_judge=4;
        }
        else if (art.data=='e')
        {
            art.num_judge=5;
        }
        else if (art.data=='f')
        {
            art.num_judge=6;
        }
        else if (art.data=='g')
        {
            art.num_judge=7;
        }
        else if (art.data=='h')
        {
            art.num_judge=8;
        }

    }
}

void openmv_send_num()
{
    return;
}

