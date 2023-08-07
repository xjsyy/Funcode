/***********************************************************
* 版权所有 (C)2023, caozhiqiang,yangyvchun,luoweihao,lvchanglu
*
* 文件名称：LessonX.c
* 文件标识：无
* 内容摘要：主体功能实现
* 其它说明：无
* 当前版本： V1.0
* 作   者：曹志强，杨钰春，罗维浩，吕昶陆
* 完成日期： 20230530
*
* 修改记录1：
* 修改日期： 20230530
* 版本号： V1.0
* 修改人： 曹志强，杨钰春，罗维浩，吕昶陆
* 修改内容：创建
**********************************************************/



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
/*********************************************************
* 功能描述：为指针分配对象
* 输入参数： 无
* 输出参数： 无
* 返回值： 无
* 其它说明：无
************************************************************/
// 构造函数
CGameMain::CGameMain()
{
    m_iGameState=0;
    m_pStartBack=new CSprite("start0");
    m_pRemieTitle=new CSprite("start1");
    m_pInfo=new CSprite("info");
    m_pBackground=new CSprite("bg");
    m_pBegintext=new CSprite("begintext");

    m_pScore=new CTextSprite("score");
    m_pTitle=new CTextSprite("socretitle");
    m_pWinText=new CTextSprite("wintext");
    m_pExitText=new CTextSprite("endtext");

    m_pFlag=new CSprite("flag");
}
//==============================================================================
//
/*********************************************************
* 功能描述：清理和资源释放
* 输入参数： 无
* 输出参数： 无
* 返回值： 无
* 其它说明：无
************************************************************/

// 析构函数
CGameMain::~CGameMain()
{
}

//==============================================================================
//
/*********************************************************
* 功能描述：游戏主循环
* 输入参数： fDeltaTime
* 输出参数： 无
* 返回值： 无
* 其它说明：无
************************************************************/
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
        break;
	case 3:
		{
			// TODO 修改此处游戏循环条件，完成正确游戏逻辑
			if( m_iPlayerState==1 )
			{
				GameRun( fDeltaTime );
			}
			else // 游戏结束。调用游戏结算函数，并把游戏状态修改为结束状态
			{

				GameEnd();
			}
		}
		break;
    case 4:
        break;

		// 游戏结束/等待按空格键开始
	case 0:
        GameReady();
        break;
	default:
		break;
	};
}
//=============================================================================
//
/*********************************************************
* 功能描述：初始化关卡
* 输入参数： 无
* 输出参数： 无
* 返回值： 无
* 其它说明：无
************************************************************/
// 每局开始前进行初始化，清空上一局相关数据
void CGameMain::GameInit(){
    m_pStartBack->SetSpriteVisible(false);
    m_pRemieTitle->SetSpriteVisible(false);
    m_pInfo->SetSpriteVisible(false);
    m_iPlayerState=1;
    m_iScore=0;
    m_pBackground->SetSpritePosition(225.f,0.f);

}

//=============================================================================
//
/*********************************************************
* 功能描述：设置精灵是否可见
* 输入参数： 无
* 输出参数： 无
* 返回值： 无
* 其它说明：无
************************************************************/
//游戏的准备阶段
void CGameMain::GameReady(){
    m_pScore->SetTextValue(0);
    m_pStartBack->SetSpriteVisible(true);
    m_pRemieTitle->SetSpriteVisible(true);


    m_pInfo->SetSpriteVisible(true);


    m_pScore->SetSpriteVisible(false);
    m_pTitle->SetSpriteVisible(false);
    m_pExitText->SetSpriteVisible(false);
    m_pWinText->SetSpriteVisible(false);
}


//=============================================================================
//
// 每局游戏进行中

