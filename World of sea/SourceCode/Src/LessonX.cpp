/////////////////////////////////////////////////////////////////////////////////
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////
#include <Stdio.h>
#include "CommonClass.h"
#include "LessonX.h"
////////////////////////////////////////////////////////////////////////////////
//
//
CGameMain		g_GameMain;

//==============================================================================
//
// ����ĳ�������Ϊ��GameMainLoop����Ϊ��ѭ��������������ÿ֡ˢ����Ļͼ��֮�󣬶��ᱻ����һ�Ρ�

//==============================================================================
//
// ���캯��
CGameMain::CGameMain()
{
    m_pblueFish = new CSprite("blueFish");
    m_pyellowFish = new CSprite("yellowFish");
    m_pcopyFish = new CSprite("copyFish");
    m_phaima= new CSprite("haima");
    m_pwhiteFish = new CSprite("whiteFish");
    m_pTextGameOver = new CTextSprite("gameOver");
    m_pyellowT=new CSprite("yellowT");
    pPerson = new CSprite("User");
    m_fTotalTime=0.0f;
	m_iGameState=0;
}
//==============================================================================
//
// ��������
CGameMain::~CGameMain()
{
}

//==============================================================================
//
// ��Ϸ��ѭ�����˺���������ͣ�ĵ��ã�����ÿˢ��һ����Ļ���˺�����������һ��
// ���Դ�����Ϸ�Ŀ�ʼ�������С������ȸ���״̬.
// ��������fDeltaTime : �ϴε��ñ��������˴ε��ñ�������ʱ��������λ����
void CGameMain::GameMainLoop( float	fDeltaTime )
{
	switch( GetGameState() )
	{
		// ��ʼ����Ϸ�������һ���������
	case 1:
		{
			GameInit();
			SetGameState(2); // ��ʼ��֮�󣬽���Ϸ״̬����Ϊ������
		}
		break;

		// ��Ϸ�����У����������Ϸ�߼�
	case 2:
		{
			// TODO �޸Ĵ˴���Ϸѭ�������������ȷ��Ϸ�߼�
			if( m_fTotalTime<60 )
			{
				GameRun( fDeltaTime );
			}
			else // ��Ϸ������������Ϸ���㺯����������Ϸ״̬�޸�Ϊ����״̬
			{
				SetGameState(0);
				GameEnd();
			}
		}
		break;

		// ��Ϸ����/�ȴ����ո����ʼ
	case 0:
	default:
		break;
	};
}
//=============================================================================
//
// ÿ�ֿ�ʼǰ���г�ʼ���������һ���������
void CGameMain::GameInit()
{
    m_pblueFish->SetSpriteVisible(true);
    m_pblueFish->SetSpritePosition(32,13);

    m_pyellowT->SetSpriteVisible(true);
    m_pyellowT->SetSpritePosition(33,-22);

    m_phaima->SetSpriteVisible(true);
    m_phaima->SetSpritePosition(85,-20);

    m_pcopyFish->SetSpriteVisible(true);
    m_pcopyFish->SetSpritePosition(-85,-30);

    m_pwhiteFish->SetSpriteVisible(true);
    m_pwhiteFish->SetSpritePosition(-85,10);

    m_pyellowFish->SetSpriteVisible(true);
    m_pyellowFish->SetSpritePosition(-34,11);

    //pPerson->SetSpriteVisible(true);

    m_pblueFish->SetSpriteLinearVelocity(-5,0);
    m_pyellowT->SetSpriteLinearVelocity(-5,0);
    m_pyellowFish->SetSpriteLinearVelocity(5,0);
    m_pcopyFish->SetSpriteLinearVelocity(5,0);
    m_phaima->SetSpriteLinearVelocity(-5,0);
    pPerson->SetSpriteLinearVelocity(5,0);
    m_pwhiteFish->SetSpriteLinearVelocity(5,0);


    m_pTextGameOver->SetSpriteVisible(false);

    m_parr[0]=new CSprite("copyFish1");
    m_parr[0]->CloneSprite("copyFish");
    m_parr[1]=new CSprite("copyFish2");
    m_parr[1]->CloneSprite("copyFish");
    m_parr[0]->SetSpritePositionY(-20);
    m_parr[1]->SetSpritePositionY(-10);

}
//=============================================================================
//
// ÿ����Ϸ������
void CGameMain::GameRun( float fDeltaTime )
{
    m_fTotalTime+=fDeltaTime;
    //if(m_fTotalTime>2)
        //m_pyellowFish->SetSpriteLinearVelocity(0,0);
    //OnKeyDown(iKey, bAltPress,bShiftPress,bCtrlPress );
}
//=============================================================================
//
// ������Ϸ����
void CGameMain::GameEnd()
{
    m_pblueFish->SetSpriteVisible(false);
    m_pyellowFish->SetSpriteVisible(false);
    m_pcopyFish->SetSpriteVisible(false);
    m_pwhiteFish->SetSpriteVisible(false);
    m_parr[1]->SetSpriteVisible(false);
    m_parr[0]->SetSpriteVisible(false);
    pPerson->SetSpriteVisible(false);
    m_phaima->SetSpriteVisible(false);
    m_pTextGameOver->SetSpriteVisible(true);
    m_pTextGameOver->SetSpritePosition(0,0);
    m_fTotalTime=0.0f;

}
// ���沶׽����ƶ���Ϣ�󣬽����õ�������
void CGameMain::OnMouseMove( const float fMouseX, const float fMouseY )
{
	// �����ڴ������Ϸ��Ҫ����Ӧ����
}
//==========================================================================
//
// ���沶׽�������Ϣ�󣬽����õ�������
void CGameMain::OnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{
	// �����ڴ������Ϸ��Ҫ����Ӧ����
    pPerson->SetSpritePosition(fMouseX,fMouseY);
}
//==========================================================================
//���ڴ� ��211-2
// 202158501223
// ���沶׽��굯����Ϣ�󣬽����õ�������
void CGameMain::OnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{
	// �����ڴ������Ϸ��Ҫ����Ӧ����
}
//==========================================================================
//
// ���沶׽���̰�����Ϣ�󣬽����õ�������
// bAltPress bShiftPress bCtrlPress �ֱ�Ϊ�ж�Shift��Alt��Ctrl��ǰ�Ƿ�Ҳ���ڰ���״̬����������ж�Ctrl+E��ϼ�
void CGameMain::OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress )
{
	// �����ڴ������Ϸ��Ҫ����Ӧ����
    switch(iKey){
    case KEY_SPACE:
         SetGameState(1);
    case KEY_W:
         pPerson->SetSpriteLinearVelocity(0,-20);
         break;
    case KEY_S:
         pPerson->SetSpriteLinearVelocity(0,20);
         break;
    case KEY_A:
         pPerson->SetSpriteLinearVelocity(-20,0);
         pPerson->SetSpriteFlipX(true);
         break;
    case KEY_D:
         pPerson->SetSpriteLinearVelocity(20,0);
         pPerson->SetSpriteFlipX(false);
         break;
    }
}
//==========================================================================
//
// ���沶׽���̵�����Ϣ�󣬽����õ�������
void CGameMain::OnKeyUp( const int iKey )
{
	//����ɿ�����WSAD����������ٶ�Ϊ0
    pPerson->SetSpriteLinearVelocity(0,0);
}

