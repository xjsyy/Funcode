/////////////////////////////////////////////////////////////////////////////////
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////
#include <Stdio.h>
#include "CommonClass.h"
#include "LessonX.h"
/////////////////////////////////////////////////////////////////////////////////
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
    // m_iGameState = 1;
    goldHook = new CSprite("goldhook"); // 创建钩子实例
    Begin = new CSprite("begin");
    goldMan = new CAnimateSprite("goldman");
    m_fTotalTime = 0.0f;
    m_iGameState = 0;
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
        if (m_iGoldCount > 0)
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
    m_iHookState = 0; // 初始情况下使钩子旋转
    m_fHookSpeed = 30.f;

    int m_fGoldBornMinX = 0;
    int m_fGoldBornMaxX = 0;
    int m_fGoldBornMinY = 0;
    int m_fGoldBornMaxY = 0;

    Begin->SetSpriteVisible(false);

    m_fHookStartPosX = 0.f;
    m_fHookStartPosY = 0.f;
    m_iHookRotToLeft = 1;  // 钩子初始化方向为←
    m_fHookRotation = 0.f; // 初始化的夹角为0
    m_iGoldCount = 20;     // 金子初始数量
    static int IinitedHookPos = 0;
    if (IinitedHookPos == 0)
    {
        IinitedHookPos = 1;

        m_fHookStartPosX = goldHook->GetSpritePositionX(); // 获取钩子的初始化X坐标
        m_fHookStartPosY = goldHook->GetSpritePositionY(); // 获取钩子的初始化Y坐标

        m_fGoldBornMinX = CSystem::GetScreenLeft() + 5;   // 金子左边界
        m_fGoldBornMaxX = CSystem::GetScreenRight() - 5;  // 金子右边界
        m_fGoldBornMinY = CSystem::GetScreenTop() + 20;   // 金子上边界
        m_fGoldBornMaxY = CSystem::GetScreenBottom() - 5; // 金子下边界

        m_fRockBornMinX = CSystem::GetScreenLeft() + 5;   // 石块左边界
        m_fRockBornMaxX = CSystem::GetScreenRight() - 5;  // 石块右边界
        m_fRockBornMinY = CSystem::GetScreenTop() + 20;   // 石块上边界
        m_fRockBornMaxY = CSystem::GetScreenBottom() - 5; // 石块下边界

        m_fBompBornMinX = CSystem::GetScreenLeft() + 5;   // 炸弹左边界
        m_fBompBornMaxX = CSystem::GetScreenRight() - 5;  // 炸弹右边界
        m_fBompBornMinY = CSystem::GetScreenTop() + 20;   // 炸弹上边界
        m_fBompBornMaxY = CSystem::GetScreenBottom() - 5; // 炸弹下边界
    }

    int iLoop = 0,iBLoop=0,iRLoop;                       // 循环变量控制
    int iSize = 4,iBSize=4,iRSize=4, iPosX = 0, iPosY = 0, iBPosX = 0, iBPosY = 0, iRPosX = 0, iRPosY = 0; // iSize表示金块大小的变量
    for (iLoop = 0; iLoop < m_iGoldCount; iLoop++)
    {
        if (iLoop < 10) // 生成10个小金块，大小为4
        {
            iSize = 4;
        }
        else if (iLoop >= 10 && iLoop < 16) // 生成6个中金块，大小为6
        {
            iSize = 6;
        }
        else // 生成4个大金块，大小为8
        {
            iSize = 8;
        }
        // 初始化金子精灵实例
        char *tmpName;//*tmpName2;
        tmpName = CSystem::MakeSpriteName("GoldBlock", iLoop); // 生成金块名字
        CSprite *tmpSprite = new CSprite(tmpName);
        tmpSprite->CloneSprite("goldTemplate");
        tmpSprite->SetSpriteWidth(iSize);  // 设置金块的宽度
        tmpSprite->SetSpriteHeight(iSize); // 设置金块的高度
        // 随机的获取金子的X坐标和Y坐标
        iPosX = CSystem::RandomRange(m_fGoldBornMinX, m_fGoldBornMaxX);
        iPosY = CSystem::RandomRange(m_fGoldBornMinY, m_fGoldBornMaxY);
        // 设置金块精灵的位置
        tmpSprite->SetSpritePosition(iPosX, iPosY);
        tmpSprite->SetSpriteCollisionReceive(true);

        golds.push_back(tmpSprite); // 将金块压入golds vector中集中管理*/
    }
    for(iBLoop=0;iBLoop<4;iBLoop++){
        iBSize=5;
        char *tmpName2;
        tmpName2 = CSystem::MakeSpriteName("Bomp", iBLoop); // 生成金块名字
        CSprite *tmpSprite2 = new CSprite(tmpName2);
        tmpSprite2->CloneSprite("bompTemplate");
        tmpSprite2->SetSpriteWidth(iBSize);  // 设置炸弹的宽度
        tmpSprite2->SetSpriteHeight(iBSize); // 设置炸弹的高度
        iBPosX = CSystem::RandomRange(m_fBompBornMinX, m_fBompBornMaxX);
        iBPosY = CSystem::RandomRange(m_fBompBornMinY, m_fBompBornMaxY);
        tmpSprite2->SetSpritePosition(iBPosX, iBPosY);
        tmpSprite2->SetSpriteCollisionReceive(true);
    }
    for(iRLoop=0;iRLoop<4;iRLoop++){
        iRSize=5;
        char *tmpName;
        tmpName = CSystem::MakeSpriteName("Rock", iRLoop); // 生成石头名字
        CSprite *tmpSprite = new CSprite(tmpName);
        tmpSprite->CloneSprite("rockTemplate");
        tmpSprite->SetSpriteWidth(iRSize);  // 设置石头的宽度
        tmpSprite->SetSpriteHeight(iRSize); // 设置石头的高度
        iRPosX = CSystem::RandomRange(m_fRockBornMinX, m_fRockBornMaxX);
        iRPosY = CSystem::RandomRange(m_fRockBornMinY, m_fRockBornMaxY);
        tmpSprite->SetSpritePosition(iRPosX, iRPosY);
        tmpSprite->SetSpriteCollisionReceive(true);

        rocks.push_back(tmpSprite); // 将金块压入golds vector中集中管理*/
    }
}
//=============================================================================
//
// 每局游戏进行中
void CGameMain::GameRun(float fDeltaTime)
{
    if (m_iHookState == 0)
    {
        const float fRotateSpeed = 45.f;               //  摇摆速度，单位 度/秒
        float fThisRotate = fRotateSpeed * fDeltaTime; // 本次旋转的角度
        // m_fTotalTime+=fDeltaTime;

        if (m_iHookRotToLeft)
        {
            // 向左 转，度数不断变大
            m_fHookRotation += fThisRotate;
            if (m_fHookRotation >= 180.f)
            {
                // 大于180，置为向右转，即0
                m_fHookRotation = 180.f;
                m_iHookRotToLeft = 0;
            }
        }
        else // 向右转，度数不断变小
        {
            m_fHookRotation -= fThisRotate; // 小于0，置为向左转，即 1
            if (m_fHookRotation <= 0.f)
            {
                m_fHookRotation = 0.f;
                m_iHookRotToLeft = 1;
            }
        }
        goldHook->SetSpriteRotation(m_fHookRotation); // 设置钩子的当前角度*/
    }
    else if (m_iHookState == 1 || m_iHookState == 2)
    { // 当钩子伸出后才需要画线
        // 首先，从矿工精灵上获取一个缆绳链接点作为绳子的起始点(该链接点在编辑器里编辑好)
        float fStartX = goldMan->GetSpriteLinkPointPosX(1);
        float fStartY = goldMan->GetSpriteLinkPointPosY(1);
        // 绳子终点在钩子精灵上获取(该链接点在编辑器里编辑好)
        float fEndX = goldHook->GetSpriteLinkPointPosX(1);
        float fEndY = goldHook->GetSpriteLinkPointPosY(1);
        // 在这两点之间划线.线的颜色红绿蓝值都为50，即灰色；255表示不透明，2.0f表示线的粗细，0表示所在的层
        CSystem::DrawLine(fStartX, fStartY, fEndX, fEndY, 2.f, 0, 50, 10, 10, 255);
        	if(m_iHookState == 2){		//回拉过程中
			float	fSpeedX	=	goldHook->GetSpriteLinearVelocityX();	//获取钩子X方向的速度
			float	fSpeedY	=	goldHook->GetSpriteLinearVelocityY();	//获取钩子Y方向的速度
			//当速度接近为0时，即可判定其已到达初始点
			if( fSpeedX < 0.00001f && fSpeedX > -0.00001f && fSpeedY < 0.00001f && fSpeedY > -0.00001f ){
				m_gotGold->SpriteDismount();	//解除金块与钩子的锚定
				//m_gotRock->SpriteDismount();
				m_gotGold->DeleteSprite();		//删除获取的金块
				//m_gotRock->DeleteSprite();
				m_iHookState = 0;				//回拉结束，设定钩子状态为0,继续来回摆动
				goldMan->AnimateSpritePlayAnimation("GolderManAnimation2", false);	//播放矿工的动画，即准备拉金子的动画
			}
		}

    }
}
//=============================================================================
//
// 本局游戏结束
void CGameMain::GameEnd()
{
    m_fTotalTime = 0.0f;
}
//==========================================================================
//
// 引擎捕捉鼠标移动消息后，将调用到本函数
void CGameMain::OnMouseMove(const float fMouseX, const float fMouseY)
{
    // 可以在此添加游戏需要的响应函数
}
//==========================================================================
//
// 引擎捕捉鼠标点击消息后，将调用到本函数
void CGameMain::OnMouseClick(const int iMouseType, const float fMouseX, const float fMouseY)
{
    // 可以在此添加游戏需要的响应函数
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
    if (iKey == KEY_SPACE && m_iGameState == 0)
        SetGameState(1);
    if (KEY_DOWN == iKey && m_iHookState == 0)
    {                     // 按下↓并且游戏状态为“1”
        m_iHookState = 1; // 置游戏状态为1，可用于控制钩子是否摆动
        // 以当前朝向给钩子一个向前的速度
        goldHook->SetSpriteLinearVelocityPolar(m_fHookSpeed, m_fHookRotation);
        // 播放挖金者的动作(一个胳膊往下压的动作)
        goldMan->AnimateSpritePlayAnimation("GolderManAnimation3", 0); // 0 表示播放一次，这里胳膊往下压就是一次
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
    if (strcmp(szSrcName, "goldhook") == 0 && strstr(szTarName, "GoldBlock") != NULL)
    {
        m_fHookSpeed=10.f;
        m_gotGold=FindGoldSpriteByName(szTarName); // 在golds中查找是否存在对应的金块，并返回CSprite*指针指向该金块
        if (m_gotGold != NULL)
        {
            m_gotGold->SpriteMountToSpriteLinkPoint("goldhook", 2);                      // 将金块锚定在钩子上
            goldHook->SpriteMoveTo(m_fHookStartPosX, m_fHookStartPosY, m_fHookSpeed, 1); // 使钩子向初始位置移动，即回拉
            goldMan->AnimateSpritePlayAnimation("GolderManAnimation3", true);           // 播放拉金块的动作
            m_iHookState = 2;		                                                     //表示金块回拉的状态
        }
    }
    else if (strcmp(szSrcName, "goldhook") == 0 && strstr(szTarName, "Rock") != NULL)
    {
        m_fHookSpeed=5.f;
        m_gotGold=FindGoldSpriteByName(szTarName); // 在golds中查找是否存在对应的石块，并返回CSprite*指针指向该金块
        if (m_gotGold != NULL)
        {
            m_gotGold->SpriteMountToSpriteLinkPoint("goldhook", 2);                      // 将金块锚定在钩子上
            goldHook->SpriteMoveTo(m_fHookStartPosX, m_fHookStartPosY, m_fHookSpeed, 1); // 使钩子向初始位置移动，即回拉
            goldMan->AnimateSpritePlayAnimation("GolderManAnimation2", false);           // 播放拉金块的动作
            m_iHookState = 2;
            m_fHookSpeed=5.f;	                                                     //表示石块回拉的状态
        }
    }
    m_fHookSpeed=30.f;
}

//===========================================================================
//
// 引擎捕捉到精灵与世界边界碰撞之后，调用此函数.
// iColSide : 0 左边，1 右边，2 上边，3 下边
void CGameMain::OnSpriteColWorldLimit(const char *szName, const int iColSide)
{
	if(strcmp(szName,"goldhook") == 0){		//碰到边界的为钩子时
			goldHook->SpriteMoveTo(m_fHookStartPosX, m_fHookStartPosY, m_fHookSpeed, 1);
		goldMan->AnimateSpritePlayAnimation("GolderManAnimation3", false );
		m_iHookState = 2;	//同样设置为回拉，只是没有碰到金子
	}
}
CSprite *CGameMain::FindGoldSpriteByName(const char *szName)
{
    for (int i = 0; i < golds.size(); i++)
        if (strcmp(szName, golds[i]->GetName()) == 0)
            return golds[i];
    for(int i=0;i<rocks.size();i++){
        if (strcmp(szName, rocks[i]->GetName()) == 0)
            return rocks[i];
    }
    //return NULL;
}