/*********************************************************
* 功能描述：游戏运行时函数
* 输入参数： fDeltaTime
* 输出参数： 无
* 返回值： 无
* 其它说明：无
************************************************************/
void CGameMain::GameRun( float fDeltaTime )
{
    m_fTotalTime+=fDeltaTime;
    m_pScore->SetSpriteVisible(true);
    m_pTitle->SetSpriteVisible(true);
    m_pScore->SetTextValue(m_iScore);
    m_pBackground->SetSpriteLinearVelocity(-20.f,0.f);
    for(int i=0;i<(int)m_vWeapon.size();i++){
        m_vWeapon[i]->OnMove();
    }

}
//=============================================================================
//
/*********************************************************
* 功能描述：清理精灵，处理结束画面
* 输入参数： 无
* 输出参数： 无
* 返回值： 无
* 其它说明：无
************************************************************/
// 本局游戏结束
void CGameMain::GameEnd()
{

    m_pBackground->SetSpriteLinearVelocity(0.f,0.f);
    if(m_iPlayerState==2){
        m_pExitText->SetSpritePosition(0.f,0.f);
        m_pExitText->SetSpriteVisible(true);
    }
    else if(m_iPlayerState==3){
        m_pWinText->SetSpritePosition(59.f,-3.5f);
        m_pWinText->SetSpriteVisible(true);
    }
    for(auto it : m_vWeapon){
        it->DeleteSprite();
    }
    m_vWeapon.clear();
    m_iGameState=4;
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
}
//==========================================================================

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
	if(m_iGameState==0){
        if(iKey==KEY_1){
            m_iLevelState=1;
            m_iGameState=1;
            m_pBegintext->SetSpriteVisible(true);
        }
        if(iKey==KEY_2){
            m_iLevelState=2;
            m_iGameState=1;
            m_pBegintext->SetSpriteVisible(true);
        }
        if(iKey==KEY_3){
            m_iLevelState=3;
            m_iGameState=1;
            m_pBegintext->SetSpriteVisible(true);
        }
        if(iKey==KEY_4){
            m_iLevelState=4;
            m_iGameState=1;
            m_pBegintext->SetSpriteVisible(true);
        }
	}
	if(m_iGameState==2){
        if(iKey==KEY_SPACE){
            m_pBegintext->SetSpriteVisible(false);
            switch(m_iLevelState){
            case 1:
                BuildLevel1();
                break;
            case 2:
                BuildLevel2();
                break;
            case 3:
                BuildLevel3();
                break;
            case 4:
                BuildLevel4();
                break;
            }
            m_iGameState=3;
        }
	}
    if(m_iGameState==4&&m_iPlayerState!=1){
        if(iKey==KEY_SPACE){
            m_iGameState=0;
        }
	}
    if(m_iGameState==3){
        if(iKey==KEY_W){
            m_pPlayer->setSpeedY(-25.f);
            m_pPlayer->AnimateSpritePlayAnimation("jumpAnimation",0);
        }
        if(iKey==KEY_D){
            m_pPlayer->AnimateSpritePlayAnimation("skyingAnimation",0);
            m_pPlayer->SetSpritePositionY(24.f);
        }
        if(iKey==KEY_K){
            count++;
            if(count%2==0){
                m_pPillar1->SetSpriteCollisionActive(0,0); //设置为不接受碰撞
	            m_pPillar1->SetSpriteCollisionResponse(COL_RESPONSE_OFF);
                m_pPillar2->SetSpriteCollisionActive(0,0); //设置为不接受碰撞
	            m_pPillar2->SetSpriteCollisionResponse(COL_RESPONSE_OFF);
            }else{
                m_pPillar1->SetSpriteCollisionActive(0,1); //设置为接受碰撞
	            m_pPillar1->SetSpriteCollisionResponse(COL_RESPONSE_CUSTOM);
                m_pPillar2->SetSpriteCollisionActive(0,1); //设置为接受碰撞
	            m_pPillar2->SetSpriteCollisionResponse(COL_RESPONSE_CUSTOM);
            }
        }
    }
}
//==========================================================================
//
/*********************************************************
* 功能描述：键盘接口函数，实现键盘操作
* 输入参数： iKey
* 输出参数： 无
* 返回值： 无
* 其它说明：无
************************************************************/
// 引擎捕捉键盘弹起消息后，将调用到本函数
void CGameMain::OnKeyUp( const int iKey )
{
	//如果松开的是W，则置速度为-10
	if(m_iGameState==3){
        if(iKey==KEY_W){
            m_pPlayer->setSpeedY(25.f);
        }
        if(iKey==KEY_D){
            m_pPlayer->AnimateSpritePlayAnimation("Ro11Animation",0);
            m_pPlayer->SetSpritePositionY(19.f);
        }
    }

}

//===========================================================================
//
/*********************************************************
* 功能描述：处理精灵与精灵碰撞反应
* 输入参数： *szSrcName，*szTarName
* 输出参数： 无
* 返回值： 无
* 其它说明：无
************************************************************/
// 引擎捕捉到精灵与精灵碰撞之后，调用此函数
void CGameMain::OnSpriteColSprite( const char *szSrcName, const char *szTarName ){
    if(m_iGameState==3){

        if(strstr(szTarName,"rewards") != NULL){
            m_iScore++;
            DeleteWeaponByName(szTarName);
        }
        if(strstr(szTarName,"pillars") != NULL){
            m_iPlayerState=2;
        }
        if(strstr(szTarName,"Monsters") != NULL){
            m_iPlayerState=2;
        }
        if(strstr(szTarName,"finalsreward") != NULL){
            m_iPlayerState=3;
        }
    }
}

