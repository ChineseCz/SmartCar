/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 *
 * @file            LSTM
 * @author          Cz
 * @date            2021-5-30
 ********************************************************************************************************************/
//神经网络部分，了解了解就好
#include<stdio.h>
#include<math.h>
#include<string.h>
#define innode 6
#define hidenode 2
#define cellnum 2
#define Dense_hidenode 1
double x[cellnum][innode];
float LSTM_w[6][8]={
{-0.4173537,0.26376134,0.43293816,0.041716218,-0.5093627,0.6478637,-0.1627785,0.38287556},
{-0.014154273,-0.2593966,0.095865615,-0.03511741,0.46501085,0.27666536,-0.032516122,0.309852},
{0.41260952,-0.51802886,0.07190071,-0.3868057,-0.56378305,0.16278356,-0.14959858,-0.55539066},
{-0.42835,0.19823822,0.593574,-0.2981742,-0.34020305,0.47902396,-0.21146297,-0.3662371},
{-0.021036165,-0.14242187,-0.5736565,-0.34069473,0.44193128,0.6206997,-0.6354572,-0.22186348},
{0.26514,0.010530583,0.0030909963,0.42398733,0.56744444,-0.59024084,0.13200031,-0.006235053}
};
float hw[2][8]={
{0.30281234,-0.06402916,-0.43406785,0.29500866,0.2343546,0.017751016,-0.4541998,0.6055083},
{0.041439082,-0.23078188,0.0069902916,0.019872913,0.6560369,0.56597996,0.44220093,0.010393433}
};
double LSTM_b[8]={
    0.004994092974811792,
    0.004990984685719013,
    1.0049787759780884,
    1.0049782991409302,
    -0.004988259170204401,
    0.0049878256395459175,
    0.004994564689695835,
    0.004991311579942703
};

float LSTM_w1[2][1]={
{-1.3158210515975952},
{1.0272846221923828}
};
double LSTM_b1[1]={
	0.0049892994575202465
};


double Gate[cellnum][hidenode*4];
double Ct[cellnum][hidenode];
double ht[cellnum][hidenode];
double ht_pre[cellnum][hidenode];
double Ct_pre[cellnum][hidenode];

double output[cellnum][Dense_hidenode];


double sigmoid(double x) 
{
	return 1 / (1+exp(-x));
}
void LSTM()
{
	for (int num=0;num<cellnum;num++)
	{
		for (int j=0;j<hidenode*4;j++)//某一门下隐藏层节点  
		{	  			
	   		for (int k=0;k<innode;k++)//某一门输入层节点，x 
	   		{
				Gate[num][j]+=x[num][k]*LSTM_w[k][j];
			}
			for (int k=0;k<hidenode;k++)//某一门输入层节点，ht-1 
			{
				Gate[num][j]+=ht_pre[num][k]*hw[k][j];
			}
			Gate[num][j]+=LSTM_b[j];

			if ( j>=2*hidenode && j<3*hidenode )
				Gate[num][j]=tanh(Gate[num][j]);
			else
				Gate[num][j]=sigmoid(Gate[num][j]);


		}
		
		/****长记忆********/ 
		for (int i=0;i<hidenode;i++)
		{					       
			Ct[num][i]=Gate[num][1*hidenode+i]*Ct_pre[num][i]+Gate[num][i]*Gate[num][2*hidenode+i];//f*Ct_pre+i*c~
			if (num!=hidenode-1) Ct_pre[num+1][i]=Ct[num][i];	
		}
	
		
		/****短记忆(ht输出)********/
		for (int i=0;i<hidenode;i++)
		{
			
			ht[num][i]=Gate[num][3*hidenode+i]*tanh(Ct[num][i]);//ot*tanh(Ct)
			if (num!=hidenode-1) ht_pre[num+1][i]=ht[num][i];	
		} 
			
	}

}
void Dense()
{
	for (int num=0;num<cellnum;num++)
	{
		for (int i=0;i<Dense_hidenode;i++)
		{
			for (int j=0;j<hidenode;j++)
			{
				output[num][i]+=ht[num][j]*LSTM_w1[j][i];
			}
		}
		for (int i=0;i<Dense_hidenode;i++)
		{
			output[num][i]+=LSTM_b1[i];
		}		
			
	}
}

void input_init()
{
//    x[0][0]=308;
//    x[0][1]=318;
//    x[0][2]=542;
//    x[0][3]=433;
//    x[0][4]=245;
//    x[0][5]=232;	
//    
//    x[1][0]=305;
//    x[1][1]=306;
//    x[1][2]=554;
//    x[1][3]=439;
//    x[1][4]=250;
//    x[1][5]=246;

    x[0][0]=299;
    x[0][1]=319;
    x[0][2]=556;
    x[0][3]=435;
    x[0][4]=253;
    x[0][5]=238;	
    
    x[1][0]=297;
    x[1][1]=324;
    x[1][2]=543;
    x[1][3]=434;
    x[1][4]=244;
    x[1][5]=228;   

//    x[0][0]=305;
//    x[0][1]=306;
//    x[0][2]=554;
//    x[0][3]=439;
//    x[0][4]=250;
//    x[0][5]=246;	
//    
//    x[1][0]=299;
//    x[1][1]=319;
//    x[1][2]=556;
//    x[1][3]=435;
//    x[1][4]=253;
//    x[1][5]=238;   
	//*不清0会爆掉 
    memset(Gate,0,sizeof(Gate));
    memset(Ct,0,sizeof(Ct));
    memset(Ct_pre,0,sizeof(Ct_pre));
    memset(ht,0,sizeof(ht));
    memset(ht_pre,0,sizeof(ht_pre));
    memset(output,0,sizeof(output));

} 
void transform()
{

    x[0][0]=(x[0][0]-26)/(490-26);
    x[0][1]=(x[0][1]-0)/(1023-0);
    x[0][2]=(x[0][2]-0)/(857-0);
    x[0][3]=(x[0][3]-0)/(860-0);
    x[0][4]=(x[0][4]-0)/(1023-0);
    x[0][5]=(x[0][5]-0)/(531-0);
    
    x[1][0]=(x[1][0]-26)/(490-26);
    x[1][1]=(x[1][1]-0)/(1023-0);
    x[1][2]=(x[1][2]-0)/(857-0);
    x[1][3]=(x[1][3]-0)/(860-0);
    x[1][4]=(x[1][4]-0)/(1023-0);
    x[1][5]=(x[1][5]-0)/(531-0);

}
void inverse_transform()
{
	for (int num=0;num<cellnum;num++)
		for (int i=0;i<Dense_hidenode;i++)
  		  output[num][i]=output[num][i]*(620-360) + 360;
}
void Run_Model_LSTM()
{

    input_init();
    transform();
//	printf("%lf %lf\n",output[0][0],output[0][1]);
    LSTM();
    Dense();
    inverse_transform();
    for (int num=0;num<cellnum;num++)
    {
        for (int i=0;i<hidenode;i++)
            printf("%lf ",ht[num][i]);
        printf("\n");
        for (int i=0;i<Dense_hidenode;i++)
            printf("%lf",output[num][i]);
        printf("\n");
    }

}
