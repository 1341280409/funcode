//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
#include "CommonAPI.h"
#include "LessonX.h"
#include<windows.h>
#include<Mmsystem.h>
#include<mmsystem.h>
#pragma comment(lib,"Winmm.lib")
int blood=1;//����Ѫ����ʼ��
int boss1hp=150;//BOSS1Ѫ��
float boss22hp=200;//BOSS2Ѫ��
float boss3hp=500;//BOSS3Ѫ��
//��Ϸ����
int level=0;
//�����ٶ�
float g_fSpeedLeft=0.f,g_fSpeedRight=0.f,g_fSpeedTop=0.f,g_fSpeedBottom=0.f;
//��ͼ�ٶ�
float ditu1=0;
//���巽��
bool bFilp=false;
//������λ�ã�����һһע��
float PositionX1=0.f,PositionY1=0.f;
float PositionX2=0.f,PositionY2=0.f;
float PositionX3=0.f,PositionY3=0.f;
float PositionX4=0.f,PositionY4=0.f;
float PositionX5=0.f,PositionY5=0.f;
float PositionX6=0.f,PositionY6=0.f;
float PositionX7=0.f,PositionY7=0.f;
float PositionX8=0.f,PositionY8=0.f;
float PositionX9=0.f,PositionY9=0.f;
float PositionX10=0.f,PositionY10=0.f;
float PositionX11=0.f,PositionY11=0.f;
float PositionX12=0.f,PositionY12=0.f;
float PositionX13=0.f,PositionY13=0.f;
float PositionX14=0.f,PositionY14=0.f;
float PositionX15=0.f,PositionY15=0.f;
float PositionX16=0.f,PositionY16=0.f;
float PositionX17=0.f,PositionY17=0.f;
float PositionX18=0.f,PositionY18=0.f;
float PositionX19=0.f,PositionY19=0.f;
float PositionX20=0.f,PositionY20=0.f;
float PositionX21=0.f,PositionY21=0.f;
float PositionX22=0.f,PositionY22=0.f;
float PositionX23=0.f,PositionY23=0.f;
float PositionX24=0.f,PositionY24=0.f;
float PositionX25=0.f,PositionY25=0.f;
float PositionX26=0.f,PositionY26=0.f;
float damenweizhiX=0;
float oldPositionY2;
//��һ�ع���
typedef struct mosquitoStruct
{
	char *szName;
	int speed;
	struct mosquitoStruct *next;
}Mosquito;
float g_fAppearTime = 0.5f;
int g_iCount = 0;		//����������
char *g_chmosquito[1000];// �洢�������ֵ�ָ������
char *jian[1000];
char *fangjian[1000];
//��һ�ع���
typedef struct mosquitoStruc
{
	char *szNam;
	int spee;
	struct mosquitoStruc *nex;
}Mosquit;
float g_fAppearTim = 3.f;		//gongjian�����ļ��ʱ��
int g_iCoun = 0;		//gongjian������
float g_fEmptyHookSpeed	= 15.f;//�����ٶ�
//����߽�����
float fScreenLeft ;
float fScreenRight ;
float fScreenTop ;
float fScreenBottom ;
//�������ӵ�����
float fStartX;
float fStartY;
float fEndX;
float fEndY;

float fStartX1;
float fStartY1;
float fEndX1;
float fEndY1;

float fStartX2;
float fStartY2;
float fEndX2;
float fEndY2;

float fStartX3;
float fStartY3;
float fEndX3;
float fEndY3;

