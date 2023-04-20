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
CGameMain g_GameMain;

//==============================================================================
//
// 大体的程序流程为：GameMainLoop函数为主循环函数，在引擎每帧刷新屏幕图像之后，都会被调用一次。

//==============================================================================
//
// 构造函数
CGameMain::CGameMain()
{
	m_iGameState = 1;
	paizi = new CSprite("paizi");
	countdown = new CTextSprite("countdown");
	kaishi = new CSprite("kaishi");
	score = new CTextSprite("score");
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
void CGameMain::GameMainLoop(float fDeltaTime)
{
	switch (GetGameState())
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
		if (true)
		{
			GameRun(fDeltaTime);
		}
		else // 游戏结束。调用游戏结算函数，并把游戏状态修改为结束状态
		{
			SetGameState(0);
			GameEnd();
		}
	}
	break;
	case 3:
	case 4:
	{ // TODO 修改此处游戏循环条件，完成正确游戏逻辑
		if (true)
		{
			GameRun(fDeltaTime);
		}
		else // 游戏结束。调用游戏结算函数，并把游戏状态修改为结束状态
		{
			SetGameState(0);
			GameEnd();
		}
	}
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
	m_iGameScore = 0;
	CSystem::ShowCursor(false); // 隐藏鼠标
	m_fRotateTime = 0.f;
	m_fOldRotation = paizi->GetSpriteRotation(); // 获取拍子的初始角度
	countdownTime = 3;							 // 倒计时时间为5s
	countPassedTime = 0.f;
	countdown->SetSpriteVisible(false); // 设置倒计时不可见
	m_iMosquitoCount = 20;
	gameTime = new CTextSprite("gameTime");
}
//=============================================================================
//
// 每局游戏进行中
void CGameMain::GameRun(float fDeltaTime)
{
	if (m_fRotateTime > 0)
	{
		m_fRotateTime -= fDeltaTime; // 每经过fDeltaTime，拍子旋转的时 间也少了fDeltaTime
		if (m_fRotateTime <= 0)
		{											  // 经过了0.2s以后
			paizi->SetSpriteRotation(m_fOldRotation); // 恢复拍子的初始旋转角
		}
	}
	if (m_iGameState == 3)
	{								   // m_iGameState 为3时才执行
		countPassedTime += fDeltaTime; // 统计经过的时间，并存储到countPassedTime
		countdown->SetTextValue(countdownTime - countPassedTime);
		if (countPassedTime >= countdownTime)
		{										// 经过的时间超过countdownTime
			countdown->SetSpriteVisible(false); // 隐藏countdown
			countPassedTime = 0;				// 重置经过的时间，为下一轮游戏做准备
			m_iGameState = 4;					// 切换g_iGameState 3->4
			int minX = CSystem::GetScreenLeft() + 5;
			int maxX = CSystem::GetScreenRight() - 5;
			int minY = CSystem::GetScreenBottom() - 5;
			int maxY = CSystem::GetScreenTop() + 5;
			int iPosX = 0, iPosY = 0, iSize = 0; // 随机产生的横纵坐标位置
			int iLoop = 0;						 // 循环控制变量
			for (iLoop = 0; iLoop < m_iMosquitoCount; iLoop++)
			{
				if (iLoop < 10) // 生成10个小蚊子，大小为4
				{
					iSize = 2;
				}
				else if (iLoop >= 10 && iLoop < 16) // 生成6个中蚊子，大小为6
				{
					iSize = 3;
				}
				else // 生成4个大蚊子，大小为8
				{
					iSize = 4;
				}
				// 初始化蚊子精灵实例
				char *szName = CSystem::MakeSpriteName("wenzi", iLoop); // 利用iLoop产生不同的蚊子名
				CSprite *wenzi = new CSprite(szName);
				wenzi->CloneSprite("wenziTemplate");	  // 复制wenziTemplate
				wenzi->SetSpriteWidth(iSize);			  // 设置蚊子的宽度
				wenzi->SetSpriteHeight(iSize);			  // 设置蚊子的高度
				iPosX = CSystem::RandomRange(minX, maxX); // 随机产生X坐标
				iPosY = CSystem::RandomRange(minY, maxY); // 随机产生Y坐标
				wenzi->SetSpritePosition(iPosX, iPosY);	  // 设置产生蚊子的位置
				wenzi->SetSpriteCollisionReceive(true);
				m_mosquitos.push_back(wenzi); // 压入vector中集中管理
			}
		}
	}
	else if (m_iGameState == 4)
	{
		m_fGameTime -= fDeltaTime;
		if (m_fGameTime > 0)
		{
			gameTime->SetTextValue(m_fGameTime); // 若游戏时间未结束，则显示剩余的游戏时间
		}
		else
		{
			m_iGameState = 2;				// 若游戏时间结束，完成g_iGameState 2->0的转换
			kaishi->SetSpriteVisible(true); // 显示“空格开始”
			m_fGameTime = 0;
			paizi->SetSpritePositionX(18);
			paizi->SetSpritePositionY(8);
			gameTime->SetTextValue(m_fGameTime);
		}
	}
}
//=============================================================================
//
// 本局游戏结束
void CGameMain::GameEnd()
{
}