//===========================================================================
//
/*********************************************************
* 功能描述：处理精灵与世界碰撞反应
* 输入参数： *szTarName，*szSrcName
* 输出参数： 无
* 返回值： 无
* 其它说明：无
************************************************************/
// 引擎捕捉到精灵与世界边界碰撞之后，调用此函数.
// iColSide : 0 左边，1 右边，2 上边，3 下边
void CGameMain::OnSpriteColWorldLimit( const char *szName, const int iColSide )
{

}
/*********************************************************
* 功能描述：设计第一关游戏机制
* 输入参数： 无
* 输出参数： 无
* 返回值： 无
* 其它说明：无
************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////      试玩关卡一由曹志强制作     //////////////////////////////
void CGameMain::BuildLevel1(){
    char* szName;
    CPillar* m_pPillar1;
    CMonster *m_pMonster1;
    CReward *m_pReward;
    int m_iMonsterNum=0;
    int m_iPillarNum=0;
    int m_iRewardNum=0;
    //the player init
    m_pPlayer=new CPlayer("myplayer");
    m_pPlayer->CloneSprite("player");
    m_pPlayer->init();
    m_vWeapon.push_back(m_pPlayer);

    // pillar1 init()
    szName=CSystem::MakeSpriteName("pillars",++m_iPillarNum);
    m_pPillar1=new CPillar(szName);
    m_pPillar1->CloneSprite("pillar1");
    m_pPillar1->setSpeedX(-20.f);
    m_pPillar1->setSpeedY(0.f);
    m_pPillar1->setPosX(50.f);
    m_pPillar1->setPosY(-12.f);
    m_pPillar1->init();
    m_vWeapon.push_back(m_pPillar1);

    szName=CSystem::MakeSpriteName("pillars",++m_iPillarNum);
    m_pPillar1=new CPillar(szName);
    m_pPillar1->CloneSprite("pillar2");
    m_pPillar1->setSpeedX(-20.f);
    m_pPillar1->setSpeedY(0.f);
    m_pPillar1->setPosX(100.f);
    m_pPillar1->setPosY(-12.f);
    m_pPillar1->init();
    m_vWeapon.push_back(m_pPillar1);


    // monster init()
    szName=CSystem::MakeSpriteName("Monsters",++m_iMonsterNum);
    m_pMonster1=new CMonster(szName);
    m_pMonster1->CloneSprite("turtle");
    m_pMonster1->setSpeedX(-60.f);
    m_pMonster1->setSpeedY(0.f);
    m_pMonster1->setPosX(30.f);
    m_pMonster1->setPosY(12.f);
    m_pMonster1->init();
    m_vWeapon.push_back(m_pMonster1);


    // reward init()
    szName=CSystem::MakeSpriteName("rewards",++m_iRewardNum);
    m_pReward=new CReward(szName);
    m_pReward->CloneSprite("gold");
    m_pReward->setSpeedX(-20.f);
    m_pReward->setSpeedY(0.f);
    m_pReward->setPosX(70.f);
    m_pReward->setPosY(5.f);
    m_pReward->init();
    m_vWeapon.push_back(m_pReward);


    //finals reward

    m_pReward=new CReward("finalsreward");
    m_pReward->CloneSprite("finals");
    m_pReward->setSpeedX(-20.f);
    m_pReward->setSpeedY(0.f);
    m_pReward->setPosX(200.f);
    m_pReward->setPosY(0.f);
    m_pReward->init();
    m_vWeapon.push_back(m_pReward);
}
/*********************************************************
* 功能描述：设计第二关游戏机制
* 输入参数： 无
* 输出参数： 无
* 返回值： 无
* 其它说明：无
************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////       关卡二由杨钰春制作        /////////////////////////////
void CGameMain::BuildLevel2(){
    char* szName;
    //CPillar* m_pPillar1;
    //CPillar* m_pPillar4;
    CMonster *m_pMonster1;
    CReward *m_pReward;
    int m_iMonsterNum=0;
    int m_iPillarNum=0;
    int m_iRewardNum=0;

    //the player init
    m_pPlayer=new CPlayer("myplayer");
    m_pPlayer->CloneSprite("player");
    m_pPlayer->init();
    m_vWeapon.push_back(m_pPlayer);

    // pillar1 init()
    szName=CSystem::MakeSpriteName("pillars",++m_iPillarNum);
    m_pPillar1=new CPillar(szName);
    m_pPillar1->CloneSprite("pillar1");
    m_pPillar1->setSpeedX(0.f);
    m_pPillar1->setSpeedY(0.f);
    m_pPillar1->setPosX(50.f);
    m_pPillar1->setPosY(-12.f);
    m_pPillar1->init();
    m_vWeapon.push_back(m_pPillar1);


    //pillar2 init()
    szName=CSystem::MakeSpriteName("pillars",++m_iPillarNum);
    m_pPillar2=new CPillar(szName);
    m_pPillar2->CloneSprite("pillar2");
    m_pPillar2->setSpeedX(-20.f);
    m_pPillar2->setSpeedY(0.f);
    m_pPillar2->setPosX(150.f);
    m_pPillar2->setPosY(-12.f);
    m_pPillar2->init();
    m_vWeapon.push_back(m_pPillar2);

    //pillar3 init()
    szName=CSystem::MakeSpriteName("pillars",++m_iPillarNum);
    m_pPillar1=new CPillar(szName);
    m_pPillar1->CloneSprite("pillar3");
    m_pPillar1->setSpeedX(-20.f);
    m_pPillar1->setSpeedY(0.f);
    m_pPillar1->setPosX(200.f);
    m_pPillar1->setPosY(-12.f);
    m_pPillar1->init();
    m_vWeapon.push_back(m_pPillar1);

    // pillar init()
    for(int iBLoop=0;iBLoop<3;iBLoop++){
        szName=CSystem::MakeSpriteName("Monsters",++m_iMonsterNum);
        m_pMonster1=new CMonster(szName);
        m_pMonster1->CloneSprite("obstacle3");
        float iBPosY = CSystem::RandomRange(24, 24);
        float iBPosX = CSystem::RandomRange(69,350);
        m_pMonster1->setPosX(iBPosX);
        m_pMonster1->setPosY(iBPosY);
        m_pMonster1->setSpeedX(-20.f);
        m_pMonster1->setSpeedY(0.f);
        m_pMonster1->init();
        m_vWeapon.push_back(m_pMonster1);
    }
    // monster_turtle init()
    szName=CSystem::MakeSpriteName("Monsters",++m_iMonsterNum);
    m_pMonster1=new CMonster(szName);
    m_pMonster1->CloneSprite("turtle");
    m_pMonster1->setSpeedX(0.f);
    m_pMonster1->setSpeedY(0.f);
    m_pMonster1->setPosX(170.f);
    m_pMonster1->setPosY(12.f);
    m_pMonster1->init();
    m_vWeapon.push_back(m_pMonster1);
    //monster_2 init()
    szName=CSystem::MakeSpriteName("Monsters",++m_iMonsterNum);
    m_pMonster1=new CMonster(szName);
    m_pMonster1->CloneSprite("missile");
    m_pMonster1->setSpeedX(-10.f);
    m_pMonster1->setSpeedY(0.f);
    m_pMonster1->setPosX(170.f);
    m_pMonster1->setPosY(18.f);
    m_pMonster1->init();
    m_vWeapon.push_back(m_pMonster1);

    //monster_lion init()
    szName=CSystem::MakeSpriteName("Monsters",++m_iMonsterNum);
    m_pMonster1=new CMonster(szName);
    m_pMonster1->CloneSprite("lion");
    m_pMonster1->setSpeedX(-40.f);
    m_pMonster1->setSpeedY(0.f);
    m_pMonster1->setPosX(190.f);
    m_pMonster1->setPosY(24.f);
    m_pMonster1->init();
    m_vWeapon.push_back(m_pMonster1);

    //monster_fake init()
    szName=CSystem::MakeSpriteName("Monsters",++m_iMonsterNum);
    m_pMonster1=new CMonster(szName);
    m_pMonster1->CloneSprite("fake");
    m_pMonster1->setSpeedX(-20.f);
    m_pMonster1->setSpeedY(0.f);
    m_pMonster1->setPosX(370.f);
    m_pMonster1->setPosY(0.f);
    m_pMonster1->init();
    m_vWeapon.push_back(m_pMonster1);


    // reward init()
    for(int iBLoop=0;iBLoop<20;iBLoop++){
        szName=CSystem::MakeSpriteName("rewards",++m_iRewardNum);
        m_pReward=new CReward(szName);
        m_pReward->CloneSprite("gold");
        float iBPosY = CSystem::RandomRange(-25, 25);
        float iBPosX = CSystem::RandomRange(49,350);
        m_pReward->setPosX(iBPosX);
        m_pReward->setPosY(iBPosY);
        m_pReward->setSpeedX(-20.f);
        m_pReward->setSpeedY(0.f);
        m_pReward->init();
        m_vWeapon.push_back(m_pReward);
    }

    //finals reward

    m_pReward=new CReward("finalsreward");
    m_pReward->CloneSprite("finals");
    m_pReward->setSpeedX(-20.f);
    m_pReward->setSpeedY(0.f);
    m_pReward->setPosX(420.f);
    m_pReward->setPosY(0.f);
    m_pReward->init();
    m_vWeapon.push_back(m_pReward);
}
/*********************************************************
* 功能描述：设计第三关游戏机制
* 输入参数： 无
* 输出参数： 无
* 返回值： 无
* 其它说明：无
************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////       关卡三由罗维浩制作        /////////////////////////////
void CGameMain::BuildLevel3(){
	char* szName;
    CPillar* m_pPillar1;
    CMonster *m_pMonster1;
    CReward *m_pReward;
    int m_iMonsterNum=0;
    int m_iPillarNum=0;
    int m_iRewardNum=0;
    //the player init
    m_pPlayer=new CPlayer("myplayer");
    m_pPlayer->CloneSprite("player");
    m_pPlayer->init();
    m_vWeapon.push_back(m_pPlayer);

    // pillar1 init()
    szName=CSystem::MakeSpriteName("pillars",++m_iPillarNum);
    m_pPillar1=new CPillar(szName);
    m_pPillar1->CloneSprite("pillar1");
    m_pPillar1->setSpeedX(-20.f);
    m_pPillar1->setSpeedY(0.f);
    m_pPillar1->setPosX(50.f);
    m_pPillar1->setPosY(-12.f);
    m_pPillar1->init();
    m_vWeapon.push_back(m_pPillar1);

    szName=CSystem::MakeSpriteName("pillars",++m_iPillarNum);
    m_pPillar1=new CPillar(szName);
    m_pPillar1->CloneSprite("pillar1");
    m_pPillar1->setSpeedX(-25.f);
    m_pPillar1->setSpeedY(0.f);
    m_pPillar1->setPosX(225.f);
    m_pPillar1->setPosY(-12.f);
    m_pPillar1->init();
    m_vWeapon.push_back(m_pPillar1);

    szName=CSystem::MakeSpriteName("pillars",++m_iPillarNum);
    m_pPillar1=new CPillar(szName);
    m_pPillar1->CloneSprite("pillar1");
    m_pPillar1->setSpeedX(-20.f);
    m_pPillar1->setSpeedY(0.f);
    m_pPillar1->setPosX(275.f);
    m_pPillar1->setPosY(-12.f);
    m_pPillar1->init();
    m_vWeapon.push_back(m_pPillar1);


    szName=CSystem::MakeSpriteName("pillars",++m_iPillarNum);
    m_pPillar1=new CPillar(szName);
    m_pPillar1->CloneSprite("pillar2");
    m_pPillar1->setSpeedX(-20.f);
    m_pPillar1->setSpeedY(0.f);
    m_pPillar1->setPosX(100.f);
    m_pPillar1->setPosY(-12.f);
    m_pPillar1->init();
    m_vWeapon.push_back(m_pPillar1);

    szName=CSystem::MakeSpriteName("pillars",++m_iPillarNum);
    m_pPillar1=new CPillar(szName);
    m_pPillar1->CloneSprite("pillar2");
    m_pPillar1->setSpeedX(-20.f);
    m_pPillar1->setSpeedY(0.f);
    m_pPillar1->setPosX(150.f);
    m_pPillar1->setPosY(-12.f);
    m_pPillar1->init();
    m_vWeapon.push_back(m_pPillar1);

    szName=CSystem::MakeSpriteName("pillars",++m_iPillarNum);
    m_pPillar1=new CPillar(szName);
    m_pPillar1->CloneSprite("pillar2");
    m_pPillar1->setSpeedX(-20.f);
    m_pPillar1->setSpeedY(0.f);
    m_pPillar1->setPosX(300.f);
    m_pPillar1->setPosY(-12.f);
    m_pPillar1->init();
    m_vWeapon.push_back(m_pPillar1);


    // monster init()
    szName=CSystem::MakeSpriteName("Monsters",++m_iMonsterNum);
    m_pMonster1=new CMonster(szName);
    m_pMonster1->CloneSprite("turtle");
    m_pMonster1->setSpeedX(-60.f);
    m_pMonster1->setSpeedY(0.f);
    m_pMonster1->setPosX(30.f);
    m_pMonster1->setPosY(12.f);
    m_pMonster1->init();
    m_vWeapon.push_back(m_pMonster1);

 // monster init()
    szName=CSystem::MakeSpriteName("Monsters",++m_iMonsterNum);
    m_pMonster1=new CMonster(szName);
    m_pMonster1->CloneSprite("turtle");
    m_pMonster1->setSpeedX(-30.f);
    m_pMonster1->setSpeedY(0.f);
    m_pMonster1->setPosX(100.f);
    m_pMonster1->setPosY(12.f);
    m_pMonster1->init();
    m_vWeapon.push_back(m_pMonster1);


 // monster init()
    szName=CSystem::MakeSpriteName("Monsters",++m_iMonsterNum);
    m_pMonster1=new CMonster(szName);
    m_pMonster1->CloneSprite("turtle");
    m_pMonster1->setSpeedX(-20.f);
    m_pMonster1->setSpeedY(0.f);
    m_pMonster1->setPosX(225.f);
    m_pMonster1->setPosY(20.f);
    m_pMonster1->init();
    m_vWeapon.push_back(m_pMonster1);

 // monster init()
    szName=CSystem::MakeSpriteName("Monsters",++m_iMonsterNum);
    m_pMonster1=new CMonster(szName);
    m_pMonster1->CloneSprite("turtle");
    m_pMonster1->setSpeedX(-22.f);
    m_pMonster1->setSpeedY(0.f);
    m_pMonster1->setPosX(250.f);
    m_pMonster1->setPosY(15.f);
    m_pMonster1->init();
    m_vWeapon.push_back(m_pMonster1);

     // monster init()
    szName=CSystem::MakeSpriteName("Monsters",++m_iMonsterNum);
    m_pMonster1=new CMonster(szName);
    m_pMonster1->CloneSprite("turtle");
    m_pMonster1->setSpeedX(-20.f);
    m_pMonster1->setSpeedY(0.f);
    m_pMonster1->setPosX(350.f);
    m_pMonster1->setPosY(20.f);
    m_pMonster1->init();
    m_vWeapon.push_back(m_pMonster1);

     // monster init()
    szName=CSystem::MakeSpriteName("Monsters",++m_iMonsterNum);
    m_pMonster1=new CMonster(szName);
    m_pMonster1->CloneSprite("turtle");
    m_pMonster1->setSpeedX(-20.f);
    m_pMonster1->setSpeedY(0.f);
    m_pMonster1->setPosX(350.f);
    m_pMonster1->setPosY(15.f);
    m_pMonster1->init();
    m_vWeapon.push_back(m_pMonster1);

     // monster init()
    szName=CSystem::MakeSpriteName("Monsters",++m_iMonsterNum);
    m_pMonster1=new CMonster(szName);
    m_pMonster1->CloneSprite("turtle");
    m_pMonster1->setSpeedX(-20.f);
    m_pMonster1->setSpeedY(0.f);
    m_pMonster1->setPosX(350.f);
    m_pMonster1->setPosY(10.f);
    m_pMonster1->init();
    m_vWeapon.push_back(m_pMonster1);

    // reward init()
    for(int iBLoop=0;iBLoop<20;iBLoop++){
        szName=CSystem::MakeSpriteName("rewards",++m_iRewardNum);
        m_pReward=new CReward(szName);
        m_pReward->CloneSprite("gold");
        float iBPosY = CSystem::RandomRange(-25, 25);
        float iBPosX = CSystem::RandomRange(49,350);
        m_pReward->setPosX(iBPosX);
        m_pReward->setPosY(iBPosY);
        m_pReward->setSpeedX(-20.f);
        m_pReward->setSpeedY(0.f);
        m_pReward->init();
        m_vWeapon.push_back(m_pReward);
    }


    //finals reward

    m_pReward=new CReward("finalsreward");
    m_pReward->CloneSprite("finals");
    m_pReward->setSpeedX(-20.f);
    m_pReward->setSpeedY(0.f);
    m_pReward->setPosX(450.f);
    m_pReward->setPosY(0.f);
    m_pReward->init();
    m_vWeapon.push_back(m_pReward);
}
/*********************************************************
* 功能描述：设计第四关游戏机制
* 输入参数： 无
* 输出参数： 无
* 返回值： 无
* 其它说明：无
************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////       关卡四由吕昶陆制作        /////////////////////////////
void CGameMain::BuildLevel4(){
    char* szName;
    CPillar* m_pPillar1;
    CMonster *m_pMonster1;
    CReward *m_pReward;
    int m_iMonsterNum=0;
    int m_iPillarNum=0;
    int m_iRewardNum=0;
    //the player init
    m_pPlayer=new CPlayer("myplayer");
    m_pPlayer->CloneSprite("player");
    m_pPlayer->init();
    m_vWeapon.push_back(m_pPlayer);


     szName=CSystem::MakeSpriteName("pillars",++m_iPillarNum);
    m_pPillar1=new CPillar(szName);
    m_pPillar1->CloneSprite("pillar1");
    m_pPillar1->setSpeedX(10.f);
    m_pPillar1->setSpeedY(0.f);
    m_pPillar1->setPosX(10.f);
    m_pPillar1->setPosY(-30.f);
    m_pPillar1->init();
    m_vWeapon.push_back(m_pPillar1);

    szName=CSystem::MakeSpriteName("pillars",++m_iPillarNum);
    m_pPillar1=new CPillar(szName);
    m_pPillar1->CloneSprite("pillar2");
    m_pPillar1->setSpeedX(-20.f);
    m_pPillar1->setSpeedY(0.f);
    m_pPillar1->setPosX(20.f);
    m_pPillar1->setPosY(-20.f);
    m_pPillar1->init();
    m_vWeapon.push_back(m_pPillar1);


    szName=CSystem::MakeSpriteName("pillars",++m_iPillarNum);
    m_pPillar1=new CPillar(szName);
    m_pPillar1->CloneSprite("pillar3");
    m_pPillar1->setSpeedX(10.f);
    m_pPillar1->setSpeedY(0.f);
    m_pPillar1->setPosX(30.f);
    m_pPillar1->setPosY(-30.f);
    m_pPillar1->init();
    m_vWeapon.push_back(m_pPillar1);


     szName=CSystem::MakeSpriteName("Monsters",++m_iMonsterNum);
    m_pMonster1=new CMonster(szName);
    m_pMonster1->CloneSprite("turtle");
    m_pMonster1->setSpeedX(-60.f);
    m_pMonster1->setSpeedY(0.f);
    m_pMonster1->setPosX(150.f);
    m_pMonster1->setPosY(12.f);
    m_pMonster1->init();
    m_vWeapon.push_back(m_pMonster1);

    szName=CSystem::MakeSpriteName("Monsters",++m_iMonsterNum);
    m_pMonster1=new CMonster(szName);
    m_pMonster1->CloneSprite("turtle");
    m_pMonster1->setSpeedX(-60.f);
    m_pMonster1->setSpeedY(0.f);
    m_pMonster1->setPosX(155.f);
    m_pMonster1->setPosY(12.f);
    m_pMonster1->init();
    m_vWeapon.push_back(m_pMonster1);

    szName=CSystem::MakeSpriteName("Monsters",++m_iMonsterNum);
    m_pMonster1=new CMonster(szName);
    m_pMonster1->CloneSprite("turtle");
    m_pMonster1->setSpeedX(-60.f);
    m_pMonster1->setSpeedY(0.f);
    m_pMonster1->setPosX(160.f);
    m_pMonster1->setPosY(12.f);
    m_pMonster1->init();
    m_vWeapon.push_back(m_pMonster1);

     szName=CSystem::MakeSpriteName("Monsters",++m_iMonsterNum);
    m_pMonster1=new CMonster(szName);
    m_pMonster1->CloneSprite("lion");
    m_pMonster1->setSpeedX(-20.f);
    m_pMonster1->setSpeedY(0.f);
    m_pMonster1->setPosX(200.f);
    m_pMonster1->setPosY(30.f);
    m_pMonster1->init();
    m_vWeapon.push_back(m_pMonster1);


    szName=CSystem::MakeSpriteName("Monsters",++m_iMonsterNum);
    m_pMonster1=new CMonster(szName);
    m_pMonster1->CloneSprite("missile");
    m_pMonster1->setSpeedX(-20.f);
    m_pMonster1->setSpeedY(0.f);
    m_pMonster1->setPosX(180.f);
    m_pMonster1->setPosY(10.f);
    m_pMonster1->init();
    m_vWeapon.push_back(m_pMonster1);

    szName=CSystem::MakeSpriteName("Monsters",++m_iMonsterNum);
    m_pMonster1=new CMonster(szName);
    m_pMonster1->CloneSprite("turtle");
    m_pMonster1->setSpeedX(-20.f);
    m_pMonster1->setSpeedY(0.f);
    m_pMonster1->setPosX(160.f);
    m_pMonster1->setPosY(20.f);
    m_pMonster1->init();
    m_vWeapon.push_back(m_pMonster1);

    szName=CSystem::MakeSpriteName("Monsters",++m_iMonsterNum);
    m_pMonster1=new CMonster(szName);
    m_pMonster1->CloneSprite("missile");
    m_pMonster1->setSpeedX(-50.f);
    m_pMonster1->setSpeedY(0.f);
    m_pMonster1->setPosX(300.f);
    m_pMonster1->setPosY(9.f);
    m_pMonster1->init();
    m_vWeapon.push_back(m_pMonster1);







    szName=CSystem::MakeSpriteName("rewards",++m_iRewardNum);
    m_pReward=new CReward(szName);
    m_pReward->CloneSprite("gold");
    m_pReward->setSpeedX(-20.f);
    m_pReward->setSpeedY(0.f);
    m_pReward->setPosX(70.f);
    m_pReward->setPosY(5.f);
    m_pReward->init();
    m_vWeapon.push_back(m_pReward);

    szName=CSystem::MakeSpriteName("rewards",++m_iRewardNum);
    m_pReward=new CReward(szName);
    m_pReward->CloneSprite("gold");
    m_pReward->setSpeedX(-20.f);
    m_pReward->setSpeedY(0.f);
    m_pReward->setPosX(60.f);
    m_pReward->setPosY(15.f);
    m_pReward->init();
    m_vWeapon.push_back(m_pReward);




    szName=CSystem::MakeSpriteName("rewards",++m_iRewardNum);
    m_pReward=new CReward(szName);
    m_pReward->CloneSprite("gold");
    m_pReward->setSpeedX(-20.f);
    m_pReward->setSpeedY(0.f);
    m_pReward->setPosX(100.f);
    m_pReward->setPosY(9.f);
    m_pReward->init();
    m_vWeapon.push_back(m_pReward);


    szName=CSystem::MakeSpriteName("rewards",++m_iRewardNum);
    m_pReward=new CReward(szName);
    m_pReward->CloneSprite("gold");
    m_pReward->setSpeedX(-20.f);
    m_pReward->setSpeedY(0.f);
    m_pReward->setPosX(120.f);
    m_pReward->setPosY(10.f);
    m_pReward->init();
    m_vWeapon.push_back(m_pReward);


    szName=CSystem::MakeSpriteName("rewards",++m_iRewardNum);
    m_pReward=new CReward(szName);
    m_pReward->CloneSprite("gold");
    m_pReward->setSpeedX(-20.f);
    m_pReward->setSpeedY(0.f);
    m_pReward->setPosX(110.f);
    m_pReward->setPosY(1.f);
    m_pReward->init();
    m_vWeapon.push_back(m_pReward);


    szName=CSystem::MakeSpriteName("rewards",++m_iRewardNum);
    m_pReward=new CReward(szName);
    m_pReward->CloneSprite("gold");
    m_pReward->setSpeedX(-20.f);
    m_pReward->setSpeedY(9.f);
    m_pReward->setPosX(80.f);
    m_pReward->setPosY(1.f);
    m_pReward->init();
    m_vWeapon.push_back(m_pReward);




    szName=CSystem::MakeSpriteName("rewards",++m_iRewardNum);
    m_pReward=new CReward(szName);
    m_pReward->CloneSprite("gold");
    m_pReward->setSpeedX(10.f);
    m_pReward->setSpeedY(0.f);
    m_pReward->setPosX(20.f);
    m_pReward->setPosY(-35.f);
    m_pReward->init();
    m_vWeapon.push_back(m_pReward);


     m_pReward=new CReward("finalsreward");
    m_pReward->CloneSprite("finals");
    m_pReward->setSpeedX(-20.f);
    m_pReward->setSpeedY(0.f);
    m_pReward->setPosX(300.f);
    m_pReward->setPosY(20.f);
    m_pReward->init();
    m_vWeapon.push_back(m_pReward);
}

/*********************************************************
* 功能描述：查找对象
* 输入参数： szName
* 输出参数： 无
* 返回值： m_vWeapon[i]
* 其它说明：无
************************************************************/
CWeapon* CGameMain::FindWeaponByName(const char* szName)//根据名字查找到对象
{
	for(int i=0; i<(int)m_vWeapon.size(); i++)
	{
			if(strcmp(szName,m_vWeapon[i]->GetName()) == 0)
			{
				return m_vWeapon[i];
			}
	}
	return NULL;
}

/*********************************************************
* 功能描述：删除精灵
* 输入参数： 无
* 输出参数： 无
* 返回值： 无
* 其它说明：无
************************************************************/
void CGameMain::DeleteWeaponByName(const char* szName)//根据名字把精灵从容器中删除
{
	for(vector<CWeapon*>::iterator it=m_vWeapon.begin();it!=m_vWeapon.end();)
	{
		CWeapon* cw =*it;
		if(strcmp(szName,cw->GetName()) == 0)
		{
			m_vWeapon.erase(it);
			cw->DeleteSprite();
			delete cw;
			break;
		}
		else
		{
			it++;
		}
	}
}