float fStartX4;
float fStartY4;
float fEndX4;
float fEndY4;
//������ʼ��
float nengliang=100;
//����������ʼ��
int shengyu=10;
//��������ֵ
int g_chengqiang=10;
//������С������
int g_i = 0;
//����xiaoguai�ļ��ʱ
float g_fBaseTime[5] = {3.f, 5.5f, 4.2f,8.f,2.4f};
float g_fCurrentTime[5] = {3.f, 5.5f, 4.2f,8.f,2.4f} ;
//xiaoguai���ٶ�
float g_fSpeed[5] = {6, 10, 15,30,5};
//����С�ֶ�Ӧ������ǰ׺
char *g_szType[5] = {"ufo_qq_muban","ufo_ww_muban","ufo_ee_muban","ufo_rr_muban","ufo_tt_muban"};
//�����ӳ�
int g_iScore[5] = {1,2,3,2,5};
int g_iNum = 0;	//����ĳ��������
int g_iNu=0;//��������
int g_iN=0;//BOSS�ļ�������
float g_fucktime1=3;//BOSS����1
float g_fucktime2=6;//BOSS����2
//BOSS���ܳ���λ��
int qq[8]={-33.182,-22.696,-14.318,-4.317,5.682,15.682,24.317,33.182};
//bossjinengˢ��ʱ��
float botime=4;
//BOSS����������
int g_x;
//�ؿ�����
int nandian=1;
///////////////////////////////////////////////////////////////////////////////////////////
//
// ���������
//
//////////////////////////////////////////////////////////////////////////////////////////
int PASCAL WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR     lpCmdLine,
                   int       nCmdShow)
{
	// ��ʼ����Ϸ����
	if( !dInitGameEngine( hInstance, lpCmdLine ) )
		return 0;
    //����ĳ������ٶ�
    dSetSpriteLinearVelocityY("b3",15);
    dSetSpriteLinearVelocity("feilun",10,0);
    dSetSpriteLinearVelocityY("boss3",-15);
    dSetSpriteLinearVelocityX("boss1",-7);
    //�������
    dShowCursor(false);
    //��������
    dPlaySound("qw.ogg",1,1);
	// To do : �ڴ�ʹ��API���Ĵ��ڱ���
	dSetWindowTitle("yaodaxian");
	//������ʼ����
	if(level==0)
    {
        dLoadMap("level0.t2d");
    }
	// ������ѭ����������Ļͼ��ˢ�µȹ���
	while( dEngineMainLoop() )
	{
		// ��ȡ���ε���֮���ʱ�����ݸ���Ϸ�߼�����
		float	fTimeDelta	=	dGetTimeDelta();
		// ִ����Ϸ��ѭ��
		GameMainLoop( fTimeDelta );
		//��ȡ����߽�
        fScreenLeft = dGetScreenLeft();
        fScreenRight = dGetScreenRight();
        fScreenTop = dGetScreenTop();
        fScreenBottom = dGetScreenBottom();
		//��ȡ����λ�ã���������������
         PositionX2=dGetSpritePositionX( "zuoguai" );
         PositionY2=dGetSpritePositionY( "zuoguai" );
         PositionX3=dGetSpritePositionX( "jianshou1" );
         PositionY3=dGetSpritePositionY( "jianshou1" );
         damenweizhiX=dGetSpritePositionX( "damen" );
         PositionX1=dGetSpritePositionX( "baoxiang" );
         PositionY1=dGetSpritePositionY( "baoxiang" );
         PositionX4=dGetSpritePositionX( "next" );
         PositionY4=dGetSpritePositionY( "next" );
         PositionX5=dGetSpritePositionX( "shubiao" );
         PositionY5=dGetSpritePositionY( "shubiao" );
         PositionX6=dGetSpritePositionX( "jianshou2" );
         PositionY6=dGetSpritePositionY( "jianshou2" );
         PositionX7=dGetSpritePositionX( "jianshou3" );
         PositionY7=dGetSpritePositionY( "jianshou3" );
         PositionX8=dGetSpritePositionX( "dadao" );
         PositionY8=dGetSpritePositionY( "dadao" );
         PositionX9=dGetSpritePositionX( "review" );
         PositionY9=dGetSpritePositionY( "review" );
         PositionX10=dGetSpritePositionX( "review2" );
         PositionY10=dGetSpritePositionY( "review2" );
         PositionX11=dGetSpritePositionX( "next3" );
         PositionY11=dGetSpritePositionY( "next3" );
         PositionX12=dGetSpritePositionX( "zuiqiang" );
         PositionY12=dGetSpritePositionY( "zuiqiang" );
         PositionX13=dGetSpritePositionX( "fanhui6" );
         PositionY13=dGetSpritePositionY( "fanhui6" );
         PositionX14=dGetSpritePositionX( "review3" );
         PositionY14=dGetSpritePositionY( "review3" );
         PositionX15=dGetSpritePositionX( "next5" );
         PositionY15=dGetSpritePositionY( "next5" );
         PositionX16=dGetSpritePositionX( "fanhui10" );
         PositionY16=dGetSpritePositionY( "fanhui10" );
         PositionX17=dGetSpritePositionX( "wotui" );
         PositionY17=dGetSpritePositionY( "wotui" );
         PositionX18=dGetSpritePositionX( "review10" );
         PositionY18=dGetSpritePositionY( "review10" );
         PositionX19=dGetSpritePositionX( "boss3" );
         PositionY19=dGetSpritePositionY( "boss3" );
         PositionX20=dGetSpritePositionX( "jianjie" );
         PositionY20=dGetSpritePositionY( "jianjie" );
         PositionX21=dGetSpritePositionX( "exit" );
         PositionY21=dGetSpritePositionY( "exit" );
         PositionX22=dGetSpritePositionX( "nextpage6" );
         PositionY22=dGetSpritePositionY( "nextpage6" );
         PositionX23=dGetSpritePositionX( "nextpage1" );
         PositionY23=dGetSpritePositionY( "nextpage1" );

         //����λ�ô����ؿ�����
         if(PositionY8<-2.f)
         {
             dSpriteMoveTo("guai1",PositionX8, PositionY8,9,1);
             dSpriteMoveTo("guai2",PositionX8, PositionY8,9,1);
             dSpriteMoveTo("guai3",PositionX8, PositionY8,9,1);
         }
         if(PositionY12<-2.f)
         {
             dSpriteMoveTo("kkk1",PositionX12, PositionY12,9,1);
             dSpriteMoveTo("kkk2",PositionX12, PositionY12,15,1);
         }
         if(PositionX12>8.f)
         {
             dSpriteMoveTo("kkk3",PositionX12, PositionY12,10,1);
             dSpriteMoveTo("kkk4",PositionX12, PositionY12,9,1);
         }
         if(PositionX12>8.f&&PositionY12<-2.f)
         {
             dSpriteMoveTo("kkk5",PositionX12, PositionY12,13,1);
             dSpriteMoveTo("kkk6",PositionX12, PositionY12,9,1);
         }
         if(PositionX12>8.f&&PositionY12<26.f)
         {
             dSpriteMoveTo("kkk10",PositionX12, PositionY12,18,1);
         }


         //���Ӿ���Ĵ�����ʵ��
     fStartX =	dGetSpriteLinkPointPosX("c5",1);
	 fStartY = dGetSpriteLinkPointPosY("c5",1);
	 fEndX	= dGetSpriteLinkPointPosX("b3",1);
	 fEndY	= dGetSpriteLinkPointPosY("b3",1);
    dDrawLine(fStartX, fStartY, fEndX, fEndY, 2.f, 8, 50, 50, 50, 255 );

     fStartX1 =	dGetSpriteLinkPointPosX("c5",2);
	 fStartY1 = dGetSpriteLinkPointPosY("c5",2);
	 fEndX1	= dGetSpriteLinkPointPosX("b4",1);
	 fEndY1	= dGetSpriteLinkPointPosY("b4",1);
	dDrawLine(fStartX1, fStartY1, fEndX1, fEndY1, 2.f, 8, 50, 50, 50, 255 );

     fStartX2 =	dGetSpriteLinkPointPosX("c5",3);
	 fStartY2 = dGetSpriteLinkPointPosY("c5",3);
	 fEndX2	= dGetSpriteLinkPointPosX("b5",1);
	 fEndY2	= dGetSpriteLinkPointPosY("b5",1);
	dDrawLine(fStartX2, fStartY2, fEndX2, fEndY2, 2.f, 8, 50, 50, 50, 255 );

     fStartX3 =	dGetSpriteLinkPointPosX("c5",4);
	 fStartY3= dGetSpriteLinkPointPosY("c5",4);
	 fEndX3	= dGetSpriteLinkPointPosX("b6",1);
	 fEndY3	= dGetSpriteLinkPointPosY("b6",1);
	dDrawLine(fStartX3, fStartY3, fEndX3, fEndY3, 2.f, 8, 50, 50, 50, 255 );

     fStartX4 =	dGetSpriteLinkPointPosX("c5",5);
	 fStartY4 = dGetSpriteLinkPointPosY("c5",5);
	 fEndX4	= dGetSpriteLinkPointPosX("b7",1);
	 fEndY4	= dGetSpriteLinkPointPosY("b7",1);
	dDrawLine(fStartX4, fStartY4, fEndX4, fEndY4, 2.f, 8, 50, 50, 50, 255 );


      //���������ִ洢
         for(int q=1;q<1000;q++)
         {
         jian[q]= dMakeSpriteName("jianyu",q++);
         }
         for(int b=0;b<1000;b++)
         {
         fangjian[b]= dMakeSpriteName("fangjian",b++);
         }



    g_fAppearTime -= fTimeDelta;	//���㹭����ʣ�����ʱ��
	if(g_fAppearTime<0)
{
        int a;
		g_fAppearTime = 0.5f;
		float fposX,fposY;
     a=dRandomRange(0, 2);
     if(a==1)
     {
        fposX = PositionX3;
        fposY = PositionY3;
     }
     else if(a==0)
     {
        fposX = PositionX6;
        fposY = PositionY6;
     }
     else if(a==2)
     {
         fposX = PositionX7;
         fposY = PositionY7;
     }
		Mosquito *m = (Mosquito*)malloc(sizeof(Mosquito));	//��̬����ռ�
		if(a==1||a==0)
        {
            m->speed = dRandomRange(30, 40);		//�ٶ�
        }
		else if(a==2)
        {
            m->speed = 30	;	//�ٶ�
        }
		m->szName = dMakeSpriteName("wenzi",g_iCount++);		//����
		m->next = NULL;
		if(a==1||a==0)
        {
		dCloneSprite("wenziTemplate",m->szName);
        }
        else if(a==2)
        {
            dCloneSprite("gongjian2",m->szName);
        }
		dSetSpritePosition(m->szName,fposX, fposY);
		float fDesX ;
		float fDesY ;
		if(a==1)
        {
		 fDesX = -100;
		fDesY =  -7.819;
        }
        if(a==0)
        {
         fDesX = -100;
		 fDesY =  1;
        }
        if(a==2)
        {
            fDesX = 100;
		 fDesY =  29;
        }
		dSpriteMoveTo(m->szName,fDesX, fDesY, m->speed, false);
		int iLoop;	//ѭ�����Ʊ���
	for( iLoop = 0; iLoop < g_iCount; iLoop++ )
	{
		g_chmosquito[iLoop]=m->szName;
		dSetSpriteCollisionReceive(m->szName , 1 );
	}
    }




    g_fAppearTim -= fTimeDelta;	//����gongjian��ʣ�����ʱ��
	if(g_fAppearTim<0)
{
		g_fAppearTim = 3.f;
		int iDi = dRandomRange(0,2);	//���һ������
		float fpoX,fpoY;
		switch(iDi){
		case 0:		//top
			fpoX = dRandomRange(fScreenLeft-1.f, fScreenRight+1.f);
			fpoY = dRandomRange(fScreenTop-1.f, fScreenTop);
			break;
		case 1:		//left
			fpoX = dRandomRange(fScreenLeft-1.f, fScreenLeft);
			fpoY = dRandomRange(fScreenTop-1.f, fScreenBottom+1.f);
			break;
		case 2:		//right
			fpoX = dRandomRange(fScreenRight, fScreenRight+1.f);
			fpoY = dRandomRange(fScreenTop-1.f, fScreenBottom+1.f);
			break;
		}
		Mosquit *m = (Mosquit*)malloc(sizeof(Mosquit));	//��̬����ռ�
		m->spee = dRandomRange(20, 35);		//����ٶ�
		m->szNam = dMakeSpriteName("fangjian",g_iCoun++);		//����
		m->nex = NULL;
		dCloneSprite("fangjian",m->szNam);
        for( int iLoop = 0; iLoop < g_iCoun; iLoop++ )
	{

		dSetSpriteCollisionReceive(m->szNam , 1 );

	}
		dSetSpritePosition(m->szNam,fpoX, fpoY);
		dSpriteMoveTo(m->szNam,PositionX8, PositionY8, m->spee, false);
		//���Ʒ���
		float cc=dGetSpriteLinearVelocityX(m->szNam);
		if(cc<0)
        {
            dSetSpriteFlipX(m->szNam,1);
        }
        else
        {
            dSetSpriteFlipX(m->szNam,0);
        }
}


//ˢ�ֺ���
        float fPX,fPY;
		char *sz;
 //������ֵ�Y����̶��ھര�ڶ���5��
		fPY = fScreenTop - 5.f;
		for(int i=0; i<5; i++)
{
g_fCurrentTime[i] -= fTimeDelta;
			if(g_fCurrentTime[i] <= 0){
				g_fCurrentTime[i] = g_fBaseTime[i];
	//���������´�guaiwu������ʱ��
				fPY = dRandomRange(fScreenTop+3 , fScreenBottom - 3);
				fPX=fScreenRight+3;
//�������guaiwu�ĺ�����
				if(i == 0)
{
					sz =dMakeSpriteName("ufo_qq",g_i++);
				}
else if(i == 1)
{
					sz =dMakeSpriteName("ufo_ww",g_i++);
				}
else if(i == 2)
{
					sz =dMakeSpriteName("ufo_ee",g_i++);
}
else if(i == 3)
{
					sz =dMakeSpriteName("ufo_rr",g_i++);
				}
else if(i == 4)
{
					sz =dMakeSpriteName("ufo_tt",g_i++);
				}
				dCloneSprite(g_szType[i],sz);	//���ƶ�Ӧ��ģ��
				dSetSpritePosition(sz,fPX, fPY);
				dSetSpriteLinearVelocityX(sz,-g_fSpeed[i]);
				dSetSpriteCollisionReceive(sz , 1 );
}
		}



        float fWX,fWY;
		char *tt;

            for(int i=0; i<8; i++)
{
            g_fucktime1-=fTimeDelta;
			if(g_fucktime1<= 0){
				g_fucktime1= 7;
	//���������´�guaiwu������ʱ��
				fWX = fScreenRight+1;
				fWY=qq[i];
                tt =dMakeSpriteName("ppp",g_iN++);
				dCloneSprite("niubi",tt);	//���ƶ�Ӧ��ģ��
				dSetSpritePosition(tt,fWX, fWY);
				dSetSpriteLinearVelocityX(tt,-20);
}
		}
            g_fucktime2-=fTimeDelta;
            if(g_fucktime2<= 0){
				g_fucktime2= 5;
	//���������´�guaiwu������ʱ��
                tt =dMakeSpriteName("ppp",g_iN++);
				dCloneSprite("niubi",tt);	//���ƶ�Ӧ��ģ��
				dSetSpritePosition(tt,PositionX19, PositionX19);
				dSpriteMoveTo(tt,PositionX12,PositionX12,10,false);
}



//boss����
char *rr;
      botime-=fTimeDelta;
			if(botime<= 0){
				botime= 4;
	//���������´�guaiwu������ʱ��
                rr =dMakeSpriteName("guangbo",g_x++);
				dCloneSprite("guangbo",rr);	//���ƶ�Ӧ��ģ��
				dSetSpritePosition(rr,PositionX19, PositionY19);
				dSetSpriteLinearVelocityX(rr,-20);
			}



//�ؿ���������
if(blood<=0&&level==2)
{
dSetSpritePosition("siwang1",PositionX8,PositionY8);
       dDeleteSprite("dadao");
       dSetSpritePosition("shibai1",0,0);
       dSetSpritePosition("review2",2,15);
}
if(blood<=0&&level==1)
{
dSetSpritePosition("siwang",PositionX2,PositionY2);
       dDeleteSprite("zuoguai");

       dSetSpritePosition("shibai",0,0);
       dSetSpritePosition("review",2,15);
}
if(blood<=0&&level==3)
{
dSetSpritePosition("siwang2",PositionX12,PositionY12);
       dDeleteSprite("zuiqiang");
       dDeleteSprite("chengqiang1");
       dSetSpritePosition("shibai2",0,0);
       dSetSpritePosition("review3",2,15);
}
if(g_chengqiang<=0&&level==3)
{
dSetSpritePosition("siwang2",PositionX12,PositionY12);
       dDeleteSprite("zuiqiang");

       dSetSpritePosition("shibai2",0,0);
       dSetSpritePosition("review3",2,15);
       dDeleteSprite("chengqiang1");
}
if(boss22hp<=0&&level==3)
{
        dDeleteSprite("boss2");
        dDeleteSprite("zuiqiang");
        dSetSpritePosition("texiao2",0,-0.357);
       dSetSpritePosition("shengli2",0,0.968);
        dSetSpritePosition("next5",10.055,8.297);
        dSetSpritePosition("moxing3",-6.000,6);
        dDeleteSprite("chengqiang1");

}
if(boss3hp<=0&&level==4)
{
        dDeleteSprite("boss3");
        dDeleteSprite("zuiqiang");
        dSetSpritePosition("texiao3",0,0);
       dSetSpritePosition("shengli3",0,0);
        dSetSpritePosition("wotui",0,15);
        dSetSpritePosition("shengli4",0,0);
        blood=1000;
}
if(blood<=0&&level==4)
{
       dDeleteSprite("zuiqiang");
       dSetSpritePosition("shibai7",0,0);
       dSetSpritePosition("review10",2,15);
}
if(boss1hp<=0&&level==2)
    {
        dDeleteSprite("boss1");
        dDeleteSprite("dadao");
        dSetSpritePosition("texiao1",0,-0.554);
       dSetSpritePosition("shengli1",-1.170,-2.500);
        dSetSpritePosition("next3",3.682,2.525);
        dSetSpritePosition("moxing1",-9.567,2.123);
        dSetSpritePosition("levelup1",-33.257,-1.385);
    }
//�ؿ����̺���
if(nandian==2)
    dSetSpritePosition("dierzhang",-0.375,-5.813);
if (nandian==3)
{
    dSetSpritePosition("disanzhang",-0.375,4.188);
    dSetSpritePosition("dierzhang",-0.375,-5.813);
}

if (nandian==4)
{
    dSetSpritePosition("disizhang",-0.375,14.187);
    dSetSpritePosition("disanzhang",-0.375,4.188);
    dSetSpritePosition("dierzhang",-0.375,-5.813);
}
	};

	// �ر���Ϸ����
	dShutdownGameEngine();
	return 0;
}


