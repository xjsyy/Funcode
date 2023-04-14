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
// 大体的程序流程为：GameMainLoop函数为主循环函数，在引擎每帧刷新屏幕图像之后，都会被调用一次。

//==============================================================================
//
// 构造函数
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
// 析构函数
CGameMain::~CGameMain()
{
}

//==============================================================================
//
// 游戏主循环，此函数将被不停的调用，引擎每刷新一次屏幕，此函数即被调用一次
// 用以处理游戏的开始、进行中、结束等各种状态.
// 函数参数fDeltaTime : 上次调用本函数到此次调用本函数的时间间隔，单位：秒
void CGameMain::GameMainLoop( float	fDeltaTime )
{
	switch( GetGameState() )
	{
		// 初始化游戏，清空上一局相关数据
	case 1:
		{
			GameInit();
			SetGameState(2); // 初始化之后，将游戏状态设置为进行中
		}
		break;

		// 游戏进行中，处理各种游戏逻辑
	case 2:
		{
			// TODO 修改此处游戏循环条件，完成正确游戏逻辑
			if( m_fTotalTime<60 )
			{
				GameRun( fDeltaTime );
			}
			else // 游戏结束。调用游戏结算函数，并把游戏状态修改为结束状态
			{
				SetGameState(0);
				GameEnd();
			}
		}
		break;

		// 游戏结束/等待按空格键开始
	case 0:
	default:
		break;
	};
}
//=============================================================================
//
// 每局开始前进行初始化，清空上一局相关数据
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
// 每局游戏进行中
void CGameMain::GameRun( float fDeltaTime )
{
    m_fTotalTime+=fDeltaTime;
    //if(m_fTotalTime>2)
        //m_pyellowFish->SetSpriteLinearVelocity(0,0);
    //OnKeyDown(iKey, bAltPress,bShiftPress,bCtrlPress );
}
//=============================================================================
//
// 本局游戏结束
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
// 引擎捕捉鼠标移动消息后，将调用到本函数
void CGameMain::OnMouseMove( const float fMouseX, const float fMouseY )
{
	// 可以在此添加游戏需要的响应函数
}
//==========================================================================
//
// 引擎捕捉鼠标点击消息后，将调用到本函数
void CGameMain::OnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{
	// 可以在此添加游戏需要的响应函数
    pPerson->SetSpritePosition(fMouseX,fMouseY);
}
//==========================================================================
//杨钰春 计211-2
// 202158501223
// 引擎捕捉鼠标弹起消息后，将调用到本函数
void CGameMain::OnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{
	// 可以在此添加游戏需要的响应函数
}
//==========================================================================
//
// 引擎捕捉键盘按下消息后，将调用到本函数
// bAltPress bShiftPress bCtrlPress 分别为判断Shift，Alt，Ctrl当前是否也处于按下状态。比如可以判断Ctrl+E组合键
void CGameMain::OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress )
{
	// 可以在此添加游戏需要的响应函数
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
// 引擎捕捉键盘弹起消息后，将调用到本函数
void CGameMain::OnKeyUp( const int iKey )
{
	//如果松开的是WSAD，则置鱼的速度为0
    pPerson->SetSpriteLinearVelocity(0,0);
}

//===========================================================================
//
// 引擎捕捉到精灵与精灵碰撞之后，调用此函数
void CGameMain::OnSpriteColSprite( const char *szSrcName, const char *szTarName )
{
}

//===========================================================================
//
// 引擎捕捉到精灵与世界边界碰撞之后，调用此函数.
// iColSide : 0 左边，1 右边，2 上边，3 下边
void CGameMain::OnSpriteColWorldLimit( const char *szName, const int iColSide )
{

    if(1==iColSide){        //右边界
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
    else if(0==iColSide){        //左边界
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
