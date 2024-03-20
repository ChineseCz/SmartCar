/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 *
 * @file            spe
 * @function        ������Ʊ�����ʼ��
 * @author          Cz
 * @date            2021-7-10
 ********************************************************************************************************************/
#include "headfile.h"
/**��ʼ��һЩ�����ļ�����**/

#define All_spe_Init 1
#define INF 999


void Spe_Init()
{
    //�ܿ���
    flag.all_EN=All_spe_Init;
    //�±�
    cnt.left_die_xb=0;
    cnt.right_die_xb=0;
    cnt.cross_xb=0;
    cnt.flash_xb=0;



    /*EN���ƽ���Ԫ�ؿ��Ƴ�����spe����ʱ��*/

    /*����*/
    cnt.island_num=1;
    flag.island_EN=1;


    flag.T_island_spe=1;
    flag.island_spe=1;
    for (int i=0;i<10;i++)
    {

        cnt.T_island_t1[i]=100;
        cnt.T_island_t2[i]=30;
        cnt.T_island_t3[i]=40;
        cnt.T_island_s1[i]=440;
        cnt.T_island_s2[i]=500;
        cnt.T_island_s3[i]=440;
    }



    /*���Ҵ���*/
    cnt.left_die_num=0;
    cnt.right_die_num=0;
    flag.left_die_EN=0;
    flag.right_die_EN=0;
    flag.left_die_spe=0;
    flag.right_die_spe=0;
    for (int i=0;i<10;i++)
    {
        cnt.left_die_open_time[i]=INF;
        cnt.left_die_close_time[i]=0;
        cnt.left_die_time[i]=0;
        cnt.left_die_to_right_time[i]=0;
        cnt.left_die_angle[i]=0;

        cnt.right_die_open_time[0]=INF;
        cnt.right_die_close_time[0]=0;
        cnt.right_die_time[0]=0;
        cnt.right_die_to_left_time[0]=0;
        cnt.right_die_angle[0]=0;
    }

    /*ʮ��*/
    flag.cross_EN=0;
    flag.cross_spe=0;
    for (int i=0;i<10;i++)
    {
        cnt.cross_open_time[0]=INF;
        cnt.cross_close_time[0]=INF;
    }

    /***���̱�־λ***/

    /*�޳�������*/
    flag.island=0;//��⻷�������
    flag.island_out=0; //����״̬
    cnt.island=0;


    /*�г�������*/
    flag.T_island=0;//��⻷�������
    flag.T_island_out=0; //����״̬
    cnt.T_island=0;

    /*���Ҵ���*/
    flag.left_die_spe=0;//����Ƿ��
    flag.right_die_spe=0;//����Ƿ��
    flag.left_fan=0;
    flag.right_fan=0;
    cnt.left_fan=0;
    cnt.right_fan=0;
    cnt.left_die=0;
    cnt.right_die=0;


    /*ͣ��*/
    cnt.run_time_limit=80;

}