//==========================================================================
//
// ���沶׽����ƶ���Ϣ�󣬽����õ�������
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
//
void dOnMouseMove( const float fMouseX, const float fMouseY )
{
    dSetSpritePosition("shubiao", fMouseX, fMouseY);
    int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    a=dIsPointInSprite("nextpage6",fMouseX,fMouseY);
    if(a==1)
    {
        dSetSpritePosition( "nextpage3", PositionX22,PositionY22);

    }
    else
        dSetSpritePosition( "nextpage3", -285.709,6.776);

    b=dIsPointInSprite("nextpage1",fMouseX,fMouseY);
    if(b==1)
         dSetSpritePosition( "nextpage2", PositionX23, PositionY23);
    else
        dSetSpritePosition( "nextpage2", -285.709,6.776);
    c=dIsPointInSprite("exit",fMouseX,fMouseY);
    if(c==1)
         dSetSpritePosition( "exit1",PositionX21, PositionY21);
    else
        dSetSpritePosition( "exit1", -285.709,6.776);
    d=dIsPointInSprite("kaishi",fMouseX,fMouseY);
    if(d==1)
        dSetSpritePosition( "kaishi1", 30.375, -5.813);
    else
        dSetSpritePosition( "kaishi1", -285.709,6.776);
    e=dIsPointInSprite("bangzhu",fMouseX,fMouseY);
        if(e==1)
        dSetSpritePosition( "bangzhu1", 30.375, 24.188);
    else
        dSetSpritePosition( "bangzhu1", -285.709,6.776);
    f=dIsPointInSprite("women",fMouseX,fMouseY);
        if(f==1)
        dSetSpritePosition( "women1", 30.375, 14.188);
    else
        dSetSpritePosition( "women1", -285.709,6.776);
    g=dIsPointInSprite("jianjie",fMouseX,fMouseY);
        if(g==1)
        dSetSpritePosition( "jianjie1",PositionX20, PositionY20);
    else
        dSetSpritePosition( "jianjie1", -285.709,6.776);
    h=dIsPointInSprite("exit2",fMouseX,fMouseY);
        if(h==1)
        dSetSpritePosition( "exit3",-26.967, 21.645);
    else
        dSetSpritePosition( "exit3", -285.709,6.776);
    i=dIsPointInSprite("nextpage4",fMouseX,fMouseY);
        if(i==1)
        dSetSpritePosition( "nextpage5",-13.618, 21.729);
    else
        dSetSpritePosition( "nextpage5", -285.709,6.776);
    j=dIsPointInSprite("exit4",fMouseX,fMouseY);
        if(j==1)
        dSetSpritePosition( "exit5",-20,22.5);
    else
        dSetSpritePosition( "exit5", -285.709,6.776);
    k=dIsPointInSprite("diyizhang",fMouseX,fMouseY);
        if(k==1)
        dSetSpritePosition( "diyizhang1",-0.375, -14.188);
    else
        dSetSpritePosition( "diyizhang1", -285.709,6.776);
    l=dIsPointInSprite("dierzhang",fMouseX,fMouseY);
        if(l==1)
        dSetSpritePosition( "dierzhang1",-0.375, -5.813);
    else
        dSetSpritePosition( "dierzhang1", -285.709,6.776);
    m=dIsPointInSprite("disanzhang",fMouseX,fMouseY);
        if(m==1)
        dSetSpritePosition( "disanzhang1",-0.375,4.188);
    else
        dSetSpritePosition( "disanzhang1", -285.709,6.776);
    n=dIsPointInSprite("disizhang",fMouseX,fMouseY);
        if(n==1)
        dSetSpritePosition( "disizhang1",-0.375, 14.187);
    else
        dSetSpritePosition( "disizhang1", -285.709,6.776);
    o=dIsPointInSprite("fanhui",fMouseX,fMouseY);
        if(o==1)
        dSetSpritePosition( "fanhui1",45.093, -33.564);
    else
        dSetSpritePosition( "fanhui1", -285.709,6.776);
    p=dIsPointInSprite("fanhui2",fMouseX,fMouseY);
        if(p==1)
        dSetSpritePosition( "fanhui3",39.875, 31.622);
    else
        dSetSpritePosition( "fanhui3", -285.709,6.776);
    q=dIsPointInSprite("next",fMouseX,fMouseY);
        if(q==1)
        dSetSpritePosition( "next1",PositionX4, PositionY4);
    else
        dSetSpritePosition( "next1", -285.709,6.776);
    r=dIsPointInSprite("review",fMouseX,fMouseY);
        if(r==1)
        dSetSpritePosition( "review1",PositionX9, PositionY9);
    else
        dSetSpritePosition( "review1", -285.709,6.776);
    s=dIsPointInSprite("review2",fMouseX,fMouseY);
        if(s==1)
        dSetSpritePosition( "review3",PositionX10, PositionY10);
    else
        dSetSpritePosition( "review3", -285.709,6.776);
    t=dIsPointInSprite("next3",fMouseX,fMouseY);
        if(t==1)
        dSetSpritePosition( "next4",PositionX11, PositionY11);
    else
        dSetSpritePosition( "next4", -285.709,6.776);
    u=dIsPointInSprite("fanhui6",fMouseX,fMouseY);
        if(u==1)
        dSetSpritePosition( "fanhui7",PositionX13, PositionY13);
    else
        dSetSpritePosition( "fanhui7", -285.709,6.776);
    v=dIsPointInSprite("review3",fMouseX,fMouseY);
        if(v==1)
        dSetSpritePosition( "review4",PositionX14, PositionY14);
    else
        dSetSpritePosition( "review4", -285.709,6.776);
    w=dIsPointInSprite("next5",fMouseX,fMouseY);
        if(w==1)
        dSetSpritePosition( "next6",PositionX15, PositionY15);
    else
        dSetSpritePosition( "next6", -285.709,6.776);
    x=dIsPointInSprite("fanhui10",fMouseX,fMouseY);
        if(x==1)
        dSetSpritePosition( "fanhui11",PositionX16, PositionY16);
    else
        dSetSpritePosition( "fanhui11", -285.709,6.776);
    y=dIsPointInSprite("wotui",fMouseX,fMouseY);
        if(y==1)
        dSetSpritePosition( "wotui1",PositionX17, PositionY17);
    else
        dSetSpritePosition( "wotui1", -285.709,6.776);
    z=dIsPointInSprite("review10",fMouseX,fMouseY);
        if(z==1)
        dSetSpritePosition( "review11",PositionX18, PositionY18);
    else
        dSetSpritePosition( "review11", -285.709,6.776);
	// �����ڴ������Ϸ��Ҫ����Ӧ����
	OnMouseMove(fMouseX, fMouseY );
}
//==========================================================================
//
// ���沶׽�������Ϣ�󣬽����õ�������
// ���� iMouseType����갴��ֵ���� enum MouseTypes ����
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
//
void dOnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{
    //���������
    dPlaySound("BLIP.wav",0,0.3);
    dSetSpriteVisible( "shubiao1", 1);
    dSetSpritePosition("shubiao1",PositionX5,PositionY5);
    dSetSpriteVisible( "shubiao", 0);


    int click1,click2,click3,click4,click5,click6,click7,click8,click9,click10,click11,click12,click13,click14,click15,click16,click17,click18,click19,click20,click21,click22,click23,click24,click25,click26;
    int click27,click28,click29,click30,click31,click32,click33,click34,click35,click36,click37,click38,click39;
	OnMouseClick(iMouseType, fMouseX, fMouseY);

    click1=dIsPointInSprite("kaishi",fMouseX,fMouseY);
    if(click1==1&&iMouseType==MOUSE_LEFT)
    {
        dLoadMap("levellevel.t2d");
    }
    click2=dIsPointInSprite("jianjie",fMouseX,fMouseY);
    if(click2==1&&iMouseType==0)
    {
        dSetSpritePosition("jianjieyi",0.079,-0.068);
        dSetSpritePosition("jianjieer",0,-0.221);
        dSetSpritePosition("jianjiesan",0,-0.136);
        dSpriteMoveTo( "exit",-20.625, 25.234, 80, 1 );
        dSpriteMoveTo( "nextpage6", -32.856,17.856, 80, 1 );
    }
    click3=dIsPointInSprite("diyizhang",fMouseX,fMouseY);
    if(click3==1&&iMouseType==0)
    {
       dLoadMap("nandian1.t2d");
       level=1;
       blood=1;
    }
    click4=dIsPointInSprite("dierzhang",fMouseX,fMouseY);
    if(click4==1&&iMouseType==0)
    {
       dLoadMap("nandian2.t2d");
       level=2;
       blood=1;
       boss1hp=150;
       shengyu=10;
    }
    click5=dIsPointInSprite("disanzhang",fMouseX,fMouseY);
    if(click5==1&&iMouseType==0)
    {
      dLoadMap("nandian3.t2d");
      level=3;
      blood=1;
      nengliang=100;
      boss22hp=200;
      g_chengqiang=10;
    }
     click6=dIsPointInSprite("disizhang",fMouseX,fMouseY);
    if(click6==1&&iMouseType==0)
    {
       dLoadMap("nandian4.t2d");
       level=4;
       blood=5;
       nengliang=100;
       boss3hp=500;
    }
    click7=dIsPointInSprite("exit",fMouseX,fMouseY);
    if(click7==1&&iMouseType==0)
    {
       dSetSpritePosition("exit",-114.625,28.234);
       dSetSpritePosition("nextpage6",-75.375,28.272);
       dSetSpritePosition("jianjieyi",-192.688,8.592);
       dSetSpritePosition("jianjieer",-192.372,8.387);
       dSetSpritePosition("jianjiesan",-285.709,6.776);
    }

    click8=dIsPointInSprite("nextpage6",fMouseX,fMouseY);
    if(click8==1&&iMouseType==0)
    {
        dSetSpritePosition("jianjieyi",-197.688,8.592);
        dSetSpritePosition("nextpage6",-75.375,28.272);
        dSetSpritePosition( "nextpage1", -32.637, 24.300 );


    }
    click9=dIsPointInSprite("nextpage1",fMouseX,fMouseY);
    if(click9==1&&iMouseType==0)
    {
        dSetSpritePosition("jianjieer",-192.372,8.387);
        dSetSpritePosition( "nextpage1", -75.375,28.272 );
    }
    click10=dIsPointInSprite("women",fMouseX,fMouseY);
    if(click10==1&&iMouseType==0)
    {
        dSetSpritePosition("women2",0,0);
        dSetSpritePosition( "women3",0,0 );
        dSetSpritePosition("nextpage4",-13.618,21.729);
        dSetSpritePosition("exit2",-26.967,21.645);
    }
    click11=dIsPointInSprite("nextpage4",fMouseX,fMouseY);
    if(click11==1&&iMouseType==0)
    {
        dSetSpritePosition("women2",-192.372,8.387);
        dSetSpritePosition("nextpage4",-192.372,8.387);
    }
    click12=dIsPointInSprite("exit2",fMouseX,fMouseY);
    if(click12==1&&iMouseType==0)
    {
        dSetSpritePosition("exit2",-192.372,8.387);
        dSetSpritePosition("women3",-192.372,8.387);
        dSetSpritePosition("women2",-192.372,8.387);
        dSetSpritePosition("nextpage4",-192.372,8.387);
    }
    click13=dIsPointInSprite("bangzhu",fMouseX,fMouseY);
    if(click13==1&&iMouseType==0)
    {
        dSetSpritePosition("bangzhu2",1.032,0.728);
    }
    click14=dIsPointInSprite("exit4",fMouseX,fMouseY);
    if(click14==1&&iMouseType==0)
    {
        dSetSpritePosition("bangzhu2",-192.372,8.387);
        dSetSpritePosition("exit4",-192.372,8.387);
    }
    click15=dIsPointInSprite("fanhui",fMouseX,fMouseY);
    if(click15==1&&iMouseType==0)
    {
        dLoadMap("levellevel.t2d");
    }
    click16=dIsPointInSprite("fanhui2",fMouseX,fMouseY);
    if(click16==1&&iMouseType==0)
    {
        dLoadMap("level0.t2d");
    }
    click17=dIsPointInSprite("next",fMouseX,fMouseY);
    if(click17==1&&iMouseType==0)
    {
        dLoadMap("nandian2.t2d");
        level=2;
        nandian=2;
    }
    click18=dIsPointInSprite("review",fMouseX,fMouseY);
    if(click18==1&&iMouseType==0)
    {
        dLoadMap("level1.t2d");
        blood=1;
    }
    click19=dIsPointInSprite("review2",fMouseX,fMouseY);
    if(click19==1&&iMouseType==0)
    {
        blood=1;
        dLoadMap("level2.t2d");
        shengyu=10;
        boss1hp=150;
        dSetTextValue("shengyu",shengyu);
        dSetTextValue("boss1hp",boss1hp);
    }
    click20=dIsPointInSprite("next3",fMouseX,fMouseY);
    if(click20==1&&iMouseType==0)
    {
        level=3;
        dLoadMap("nandian3.t2d");
        blood=1;
        nengliang=100;
        nandian=3;
    }
    click21=dIsPointInSprite("fanhui6",fMouseX,fMouseY);
    if(click21==1&&iMouseType==0)
    {
        dLoadMap("levellevel.t2d");
    }
    click22=dIsPointInSprite("next5",fMouseX,fMouseY);
    if(click22==1&&iMouseType==0)
    {
        dLoadMap("nandian4.t2d");
        level=4;
        blood=5;
        nengliang=100;
        nandian=4;

    }
    click23=dIsPointInSprite("review3",fMouseX,fMouseY);
    if(click23==1&&iMouseType==0)
    {
        dLoadMap("level3.t2d");
        boss22hp=200;
        nengliang=100;
        blood=1;
        g_chengqiang=10;
    }
    click24=dIsPointInSprite("fanhui10",fMouseX,fMouseY);
    if(click24==1&&iMouseType==0)
    {
        dLoadMap("levellevel.t2d");
    }
    click25=dIsPointInSprite("wotui",fMouseX,fMouseY);
    if(click25==1&&iMouseType==0)
    {
        dLoadMap("level0.t2d");
    }
    click26=dIsPointInSprite("review10",fMouseX,fMouseY);
    if(click26==1&&iMouseType==0)
    {
        dLoadMap("level4.t2d");
        blood=5;
        nengliang=100;
        boss3hp=500;
    }
    click27=dIsPointInSprite("shengyin",fMouseX,fMouseY);
    if(click27==1&&iMouseType==0)
    {
       dStopAllSound();
       dSetSpritePosition("shengyin",-200,30);
       dDeleteSprite("shengyin");
       dSetSpritePosition("jingyin",37.457,-33.587);
    }
    click28=dIsPointInSprite("jingyin",fMouseX,fMouseY);
    if(click28==1&&iMouseType==0)
    {
       dPlaySound("qw.ogg",1,1);
       dLoadMap("level0.t2d");
       dSetSpritePosition("jingyin",-200,30);
    }
}
//==========================================================================
//
// ���沶׽��굯����Ϣ�󣬽����õ�������
// ���� iMouseType����갴��ֵ���� enum MouseTypes ����
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
//
void dOnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{
    //�������̧����
dSetSpriteVisible( "shubiao", 1);
dSetSpriteVisible( "shubiao1", 0);
	OnMouseUp(iMouseType, fMouseX, fMouseY);

}
//==========================================================================
//
// ���沶׽���̰�����Ϣ�󣬽����õ�������
// ���� iKey�������µļ���ֵ�� enum KeyCodes �궨��
// ���� iAltPress, iShiftPress��iCtrlPress�������ϵĹ��ܼ�Alt��Ctrl��Shift��ǰ�Ƿ�Ҳ���ڰ���״̬(0δ���£�1����)
//
void dOnKeyDown( const int iKey, const int iAltPress, const int iShiftPress, const int iCtrlPress )
{
    //�ؿ�ѡ��
    if(iKey==KEY_ENTER)
    {
        if(level==1)
        {
             dLoadMap("level1.t2d");
             blood=1;
             level=1;
        }

        if(level==2)
        {
            dLoadMap("level2.t2d");
            blood=1;
            shengyu=10;
            boss1hp=150;
            level=2;
        }

        if(level==3)
        {
            blood=1;
            g_chengqiang=10;
            boss22hp=200;
            dLoadMap("level3.t2d");
            level=3;
            nengliang=100;
        }

        if(level==4)
        {
            dLoadMap("level4.t2d");
            level=4;
            boss3hp=500;
            nengliang=100;
            blood=5;
        }

    }
    //��һ����Ч����
    int a;
    a=dIsPointInSprite("baoxiang",PositionX2,PositionY2);
    if(a==1&&iKey==KEY_W)
    {
        dDeleteSprite("baoxiang");
        dSetSpritePosition("kaixiang", PositionX1, PositionY1);
        dSetSpritePosition("huohua", PositionX1, PositionY1);
        dDeleteSprite("zuoguai");
        dSetSpritePosition("texiao",0,0.087);
       dSetSpritePosition("shengli",0.252,0.976);
        dSetSpritePosition("next",12.250,10.851);
        dSetSpritePosition("moxing",-11.117,10.823);
        dPlaySound("shengli.ogg",0,0.5);
        dSetSpritePosition("levelup",PositionX1-1,PositionY1-9);
    }
    if(level==1&&iKey==KEY_SPACE&&damenweizhiX<=-29.000&&damenweizhiX>=-32.000)
    {
        dSetSpritePosition("damen",-192.372,8.387);
        dPlaySound("chuaimen.ogg",0,0.5);
        dDeleteSprite("kongge");
    }

    //�����ƶ�
    switch(iKey)
	{
    case KEY_A:
        bFilp=true;
        g_fSpeedLeft=-20.f;

dSetSpriteLinearVelocityX("ditu1",10);
ditu1=dGetSpriteLinearVelocityX("ditu1");
if(ditu1==10)
{
dSetSpriteLinearVelocityX("tukuai2",10);
        dSetSpriteLinearVelocityX("tukuai1",10);
        dSetSpriteLinearVelocityX("tukuai3",10);
        dSetSpriteLinearVelocityX("tukuai4",10);
        dSetSpriteLinearVelocityX("tukuai5",10);
        dSetSpriteLinearVelocityX("barrier1",10);
        dSetSpriteLinearVelocityX("shitou",10);
        dSetSpriteLinearVelocityX("baikuang",10);
        dSetSpriteLinearVelocityX("baoxiang",10);
        dSetSpriteLinearVelocityX("barrier5",10);
        dSetSpriteLinearVelocityX("barrier2",10);
        dSetSpriteLinearVelocityX("barrier3",10);
        dSetSpriteLinearVelocityX("barrier4",10);
        dSetSpriteLinearVelocityX("kaimen",10);
        dSetSpriteLinearVelocityX("damen",10);
        dSetSpriteLinearVelocityX("jianshou1",10);
        dSetSpriteLinearVelocityX("jianshou2",10);
        dSetSpriteLinearVelocityX("jianshou3",10);
        dSetSpriteLinearVelocityX("baikuang1",10);
        dSetSpriteLinearVelocityX("jianyu16",10);
        dSetSpriteLinearVelocityX("jianyu17",10);
        dSetSpriteLinearVelocityX("jianyu18",10);
        dSetSpriteLinearVelocityX("jianyu19",10);

}
else
        {
            dSetSpriteLinearVelocityX("tukuai2",0);
        dSetSpriteLinearVelocityX("tukuai1",0);
        dSetSpriteLinearVelocityX("tukuai3",0);
        dSetSpriteLinearVelocityX("tukuai4",0);
        dSetSpriteLinearVelocityX("tukuai5",0);
        dSetSpriteLinearVelocityX("barrier1",0);
        dSetSpriteLinearVelocityX("jianyu16",0);
        dSetSpriteLinearVelocityX("jianyu17",0);
        dSetSpriteLinearVelocityX("jianyu18",0);
        dSetSpriteLinearVelocityX("jianyu19",0);
        }
        break;
    case KEY_D:
        g_fSpeedRight=20.f;

        dSetSpriteLinearVelocityX("ditu1",-10);
        ditu1=dGetSpriteLinearVelocityX("ditu1");
        if(ditu1==-10)
        {
        dSetSpriteLinearVelocityX("tukuai2",-10);
        dSetSpriteLinearVelocityX("tukuai1",-10);
        dSetSpriteLinearVelocityX("tukuai3",-10);
        dSetSpriteLinearVelocityX("tukuai4",-10);
        dSetSpriteLinearVelocityX("tukuai5",-10);
        dSetSpriteLinearVelocityX("barrier1",-10);
        dSetSpriteLinearVelocityX("shitou",-10);
        dSetSpriteLinearVelocityX("baikuang",-10);
        dSetSpriteLinearVelocityX("baoxiang",-10);
        dSetSpriteLinearVelocityX("barrier5",-10);
        dSetSpriteLinearVelocityX("barrier2",-10);
        dSetSpriteLinearVelocityX("barrier3",-10);
        dSetSpriteLinearVelocityX("barrier4",-10);
        dSetSpriteLinearVelocityX("kaimen",-10);
        dSetSpriteLinearVelocityX("damen",-10);
        dSetSpriteLinearVelocityX("jianshou1",-10);
        dSetSpriteLinearVelocityX("jianshou2",-10);
        dSetSpriteLinearVelocityX("jianshou3",-10);
        dSetSpriteLinearVelocityX("baikuang1",-10);
        dSetSpriteLinearVelocityX("jianyu16",-10);
        dSetSpriteLinearVelocityX("jianyu17",-10);
        dSetSpriteLinearVelocityX("jianyu18",-10);
        dSetSpriteLinearVelocityX("jianyu19",-10);
        }
        else
        {
            dSetSpriteLinearVelocityX("tukuai2",0);
        dSetSpriteLinearVelocityX("tukuai1",0);
        dSetSpriteLinearVelocityX("tukuai3",0);
        dSetSpriteLinearVelocityX("tukuai4",0);
        dSetSpriteLinearVelocityX("tukuai5",0);
        dSetSpriteLinearVelocityX("barrier1",0);
        dSetSpriteLinearVelocityX("jianyu16",0);
        dSetSpriteLinearVelocityX("jianyu17",0);
        dSetSpriteLinearVelocityX("jianyu18",0);
        dSetSpriteLinearVelocityX("jianyu19",0);
        }
        break;
        //��ͨ����
    case KEY_J:
        if(level==2||level==3||level==4)
        {
        dPlaySound("attack.ogg",0,0.3);
        dSetSpriteFlipX("huidao",bFilp);
        dSetSpritePosition("huidao",PositionX8,PositionY8);
        dSetSpriteVisible( "huidao",  1);
        dSetSpriteVisible( "dadao",  0);
        dSetSpriteFlipX("pugong",bFilp);
        dSetSpritePosition("pugong",PositionX12,PositionY12);
        dSetSpriteVisible( "pugong",  1);
        dSetSpriteVisible( "zuiqiang",  0);
        }
        break;
        //���ܼ�λ�õ��ؼ���
    case KEY_K:
        if(level==1)
       {
       g_fSpeedBottom=-10;
       }
       else if(level==2&&shengyu>0)
       {
           dPlaySound("feibiao.ogg",0,1);
           char *s;
		s = dMakeSpriteName("feibiao_%d", g_iNu++);		//�õ��ڵ�����
		dCloneSprite("feibiao_muban",s);		//�����ڵ�ģ��
		dSetSpritePosition(s,PositionX8, PositionY8);
            int pp=dGetSpriteFlipX( "dadao");
            if(pp==1)
            {
                dSetSpriteLinearVelocity(s,40,0);
            }
            if(pp==0)
            {
                dSetSpriteLinearVelocity(s,-40,0);
            }
        shengyu--;
          dSetTextValue("shengyu",shengyu);
       }

        break;
        //ESC����
    case KEY_ESCAPE:
        dLoadMap("level0.t2d");
        break;
        //���������ƶ�
    case KEY_W:
        if(level!=1)
        {
            g_fSpeedBottom=-20;
        }
        break;
    case KEY_S:
        if(level!=1)
        {
            g_fSpeedBottom=20;
        }
        break;
        //���＼��
    case KEY_L:
if(nengliang>=30)
{
            nengliang-=30;
            dSetTextValue("nengliang",nengliang);
            dSetSpritePosition("dazhao",-89.375,3.157);
            dSetSpriteLinearVelocityX("dazhao",25);
            dPlaySound("shandian",0,0.5);
}
        break;
    case KEY_I:
        if(nengliang>=1)
        {
            nengliang=nengliang-2;
            dSetTextValue("nengliang",nengliang);
            dPlaySound("zi.ogg",0,0.3);
		    char *szName;
		szName = dMakeSpriteName("paodan_%d", g_iNum++);		//�õ��ڵ�����
		dCloneSprite("paodan_muban",szName);		//�����ڵ�ģ��
		dSetSpritePosition(szName,PositionX12, PositionY12);
		dSetSpriteLinearVelocityX(szName,35);
        }

        break;
    case KEY_O:
            if(nengliang>=5&&level==4)
            {
                nengliang-=5;
                blood++;
                dPlaySound("huifu.ogg",0,0.5);
                dSetSpritePosition("baohu",PositionX12,PositionY12);
                dSetSpriteVisible("baohu",1);
                dSetTextValue("blood",blood);
                 dSetTextValue("nengliang",nengliang);
            }
      break;
	}
        if((g_fSpeedLeft+g_fSpeedRight)>0)
    {

        bFilp=true;
    }
        if((g_fSpeedLeft+g_fSpeedRight)<0)
        {
            bFilp=false;
        }
	dSetSpriteFlipX("dadao",bFilp);
	dSetSpriteLinearVelocity("dadao",g_fSpeedLeft+g_fSpeedRight,g_fSpeedTop+g_fSpeedBottom);
	dSetSpriteFlipX("zuoguai",bFilp);
	dSetSpriteLinearVelocity("zuoguai",g_fSpeedLeft+g_fSpeedRight,g_fSpeedTop+g_fSpeedBottom);
	dSetSpriteFlipX("zuiqiang",bFilp);
	dSetSpriteLinearVelocity("zuiqiang",g_fSpeedLeft+g_fSpeedRight,g_fSpeedTop+g_fSpeedBottom);
	// �����ڴ������Ϸ��Ҫ����Ӧ����
	OnKeyDown(iKey, iAltPress, iShiftPress, iCtrlPress);
}
//==========================================================================
//
// ���沶׽���̵�����Ϣ�󣬽����õ�������
// ���� iKey������ļ���ֵ�� enum KeyCodes �궨��
//
void dOnKeyUp( const int iKey )
{
    // �����ƶ�

	switch(iKey)
	{
    case KEY_A:
        g_fSpeedLeft=0.f;
        dSetSpriteLinearVelocityX("ditu1",0);
        dSetSpriteLinearVelocityX("tukuai2",0);
        dSetSpriteLinearVelocityX("tukuai1",0);
        dSetSpriteLinearVelocityX("tukuai3",0);
        dSetSpriteLinearVelocityX("tukuai4",0);
        dSetSpriteLinearVelocityX("tukuai5",0);
        dSetSpriteLinearVelocityX("barrier1",0);
        dSetSpriteLinearVelocityX("shitou",0);
        dSetSpriteLinearVelocityX("baikuang",0);
        dSetSpriteLinearVelocityX("baoxiang",0);
        dSetSpriteLinearVelocityX("barrier5",0);
        dSetSpriteLinearVelocityX("barrier2",0);
        dSetSpriteLinearVelocityX("barrier3",0);
        dSetSpriteLinearVelocityX("barrier4",0);
        dSetSpriteLinearVelocityX("kaimen",0);
        dSetSpriteLinearVelocityX("damen",0);
        dSetSpriteLinearVelocityX("jianshou1",0);
        dSetSpriteLinearVelocityX("jianshou2",0);
        dSetSpriteLinearVelocityX("jianshou3",0);
        dSetSpriteLinearVelocityX("baikuang1",0);
        dSetSpriteLinearVelocityX("jianyu16",0);
        dSetSpriteLinearVelocityX("jianyu17",0);
        dSetSpriteLinearVelocityX("jianyu18",0);
        dSetSpriteLinearVelocityX("jianyu19",0);
        break;
    case KEY_D:
        g_fSpeedRight=0.f;
        dSetSpriteLinearVelocityX("shitou",0);
        dSetSpriteLinearVelocityX("baikuang",0);
        dSetSpriteLinearVelocityX("baikuang1",0);
        dSetSpriteLinearVelocityX("baoxiang",0);
        dSetSpriteLinearVelocityX("barrier5",0);
        dSetSpriteLinearVelocityX("barrier2",0);
        dSetSpriteLinearVelocityX("barrier3",0);
        dSetSpriteLinearVelocityX("barrier4",0);
        dSetSpriteLinearVelocityX("kaimen",0);
        dSetSpriteLinearVelocityX("damen",0);
        dSetSpriteLinearVelocityX("jianshou1",0);
        dSetSpriteLinearVelocityX("jianshou2",0);
        dSetSpriteLinearVelocityX("jianshou3",0);
        dSetSpriteLinearVelocityX("ditu1",0);
        dSetSpriteLinearVelocityX("tukuai2",0);
        dSetSpriteLinearVelocityX("tukuai1",0);
        dSetSpriteLinearVelocityX("tukuai3",0);
        dSetSpriteLinearVelocityX("tukuai4",0);
        dSetSpriteLinearVelocityX("tukuai5",0);
        dSetSpriteLinearVelocityX("barrier1",0);
        dSetSpriteLinearVelocityX("jianyu16",0);
        dSetSpriteLinearVelocityX("jianyu17",0);
        dSetSpriteLinearVelocityX("jianyu18",0);
        dSetSpriteLinearVelocityX("jianyu19",0);
        break;
        case  KEY_K:
            if(level==1)
            {
                g_fSpeedBottom=10;
            }
            break;
            if(level!=1)
            {
        case KEY_W:
        {
            g_fSpeedBottom=0;
            break;
        }
    case KEY_S:
        {
            g_fSpeedBottom=0;
            break;
        }
    case KEY_J:
        dSetSpritePosition("huidao",-200,600);
        dSetSpriteVisible( "huidao",  0);
        dSetSpriteVisible( "dadao",  1);
        dSetSpritePosition("pugong",-200,600);
        dSetSpriteVisible( "pugong",  0);
        dSetSpriteVisible( "zuiqiang",  1);
        break;
    case KEY_O:
        dSetSpriteVisible("baohu",0);
        break;
               }

	}
	if((g_fSpeedLeft+g_fSpeedRight)>0)
    {

        bFilp=true;
    }
    else
    {
        if((g_fSpeedLeft+g_fSpeedRight)<0)
        {
            bFilp=false;
        }
    }
    dSetSpriteFlipX("zuoguai",bFilp);
	dSetSpriteLinearVelocity("zuoguai",g_fSpeedLeft+g_fSpeedRight,g_fSpeedTop+g_fSpeedBottom);
	dSetSpriteFlipX("dadao",bFilp);
	dSetSpriteLinearVelocity("dadao",g_fSpeedLeft+g_fSpeedRight,g_fSpeedTop+g_fSpeedBottom);
	dSetSpriteFlipX("zuiqiang",bFilp);
	dSetSpriteLinearVelocity("zuiqiang",g_fSpeedLeft+g_fSpeedRight,g_fSpeedTop+g_fSpeedBottom);
	// �����ڴ������Ϸ��Ҫ����Ӧ����
	OnKeyUp(iKey);
}