//==========================================================================
//
// 引擎捕捉鼠标移动消息后，将调用到本函数
void CGameMain::OnMouseMove(const float fMouseX, const float fMouseY)
{
	// 可以在此添加游戏需要的响应函数]
	if (m_iGameState == 4)
	{
		paizi->SetSpritePosition(fMouseX, fMouseY); // 使拍子的位置和鼠标一致
	}
}
//==========================================================================
//
// 引擎捕捉鼠标点击消息后，将调用到本函数
void CGameMain::OnMouseClick(const int iMouseType, const float fMouseX, const float fMouseY)
{
	// 可以在此添加游戏需要的响应函数
	if (iMouseType == MOUSE_LEFT && m_iGameState == 4) // 鼠标左键按下
	{
		paizi->SetSpriteRotation(m_fOldRotation - 10); // 设置拍子的旋转角，为初始值-10
		m_fRotateTime = 0.1f;						   // 拍打的时间间隔 0.2s，即0.2s后恢复拍子初始角度
		// 遍历判定蚊子是否被击中
		float fX, fY;
		for (int i = 0; i < m_mosquitos.size(); i++)
		{											   // 遍历vector中的蚊子
			fX = m_mosquitos[i]->GetSpritePositionX(); // 获取蚊子所在的横坐标
			fY = m_mosquitos[i]->GetSpritePositionY(); // 获取蚊子所在的纵坐标
			if (paizi->IsPointInSprite(fX, fY))		   // 判断蚊子是否在拍子的范围内
			{
				m_mosquitos[i]->DeleteSprite(); // 删除该蚊子
				m_iGameScore++;					// 每打一只蚊子加一分
				score->SetTextValue(m_iGameScore);
				break;
			}
		}
	}
}
//==========================================================================
//
// 引擎捕捉鼠标弹起消息后，将调用到本函数
void CGameMain::OnMouseUp(const int iMouseType, const float fMouseX, const float fMouseY)
{
	// 可以在此添加游戏需要的响应函数
}
//==========================================================================
//
// 引擎捕捉键盘按下消息后，将调用到本函数
// bAltPress bShiftPress bCtrlPress 分别为判断Shift，Alt，Ctrl当前是否也处于按下状态。比如可以判断Ctrl+E组合键
void CGameMain::OnKeyDown(const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress)
{
	// 可以在此添加游戏需要的响应函数
	if (KEY_SPACE == iKey && 2 == m_iGameState) // 按下空格且游戏状态为2时
	{
		m_iGameState = 3;				   // 设置游戏状态进入倒计时，即3
		countdown->SetSpriteVisible(true); // 显示倒计时文本框
		kaishi->SetSpriteVisible(false);   // 隐藏“空格开始”
		m_iGameScore = 0.f;				   // 初始化新一轮游戏分数
		m_fGameTime = 10.f;				   // 初始化新一轮游戏时间
		score->SetTextValue(m_iGameScore);
		gameTime->SetTextValue(m_fGameTime);
		for (int i = 0; i < m_mosquitos.size(); i++)
		{ // 删除上一轮游戏中剩余的蚊子
			m_mosquitos[i]->DeleteSprite();
		}
		m_mosquitos.clear(); // 清空vector
	}
}
//==========================================================================
//
// 引擎捕捉键盘弹起消息后，将调用到本函数
void CGameMain::OnKeyUp(const int iKey)
{
	// 可以在此添加游戏需要的响应函数
}

//===========================================================================
//
// 引擎捕捉到精灵与精灵碰撞之后，调用此函数
void CGameMain::OnSpriteColSprite(const char *szSrcName, const char *szTarName)
{
}

//===========================================================================
//
// 引擎捕捉到精灵与世界边界碰撞之后，调用此函数.
// iColSide : 0 左边，1 右边，2 上边，3 下边
void CGameMain::OnSpriteColWorldLimit(const char *szName, const int iColSide)
{
}
