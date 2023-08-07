/***********************************************************
* ��Ȩ���� (C)2023, caozhiqiang,yangyvchun,luoweihao,lvchanglu
*
* �ļ����ƣ�LessonX.c
* �ļ���ʶ����
* ����ժҪ�����幦��ʵ��
* ����˵������
* ��ǰ�汾�� V1.0
* ��   �ߣ���־ǿ�����ڴ�����ά�ƣ�����½
* ������ڣ� 20230530
*
* �޸ļ�¼1��
* �޸����ڣ� 20230530
* �汾�ţ� V1.0
* �޸��ˣ� ��־ǿ�����ڴ�����ά�ƣ�����½
* �޸����ݣ�����
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
// ����ĳ�������Ϊ��GameMainLoop����Ϊ��ѭ��������������ÿ֡ˢ����Ļͼ��֮�󣬶��ᱻ����һ�Ρ�

//==============================================================================
//
/*********************************************************
* ����������Ϊָ��������
* ��������� ��
* ��������� ��
* ����ֵ�� ��
* ����˵������
************************************************************/
// ���캯��
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
* �����������������Դ�ͷ�
* ��������� ��
* ��������� ��
* ����ֵ�� ��
* ����˵������
************************************************************/

// ��������
CGameMain::~CGameMain()
{
}

//==============================================================================
//
/*********************************************************
* ������������Ϸ��ѭ��
* ��������� fDeltaTime
* ��������� ��
* ����ֵ�� ��
* ����˵������
************************************************************/
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
        break;
	case 3:
		{
			// TODO �޸Ĵ˴���Ϸѭ�������������ȷ��Ϸ�߼�
			if( m_iPlayerState==1 )
			{
				GameRun( fDeltaTime );
			}
			else // ��Ϸ������������Ϸ���㺯����������Ϸ״̬�޸�Ϊ����״̬
			{

				GameEnd();
			}
		}
		break;
    case 4:
        break;

		// ��Ϸ����/�ȴ����ո����ʼ
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
* ������������ʼ���ؿ�
* ��������� ��
* ��������� ��
* ����ֵ�� ��
* ����˵������
************************************************************/
// ÿ�ֿ�ʼǰ���г�ʼ���������һ���������
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
* �������������þ����Ƿ�ɼ�
* ��������� ��
* ��������� ��
* ����ֵ�� ��
* ����˵������
************************************************************/
//��Ϸ��׼���׶�
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
// ÿ����Ϸ������

/*********************************************************
* ������������Ϸ����ʱ����
* ��������� fDeltaTime
* ��������� ��
* ����ֵ�� ��
* ����˵������
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
* ���������������飬�����������
* ��������� ��
* ��������� ��
* ����ֵ�� ��
* ����˵������
************************************************************/
// ������Ϸ����
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
}
//==========================================================================

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
                m_pPillar1->SetSpriteCollisionActive(0,0); //����Ϊ��������ײ
	            m_pPillar1->SetSpriteCollisionResponse(COL_RESPONSE_OFF);
                m_pPillar2->SetSpriteCollisionActive(0,0); //����Ϊ��������ײ
	            m_pPillar2->SetSpriteCollisionResponse(COL_RESPONSE_OFF);
            }else{
                m_pPillar1->SetSpriteCollisionActive(0,1); //����Ϊ������ײ
	            m_pPillar1->SetSpriteCollisionResponse(COL_RESPONSE_CUSTOM);
                m_pPillar2->SetSpriteCollisionActive(0,1); //����Ϊ������ײ
	            m_pPillar2->SetSpriteCollisionResponse(COL_RESPONSE_CUSTOM);
            }
        }
    }
}
//==========================================================================
//
/*********************************************************
* �������������̽ӿں�����ʵ�ּ��̲���
* ��������� iKey
* ��������� ��
* ����ֵ�� ��
* ����˵������
************************************************************/
// ���沶׽���̵�����Ϣ�󣬽����õ�������
void CGameMain::OnKeyUp( const int iKey )
{
	//����ɿ�����W�������ٶ�Ϊ-10
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
* �����������������뾫����ײ��Ӧ
* ��������� *szSrcName��*szTarName
* ��������� ��
* ����ֵ�� ��
* ����˵������
************************************************************/
// ���沶׽�������뾫����ײ֮�󣬵��ô˺���
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
* ������������������������ײ��Ӧ
* ��������� *szTarName��*szSrcName
* ��������� ��
* ����ֵ�� ��
* ����˵������
************************************************************/
// ���沶׽������������߽���ײ֮�󣬵��ô˺���.
// iColSide : 0 ��ߣ�1 �ұߣ�2 �ϱߣ�3 �±�
void CGameMain::OnSpriteColWorldLimit( const char *szName, const int iColSide )
{

}
/*********************************************************
* ������������Ƶ�һ����Ϸ����
* ��������� ��
* ��������� ��
* ����ֵ�� ��
* ����˵������
************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////      ����ؿ�һ�ɲ�־ǿ����     //////////////////////////////
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
* ������������Ƶڶ�����Ϸ����
* ��������� ��
* ��������� ��
* ����ֵ�� ��
* ����˵������
************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////       �ؿ��������ڴ�����        /////////////////////////////
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
* ������������Ƶ�������Ϸ����
* ��������� ��
* ��������� ��
* ����ֵ�� ��
* ����˵������
************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////       �ؿ�������ά������        /////////////////////////////
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
* ������������Ƶ��Ĺ���Ϸ����
* ��������� ��
* ��������� ��
* ����ֵ�� ��
* ����˵������
************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////       �ؿ���������½����        /////////////////////////////
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
* �������������Ҷ���
* ��������� szName
* ��������� ��
* ����ֵ�� m_vWeapon[i]
* ����˵������
************************************************************/
CWeapon* CGameMain::FindWeaponByName(const char* szName)//�������ֲ��ҵ�����
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
* ����������ɾ������
* ��������� ��
* ��������� ��
* ����ֵ�� ��
* ����˵������
************************************************************/
void CGameMain::DeleteWeaponByName(const char* szName)//�������ְѾ����������ɾ��
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