//===========================================================================
//
// ���沶׽�������뾫����ײ֮�󣬵��ô˺���
// ����֮��Ҫ������ײ�������ڱ༭�����ߴ��������þ��鷢�ͼ�������ײ
// ���� szSrcName��������ײ�ľ�������
// ���� szTarName������ײ�ľ�������
//
void dOnSpriteColSprite( const char *szSrcName, const char *szTarName )
{

    if(stricmp("zuoguai",szSrcName)==0 && stricmp("tukuai1",szTarName)==0)
   {
       g_fSpeedTop=0;
       g_fSpeedBottom=0;
       g_fSpeedLeft=0;
       g_fSpeedRight=0;
       dSetSpriteLinearVelocity("zuoguai",g_fSpeedLeft+g_fSpeedRight,g_fSpeedTop+g_fSpeedBottom);
       dSetSpriteLinearVelocityX("ditu1",0);
        dSetSpriteLinearVelocityX("tukuai2",0);
        dSetSpriteLinearVelocityX("tukuai1",0);
        dSetSpriteLinearVelocityX("tukuai3",0);
        dSetSpriteLinearVelocityX("tukuai4",0);
        dSetSpriteLinearVelocityX("tukuai5",0);
        dSetSpriteLinearVelocityX("barrier1",0);
        dSetSpriteLinearVelocityX("shitou",0);
        dSetSpriteLinearVelocityX("baikuang",0);
        dSetSpriteLinearVelocityX("baoxiang",0);
        dSetSpriteLinearVelocityX("barrier5",0);
        dSetSpriteLinearVelocityX("barrier2",0);
        dSetSpriteLinearVelocityX("barrier3",0);
        dSetSpriteLinearVelocityX("barrier4",0);
        dSetSpriteLinearVelocityX("kaimen",0);
        dSetSpriteLinearVelocityX("damen",0);
        dSetSpriteLinearVelocityX("jianshou1",0);
        dSetSpriteLinearVelocityX("jianshou2",0);
        dSetSpriteLinearVelocityX("jianshou3",0);
        dSetSpriteLinearVelocityX("baikuang1",0);
        dSetSpriteLinearVelocityX("jianyu16",0);
        dSetSpriteLinearVelocityX("jianyu17",0);
        dSetSpriteLinearVelocityX("jianyu18",0);
        dSetSpriteLinearVelocityX("jianyu19",0);

   }
if(stricmp("zuoguai",szSrcName)==0 && stricmp("tukuai2",szTarName)==0)
   {
       g_fSpeedLeft=0;
       g_fSpeedRight=0;
       g_fSpeedTop=0;
       g_fSpeedBottom=0;
       dSetSpriteLinearVelocity("zuoguai",g_fSpeedLeft+g_fSpeedRight,g_fSpeedTop+g_fSpeedBottom);
       dSetSpriteLinearVelocityX("ditu1",0);
        dSetSpriteLinearVelocityX("tukuai2",0);
        dSetSpriteLinearVelocityX("tukuai1",0);
        dSetSpriteLinearVelocityX("tukuai3",0);
        dSetSpriteLinearVelocityX("tukuai4",0);
        dSetSpriteLinearVelocityX("tukuai5",0);
        dSetSpriteLinearVelocityX("barrier1",0);
        dSetSpriteLinearVelocityX("shitou",0);
        dSetSpriteLinearVelocityX("baikuang",0);
        dSetSpriteLinearVelocityX("baoxiang",0);
        dSetSpriteLinearVelocityX("barrier5",0);
        dSetSpriteLinearVelocityX("barrier2",0);
        dSetSpriteLinearVelocityX("barrier3",0);
        dSetSpriteLinearVelocityX("barrier4",0);
        dSetSpriteLinearVelocityX("kaimen",0);
        dSetSpriteLinearVelocityX("damen",0);
        dSetSpriteLinearVelocityX("jianshou1",0);
        dSetSpriteLinearVelocityX("jianshou2",0);
        dSetSpriteLinearVelocityX("jianshou3",0);
        dSetSpriteLinearVelocityX("baikuang1",0);
        dSetSpriteLinearVelocityX("jianyu16",0);
        dSetSpriteLinearVelocityX("jianyu17",0);
        dSetSpriteLinearVelocityX("jianyu18",0);
        dSetSpriteLinearVelocityX("jianyu19",0);
          }
   if(stricmp("zuoguai",szSrcName)==0 && stricmp("tukuai3",szTarName)==0)
   {
       g_fSpeedLeft=0;
       g_fSpeedRight=0;
       g_fSpeedTop=0;
       g_fSpeedBottom=0;
       dSetSpriteLinearVelocity("zuoguai",g_fSpeedLeft+g_fSpeedRight,g_fSpeedTop+g_fSpeedBottom);
       dSetSpriteLinearVelocityX("ditu1",0);
        dSetSpriteLinearVelocityX("tukuai2",0);
        dSetSpriteLinearVelocityX("tukuai1",0);
        dSetSpriteLinearVelocityX("tukuai3",0);
        dSetSpriteLinearVelocityX("tukuai4",0);
        dSetSpriteLinearVelocityX("tukuai5",0);
        dSetSpriteLinearVelocityX("barrier1",0);
        dSetSpriteLinearVelocityX("shitou",0);
        dSetSpriteLinearVelocityX("baikuang",0);
        dSetSpriteLinearVelocityX("baoxiang",0);
        dSetSpriteLinearVelocityX("barrier5",0);
        dSetSpriteLinearVelocityX("barrier2",0);
        dSetSpriteLinearVelocityX("barrier3",0);
        dSetSpriteLinearVelocityX("barrier4",0);
        dSetSpriteLinearVelocityX("kaimen",0);
        dSetSpriteLinearVelocityX("damen",0);
        dSetSpriteLinearVelocityX("jianshou1",0);
        dSetSpriteLinearVelocityX("jianshou2",0);
        dSetSpriteLinearVelocityX("jianshou3",0);
        dSetSpriteLinearVelocityX("baikuang1",0);
        dSetSpriteLinearVelocityX("jianyu16",0);
        dSetSpriteLinearVelocityX("jianyu17",0);
        dSetSpriteLinearVelocityX("jianyu18",0);
        dSetSpriteLinearVelocityX("jianyu19",0);
   }
   if(stricmp("zuoguai",szSrcName)==0 && stricmp("tukuai4",szTarName)==0)
   {
       g_fSpeedLeft=0;
       g_fSpeedRight=0;
       g_fSpeedTop=0;
       g_fSpeedBottom=0;
       dSetSpriteLinearVelocity("zuoguai",g_fSpeedLeft+g_fSpeedRight,g_fSpeedTop+g_fSpeedBottom);
       dSetSpriteLinearVelocityX("ditu1",0);
        dSetSpriteLinearVelocityX("tukuai2",0);
        dSetSpriteLinearVelocityX("tukuai1",0);
        dSetSpriteLinearVelocityX("tukuai3",0);
        dSetSpriteLinearVelocityX("tukuai4",0);
        dSetSpriteLinearVelocityX("tukuai5",0);
        dSetSpriteLinearVelocityX("barrier1",0);
        dSetSpriteLinearVelocityX("shitou",0);
        dSetSpriteLinearVelocityX("baikuang",0);
        dSetSpriteLinearVelocityX("baoxiang",0);
        dSetSpriteLinearVelocityX("barrier5",0);
        dSetSpriteLinearVelocityX("barrier2",0);
        dSetSpriteLinearVelocityX("barrier3",0);
        dSetSpriteLinearVelocityX("barrier4",0);
        dSetSpriteLinearVelocityX("kaimen",0);
        dSetSpriteLinearVelocityX("damen",0);
        dSetSpriteLinearVelocityX("jianshou1",0);
        dSetSpriteLinearVelocityX("jianshou2",0);
        dSetSpriteLinearVelocityX("jianshou3",0);
        dSetSpriteLinearVelocityX("baikuang1",0);
        dSetSpriteLinearVelocityX("jianyu16",0);
        dSetSpriteLinearVelocityX("jianyu17",0);
        dSetSpriteLinearVelocityX("jianyu18",0);
        dSetSpriteLinearVelocityX("jianyu19",0);
   }
   if(stricmp("zuoguai",szSrcName)==0 && stricmp("tukuai5",szTarName)==0)
   {
       g_fSpeedLeft=0;
       g_fSpeedRight=0;
       g_fSpeedTop=0;
       g_fSpeedBottom=0;
       dSetSpriteLinearVelocity("zuoguai",g_fSpeedLeft+g_fSpeedRight,g_fSpeedTop+g_fSpeedBottom);
       dSetSpriteLinearVelocityX("ditu1",0);
        dSetSpriteLinearVelocityX("tukuai2",0);
        dSetSpriteLinearVelocityX("tukuai1",0);
        dSetSpriteLinearVelocityX("tukuai3",0);
        dSetSpriteLinearVelocityX("tukuai4",0);
        dSetSpriteLinearVelocityX("tukuai5",0);
        dSetSpriteLinearVelocityX("barrier1",0);
        dSetSpriteLinearVelocityX("shitou",0);
        dSetSpriteLinearVelocityX("baikuang",0);
        dSetSpriteLinearVelocityX("baoxiang",0);
        dSetSpriteLinearVelocityX("barrier5",0);
        dSetSpriteLinearVelocityX("barrier2",0);
        dSetSpriteLinearVelocityX("barrier3",0);
        dSetSpriteLinearVelocityX("barrier4",0);
        dSetSpriteLinearVelocityX("kaimen",0);
        dSetSpriteLinearVelocityX("damen",0);
        dSetSpriteLinearVelocityX("jianshou1",0);
        dSetSpriteLinearVelocityX("jianshou2",0);
        dSetSpriteLinearVelocityX("jianshou3",0);
        dSetSpriteLinearVelocityX("baikuang1",0);
        dSetSpriteLinearVelocityX("jianyu16",0);
        dSetSpriteLinearVelocityX("jianyu17",0);
        dSetSpriteLinearVelocityX("jianyu18",0);
        dSetSpriteLinearVelocityX("jianyu19",0);
   }

    if(stricmp("feilun",szSrcName)==0 && stricmp("baikuang",szTarName)==0)
   {
       dSetSpriteLinearVelocity("feilun",-20,0);
   }
   if(stricmp("feilun",szSrcName)==0 && stricmp("baikuang1",szTarName)==0)
   {
       dSetSpriteLinearVelocity("feilun",20,0);
   }
    if(stricmp("zuoguai",szSrcName)==0 && stricmp("shitou",szTarName)==0)
   {
       g_fSpeedLeft=0;
       g_fSpeedRight=0;
       g_fSpeedTop=0;
       g_fSpeedBottom=0;
       dSetSpriteLinearVelocity("zuoguai",g_fSpeedLeft+g_fSpeedRight,g_fSpeedTop+g_fSpeedBottom);
       dSetSpriteLinearVelocity("ditu1",0,0);
           dSetSpriteLinearVelocityX("tukuai2",0);
        dSetSpriteLinearVelocityX("tukuai1",0);
        dSetSpriteLinearVelocityX("tukuai3",0);
        dSetSpriteLinearVelocityX("tukuai4",0);
        dSetSpriteLinearVelocityX("tukuai5",0);
        dSetSpriteLinearVelocityX("barrier1",0);
        dSetSpriteLinearVelocityX("shitou",0);
        dSetSpriteLinearVelocityX("baikuang",0);
        dSetSpriteLinearVelocityX("baoxiang",0);
        dSetSpriteLinearVelocityX("barrier5",0);
        dSetSpriteLinearVelocityX("barrier2",0);
        dSetSpriteLinearVelocityX("barrier3",0);
        dSetSpriteLinearVelocityX("barrier4",0);
        dSetSpriteLinearVelocityX("kaimen",0);
        dSetSpriteLinearVelocityX("damen",0);
        dSetSpriteLinearVelocityX("jianshou1",0);
        dSetSpriteLinearVelocityX("jianshou2",0);
        dSetSpriteLinearVelocityX("jianshou3",0);
        dSetSpriteLinearVelocityX("baikuang1",0);
        dSetSpriteLinearVelocityX("jianyu16",0);
        dSetSpriteLinearVelocityX("jianyu17",0);
        dSetSpriteLinearVelocityX("jianyu18",0);
        dSetSpriteLinearVelocityX("jianyu19",0);
   }
    if(stricmp("zuoguai",szSrcName)==0 && stricmp("damen",szTarName)==0)
   {
       g_fSpeedLeft=0;
       g_fSpeedRight=0;
       g_fSpeedTop=0;
       g_fSpeedBottom=0;
       dSetSpriteLinearVelocity("zuoguai",g_fSpeedLeft+g_fSpeedRight,g_fSpeedTop+g_fSpeedBottom);
       dSetSpriteLinearVelocity("ditu1",0,0);
           dSetSpriteLinearVelocityX("tukuai2",0);
        dSetSpriteLinearVelocityX("tukuai1",0);
        dSetSpriteLinearVelocityX("tukuai3",0);
        dSetSpriteLinearVelocityX("tukuai4",0);
        dSetSpriteLinearVelocityX("tukuai5",0);
        dSetSpriteLinearVelocityX("barrier1",0);
        dSetSpriteLinearVelocityX("shitou",0);
        dSetSpriteLinearVelocityX("baikuang",0);
        dSetSpriteLinearVelocityX("baoxiang",0);
        dSetSpriteLinearVelocityX("barrier5",0);
        dSetSpriteLinearVelocityX("barrier2",0);
        dSetSpriteLinearVelocityX("barrier3",0);
        dSetSpriteLinearVelocityX("barrier4",0);
        dSetSpriteLinearVelocityX("kaimen",0);
        dSetSpriteLinearVelocityX("damen",0);
        dSetSpriteLinearVelocityX("jianshou1",0);
        dSetSpriteLinearVelocityX("jianshou2",0);
        dSetSpriteLinearVelocityX("jianshou3",0);
        dSetSpriteLinearVelocityX("baikuang1",0);
        dSetSpriteLinearVelocityX("jianyu16",0);
        dSetSpriteLinearVelocityX("jianyu17",0);
        dSetSpriteLinearVelocityX("jianyu18",0);
        dSetSpriteLinearVelocityX("jianyu19",0);
   }
    if(strstr(szSrcName, "zuoguai") && strstr(szTarName,"wenzi"))
   {
       blood-=1;
       dPlaySound("siwang.ogg",0,1);
   }
    if(stricmp("zuoguai",szSrcName)==0 && stricmp("barrier1",szTarName)==0)
   {
       blood-=1;
       dPlaySound("siwang.ogg",0,1);
   }
   if(stricmp("zuoguai",szSrcName)==0 && stricmp("barrier2",szTarName)==0)
   {
       blood-=1;
       dPlaySound("siwang.ogg",0,1);
   }
   if(stricmp("zuoguai",szSrcName)==0 && stricmp("barrier3",szTarName)==0)
   {
       blood-=1;
       dPlaySound("siwang.ogg",0,1);
   }
   if(stricmp("zuoguai",szSrcName)==0 && stricmp("feilun",szTarName)==0)
   {
       blood-=1;
       dPlaySound("siwang.ogg",0,1);
   }
   if(stricmp("zuoguai",szSrcName)==0 && stricmp("barrier4",szTarName)==0)
   {
       blood-=1;
       dPlaySound("siwang.ogg",0,1);
   }
if(stricmp("zuoguai",szSrcName)==0 && stricmp("barrier5",szTarName)==0)
   {
       blood-=1;
       dPlaySound("siwang.ogg",0,1);
   }
   for(int ee=1;ee<19;ee++)
   {
       if(stricmp("zuoguai",szSrcName)==0 && stricmp(jian[ee],szTarName)==0)
   {
       blood-=1;
       dPlaySound("siwang.ogg",0,1);
   }
   }
for(int bb=1;bb<300;bb++)
   {
       if(stricmp("zuoguai",szSrcName)==0 && stricmp(g_chmosquito[bb],szTarName)==0)
   {
       blood-=1;
       dPlaySound("siwang.ogg",0,1);
   }
   }
       if(strstr(szSrcName, "dadao") && strstr(szTarName,"fangjian"))
   {
       blood-=1;
       dPlaySound("siwang.ogg",0,1);
   }
   if(stricmp("dadao",szSrcName)==0 && stricmp("c1",szTarName)==0)
   {
       g_fSpeedLeft=0;
       g_fSpeedRight=0;
       g_fSpeedTop=0;
       g_fSpeedBottom=0;
       dSetSpriteLinearVelocity("dadao",g_fSpeedLeft+g_fSpeedRight,g_fSpeedTop+g_fSpeedBottom);
   }
   if(stricmp("dadao",szSrcName)==0 && stricmp("c2",szTarName)==0)
   {
       g_fSpeedLeft=0;
       g_fSpeedRight=0;
       g_fSpeedTop=0;
       g_fSpeedBottom=0;
       dSetSpriteLinearVelocity("dadao",g_fSpeedLeft+g_fSpeedRight,g_fSpeedTop+g_fSpeedBottom);
   }
   if(stricmp("dadao",szSrcName)==0 && stricmp("c3",szTarName)==0)
   {
       g_fSpeedLeft=0;
       g_fSpeedRight=0;
       g_fSpeedTop=0;
       g_fSpeedBottom=0;
       dSetSpriteLinearVelocity("dadao",g_fSpeedLeft+g_fSpeedRight,g_fSpeedTop+g_fSpeedBottom);
   }
   if(stricmp("dadao",szSrcName)==0 && stricmp("c4",szTarName)==0)
   {
       g_fSpeedLeft=0;
       g_fSpeedRight=0;
       g_fSpeedTop=0;
       g_fSpeedBottom=0;
       dSetSpriteLinearVelocity("dadao",g_fSpeedLeft+g_fSpeedRight,g_fSpeedTop+g_fSpeedBottom);
   }
   if(stricmp("dadao",szSrcName)==0 && stricmp("c5",szTarName)==0)
   {
       g_fSpeedLeft=0;
       g_fSpeedRight=0;
       g_fSpeedTop=0;
       g_fSpeedBottom=0;
       dSetSpriteLinearVelocity("dadao",g_fSpeedLeft+g_fSpeedRight,g_fSpeedTop+g_fSpeedBottom);
   }
   if(stricmp("dadao",szSrcName)==0 && stricmp("c6",szTarName)==0)
   {
       g_fSpeedLeft=0;
       g_fSpeedRight=0;
       g_fSpeedTop=0;
       g_fSpeedBottom=0;
       dSetSpriteLinearVelocity("dadao",g_fSpeedLeft+g_fSpeedRight,g_fSpeedTop+g_fSpeedBottom);
   }
   if(stricmp("dadao",szSrcName)==0 && stricmp("c7",szTarName)==0)
   {
       g_fSpeedLeft=0;
       g_fSpeedRight=0;
       g_fSpeedTop=0;
       g_fSpeedBottom=0;
       dSetSpriteLinearVelocity("dadao",g_fSpeedLeft+g_fSpeedRight,g_fSpeedTop+g_fSpeedBottom);
   }
   if(stricmp("dadao",szSrcName)==0 && stricmp("c8",szTarName)==0)
   {
       g_fSpeedLeft=0;
       g_fSpeedRight=0;
       g_fSpeedTop=0;
       g_fSpeedBottom=0;
       dSetSpriteLinearVelocity("dadao",g_fSpeedLeft+g_fSpeedRight,g_fSpeedTop+g_fSpeedBottom);
   }
   if(stricmp("dadao",szSrcName)==0 && stricmp("b1",szTarName)==0)
   {
       blood-=1;
       dPlaySound("siwang.ogg",0,1);
   }
   if(stricmp("dadao",szSrcName)==0 && stricmp("b2",szTarName)==0)
   {
       blood-=1;
       dPlaySound("siwang.ogg",0,1);
   }
   if(stricmp("dadao",szSrcName)==0 && stricmp("b3",szTarName)==0)
   {
       blood-=1;
       dPlaySound("siwang.ogg",0,1);
   }
   if(stricmp("dadao",szSrcName)==0 && stricmp("b4",szTarName)==0)
   {
       blood-=1;
       dPlaySound("siwang.ogg",0,1);
   }
   if(stricmp("dadao",szSrcName)==0 && stricmp("b5",szTarName)==0)
   {
       blood-=1;
       dPlaySound("siwang.ogg",0,1);
   }
   if(stricmp("dadao",szSrcName)==0 && stricmp("b6",szTarName)==0)
   {
       blood-=1;
       dPlaySound("siwang.ogg",0,1);
   }
   if(stricmp("dadao",szSrcName)==0 && stricmp("b7",szTarName)==0)
   {
       blood-=1;
       dPlaySound("siwang.ogg",0,1);
   }
   if(stricmp("dadao",szSrcName)==0 && stricmp("b8",szTarName)==0)
   {
       blood-=1;
       dPlaySound("siwang.ogg",0,1);
   }
   if(stricmp("b8",szSrcName)==0 && stricmp("c2",szTarName)==0)
   {
       dSetSpriteLinearVelocityX("b8",15);
   }
   if(stricmp("b3",szSrcName)==0 && stricmp("c4",szTarName)==0)
   {
       dSetSpriteLinearVelocityY("b3",-5);
   }
   if(stricmp("b3",szSrcName)==0 && stricmp("fulai",szTarName)==0)
   {
       dSetSpriteLinearVelocityY("b3",5);
   }
   if(stricmp("b4",szSrcName)==0 && stricmp("c4",szTarName)==0)
   {
       dSetSpriteLinearVelocityY("b4",-5);
   }
   if(stricmp("b4",szSrcName)==0 && stricmp("fulai",szTarName)==0)
   {
       dSetSpriteLinearVelocityY("b4",5);
   }
   if(stricmp("b5",szSrcName)==0 && stricmp("c4",szTarName)==0)
   {
       dSetSpriteLinearVelocityY("b5",-5);
   }
   if(stricmp("b5",szSrcName)==0 && stricmp("fulai",szTarName)==0)
   {
       dSetSpriteLinearVelocityY("b5",5);
   }
   if(stricmp("b6",szSrcName)==0 && stricmp("c4",szTarName)==0)
   {
       dSetSpriteLinearVelocityY("b6",-10);
   }
   if(stricmp("b6",szSrcName)==0 && stricmp("fulai",szTarName)==0)
   {
       dSetSpriteLinearVelocityY("b6",10);
   }
   if(stricmp("b7",szSrcName)==0 && stricmp("c3",szTarName)==0)
   {
       dSetSpriteLinearVelocityY("b7",-10);
   }
   if(stricmp("b7",szSrcName)==0 && stricmp("fulai",szTarName)==0)
   {
       dSetSpriteLinearVelocityY("b7",8);
   }
   if(stricmp("huidao",szSrcName)==0 && stricmp("guai1",szTarName)==0)
   {
       dDeleteSprite("guai1");
       dPlaySound("xiezi.wav",0,1);
   }
   if(stricmp("huidao",szSrcName)==0 && stricmp("guai2",szTarName)==0)
   {
       dDeleteSprite("guai2");
       dPlaySound("xiezi.wav",0,1);
   }
   if(stricmp("huidao",szSrcName)==0 && stricmp("guai3",szTarName)==0)
   {
       dDeleteSprite("guai3");
       dPlaySound("xiezi.wav",0,1);
   }
   if(stricmp("guai1",szSrcName)==0 && stricmp("dadao",szTarName)==0)
   {
       blood-=1;
       dPlaySound("siwang.ogg",0,1);
   }
   if(stricmp("guai2",szSrcName)==0 && stricmp("dadao",szTarName)==0)
   {
       blood-=1;
       dPlaySound("siwang.ogg",0,1);
   }
   if(stricmp("guai3",szSrcName)==0 && stricmp("dadao",szTarName)==0)
   {
       blood-=1;
       dPlaySound("siwang.ogg",0,1);
   }
   if(stricmp("boss1",szSrcName)==0 && stricmp("c7",szTarName)==0)
   {
       dSetSpriteLinearVelocityX("boss1",7);
       dSetSpriteFlipX( "boss1", 1 );

   }
   if(strcmp("boss1",szSrcName)==0&& stricmp("baibaide",szTarName)==0)
    {
          dSetSpriteLinearVelocityX("boss1",-7);
          dSetSpriteFlipX( "boss1", 0 );
    }
    if(strstr(szSrcName, "huidao") && strstr(szTarName,"boss1"))
    {
          boss1hp--;
          dSetTextValue("boss1hp",boss1hp);
          dPlaySound("shoushang.ogg",0,0.5);
           if(boss1hp<=0)
    {
        dPlaySound("shengli.ogg",0,0.5);
    }
    }
if(strstr(szSrcName, "ufo") && strstr(szTarName,"chengqiang1"))
{
    dDeleteSprite(szSrcName);
    g_chengqiang--;

    dSetTextValue("chengqiang",g_chengqiang);
    dPlaySound("chengqiang.ogg",0,0.5);
    if(g_chengqiang==0)
    {
        blood=0;
    }
}
if(stricmp("kongbu",szSrcName)==0 && stricmp("zuiqiang",szTarName)==0)
   {
       blood-=1;
       dPlaySound("siwang.ogg",0,1);
   }
if(strstr(szSrcName, "feibiao") && strstr(szTarName,"boss1"))
{
    boss1hp--;
    dSetTextValue("boss1hp",boss1hp);
    if(boss1hp<=0)
    {
        dPlaySound("shengli.ogg",0,0.5);
    }

}
if(strstr(szSrcName, "pugong") && strstr(szTarName,"ufo"))
{
    nengliang++;
    dDeleteSprite(szTarName);
    dSetTextValue("nengliang",nengliang);
    dPlaySound("shoushang.ogg",0,0.5);
}
if(strstr(szSrcName, "dazhao") && strstr(szTarName,"boss2"))
{
    boss22hp--;
    dSetTextValue("boss22hp",boss22hp);
    dPlaySound("shoushang.ogg",0,0.5);
    if(boss22hp==0)
    dPlaySound("shengli.ogg",0,0.5);
}
if(strstr(szSrcName, "paodan") && strstr(szTarName,"boss2"))
{
    boss22hp-=3;
    dSetTextValue("boss22hp",boss22hp);
    dDeleteSprite(szSrcName);
    if(boss22hp==0)
    dPlaySound("shengli.ogg",0,0.5);
}
if(strstr(szSrcName, "paodan") && strstr(szTarName,"ufo"))
{
    dDeleteSprite(szTarName);
}
if(strstr(szSrcName, "dazhao") && strstr(szTarName,"ufo"))
{
    dDeleteSprite(szTarName);
}
if(strstr(szSrcName, "dazhao") && strstr(szTarName,"boss3"))
{
    boss3hp--;
    dSetTextValue("boss3hp",boss3hp);
    dPlaySound("shoushang.ogg",0,0.5);
    if(boss3hp==0)
    dPlaySound("shengli.ogg",0,0.5);
}
if(strstr(szSrcName, "paodan") && strstr(szTarName,"boss3"))
{
    boss3hp--;
    dDeleteSprite(szSrcName);
    dSetTextValue("boss3hp",boss3hp);
    if(boss3hp==0)
    dPlaySound("shengli.ogg",0,0.5);
}
if(strstr(szSrcName, "pugong") && strstr(szTarName,"boss3"))
{
    boss3hp--;
    dSetTextValue("boss3hp",boss3hp);
    if(boss3hp==0)
    dPlaySound("shengli.ogg",0,0.5);
}
if(strstr(szSrcName, "pugong") && strstr(szTarName,"kkk"))
{
    dDeleteSprite(szTarName);
    nengliang+=50;
    dPlaySound("shoushang.ogg",0,0.5);
    dSetTextValue("nengliang",nengliang);

}
if(strstr(szSrcName, "kkk") && strstr(szTarName,"zuiqiang"))
{
    blood--;
    dDeleteSprite(szSrcName);
    dPlaySound("siwang.ogg",0,0.5);
    dSetTextValue("blood",blood);
}
if(strstr(szSrcName, "ppp") && strstr(szTarName,"zuiqiang"))
{
    blood--;
    dDeleteSprite(szSrcName);
    dPlaySound("siwang.ogg",0,0.5);
    dSetTextValue("blood",blood);
}
if(strstr(szSrcName, "ppp") && strstr(szTarName,"bbb"))
{
    dDeleteSprite(szSrcName);
}
if(strstr(szSrcName, "guangbo") && strstr(szTarName,"bbb"))
{
    dDeleteSprite(szSrcName);
}
if(strstr(szSrcName, "guangbo") && strstr(szTarName,"zuiqiang"))
{
    dDeleteSprite(szSrcName);
    blood--;
    dSetTextValue("blood",blood);
    dPlaySound("siwang.ogg",0,0.5);
}
if(strstr(szSrcName, "paodan") && strstr(szTarName,"kkk"))
{
    dDeleteSprite(szTarName);
    dDeleteSprite(szSrcName);
    nengliang+=50;
    dSetTextValue("nengliang",nengliang);
    dPlaySound("shoushang.ogg",0,0.5);
}
	// �����ڴ������Ϸ��Ҫ����Ӧ����
	OnSpriteColSprite(szSrcName, szTarName);
}