//===========================================================================
//
// ���沶׽�������뾫����ײ֮�󣬵��ô˺���
void CGameMain::OnSpriteColSprite( const char *szSrcName, const char *szTarName )
{
}

//===========================================================================
//
// ���沶׽������������߽���ײ֮�󣬵��ô˺���.
// iColSide : 0 ��ߣ�1 �ұߣ�2 �ϱߣ�3 �±�
void CGameMain::OnSpriteColWorldLimit( const char *szName, const int iColSide )
{

    if(1==iColSide){        //�ұ߽�
        pPerson->SetSpriteLinearVelocity(-20,0);
        m_pyellowFish->SetSpriteLinearVelocity(-5,0);
        m_pblueFish->SetSpriteLinearVelocity(5,0);
        m_pyellowT->SetSpriteLinearVelocity(5,0);
        m_phaima->SetSpriteLinearVelocity(5,0);
        m_pcopyFish->SetSpriteLinearVelocity(-5,0);
        m_pwhiteFish->SetSpriteLinearVelocity(-20,0);


        m_pyellowFish->SetSpriteFlipX(true);
        m_pcopyFish->SetSpriteFlipX(true);
        m_phaima->SetSpriteFlipX(false);
        m_pwhiteFish->SetSpriteFlipX(true);
        pPerson->SetSpriteFlipX(true);
        m_pblueFish->SetSpriteFlipX(false);
        m_pyellowT->SetSpriteFlipX(false);
    }
    else if(0==iColSide){        //��߽�
        pPerson->SetSpriteLinearVelocity(20,0);
        m_pyellowFish->SetSpriteLinearVelocity(5,0);
        m_pblueFish->SetSpriteLinearVelocity(-5,0);
        m_pyellowT->SetSpriteLinearVelocity(-5,0);
        m_phaima->SetSpriteLinearVelocity(-5,0);
        m_pcopyFish->SetSpriteLinearVelocity(5,0);
        m_pwhiteFish->SetSpriteLinearVelocity(5,0);

        pPerson->SetSpriteFlipX(false);
        m_pyellowFish->SetSpriteFlipX(false);
        m_pcopyFish->SetSpriteFlipX(false);
        m_pwhiteFish->SetSpriteFlipX(false);
        m_phaima->SetSpriteFlipX(true);
        m_pblueFish->SetSpriteFlipX(true);
        m_pyellowT->SetSpriteFlipX(true);
    }
}