//===========================================================================
//
// ���沶׽������������߽���ײ֮�󣬵��ô˺���.
// ����֮��Ҫ������ײ�������ڱ༭�����ߴ��������þ��������߽�����
// ���� szName����ײ���߽�ľ�������
// ���� iColSide����ײ���ı߽� 0 ��ߣ�1 �ұߣ�2 �ϱߣ�3 �±�
//
void dOnSpriteColWorldLimit( const char *szName, const int iColSide )
{
    if(strcmp(szName,"feilun")==0)
    {
        if(iColSide==0)
          dSetSpriteLinearVelocityX("feilun",20);
    }
    if(strcmp(szName,"dazhao")==0)
    {
        if(iColSide==1)
        {
            dSetSpriteLinearVelocityX("dazhao",0);
            dSetSpritePosition("dazhao",-89.375,3.157);
        }

    }

    if(strcmp(szName,"ditu1")==0)
    {
        if(iColSide==0||iColSide==1)
       {
           ditu1=0;
           dSetSpriteLinearVelocity("ditu1",0,0);
           dSetSpriteLinearVelocityX("tukuai2",0);
        dSetSpriteLinearVelocityX("tukuai1",0);
        dSetSpriteLinearVelocityX("tukuai3",0);
        dSetSpriteLinearVelocityX("tukuai4",0);
        dSetSpriteLinearVelocityX("tukuai5",0);
        dSetSpriteLinearVelocityX("barrier1",0);
        dSetSpriteLinearVelocityX("shitou",0);
        dSetSpriteLinearVelocityX("baikuang",0);
        dSetSpriteLinearVelocityX("baoxiang",0);
        dSetSpriteLinearVelocityX("barrier5",0);
        dSetSpriteLinearVelocityX("barrier2",0);
        dSetSpriteLinearVelocityX("barrier3",0);
        dSetSpriteLinearVelocityX("barrier4",0);
        dSetSpriteLinearVelocityX("kaimen",0);
        dSetSpriteLinearVelocityX("damen",0);
        dSetSpriteLinearVelocityX("jianshou1",0);
        dSetSpriteLinearVelocityX("jianshou2",0);
        dSetSpriteLinearVelocityX("jianshou3",0);
        dSetSpriteLinearVelocityX("baikuang1",0);
        dSetSpriteLinearVelocityX("jianyu16",0);
        dSetSpriteLinearVelocityX("jianyu17",0);
        dSetSpriteLinearVelocityX("jianyu18",0);
        dSetSpriteLinearVelocityX("jianyu19",0);
       }

       if(strstr(szName,"muban")==NULL)
{
//�����������߽�Ĳ���ģ��
		if(strstr(szName,"ufo")!=NULL &&iColSide==0)
{
//3��ʾ�±߽�
			dDeleteSprite(szName);
		}
else if(strstr(szName,"fangjian")!=NULL)
{
			dDeleteSprite(szName);
		}
else if(strstr(szName,"jianyu")!=NULL)
{
			dDeleteSprite(szName);
		}
else if(strstr(szName,"wenzi")!=NULL)
{
			dDeleteSprite(szName);
		}
	}
if(strcmp(szName,"boss3")==0)
    {
        if(iColSide==2)
        {
            dSetSpriteLinearVelocityY("boss3",10);
        }
        if(iColSide==3)
        {
            dSetSpriteLinearVelocityY("boss3",-15);
        }

    }
    }





	// �����ڴ������Ϸ��Ҫ����Ӧ����
	OnSpriteColWorldLimit(szName, iColSide);
}

