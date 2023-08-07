/////////////////////////////////////////////////////////////////////////////////
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////
#include <Stdio.h>
#include "CommonClass.h"
#include "LessonX.h"
#include "CBullet.h"
#include "CWeapon.h"
#include "CTankPlayer.h"
#include "CTankEnemy.h"
////////////////////////////////////////////////////////////////////////////////
//
//
CGameMain g_GameMain;

//==============================================================================
//
// ����ĳ�������Ϊ��GameMainLoop����Ϊ��ѭ��������������ÿ֡ˢ����Ļͼ��֮�󣬶��ᱻ����һ�Ρ�

//==============================================================================
//
// ���캯��
CGameMain::CGameMain()
{
	m_iGameState			=	0;
	m_pSplash	= new CSprite("splash");
    m_pStart	= new CSprite("start");
	m_pScore = new CTextSprite("score");
	m_pHight = new CTextSprite("hight");
	m_pEnemy = new CTextSprite("enemyNum");
	m_iScore=0;//����
	m_iEnemy=0;//��������
	m_iHight = 0;
	m_fDeltaTime = 0.f;


	count=0;
}
//==============================================================================
//
// ��������
CGameMain::~CGameMain()
{
	delete m_pSplash;
	delete m_pStart;
}

//==============================================================================
//
// ��Ϸ��ѭ�����˺���������ͣ�ĵ��ã�����ÿˢ��һ����Ļ���˺�����������һ��
// ���Դ�����Ϸ�Ŀ�ʼ�������С������ȸ���״̬.
// ��������fDeltaTime : �ϴε��ñ��������˴ε��ñ�������ʱ��������λ����
void CGameMain::GameMainLoop(float fDeltaTime)
{
	switch (GetGameState())
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
		if(!m_pTankplayer->IsDead() && !m_pAim_nor->IsDead() && m_fDeltaTime<30)
		{
			GameRun(fDeltaTime);
		}
		else // ��Ϸ������������Ϸ���㺯����������Ϸ״̬�޸�Ϊ����״̬
		{
			SetGameState(0);
			GameEnd();
		}
	}
	break;
	case 3:
	case 4:
	{ // TODO �޸Ĵ˴���Ϸѭ�������������ȷ��Ϸ�߼�
		if (true)
		{
			GameRun(fDeltaTime);
		}
		else // ��Ϸ������������Ϸ���㺯����������Ϸ״̬�޸�Ϊ����״̬
		{
			SetGameState(0);
			GameEnd();
		}
	}
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
	//m_pSplash=new CSprite("splash");
	//m_pStart=new CSprite("start");
	m_pSplash->SetSpriteVisible(false);
	m_pStart->SetSpriteVisible(false);
	m_pTankplayer=new CTankPlayer("myplayer");//�½�һ��������myPlayer���ҷ�̹�˶���
	m_pTankplayer->CloneSprite("player");//�ҷ�̹�˿�¡��funcodeģ���д��ڵ�����Ϊplayer��̹�ˣ���ʾ�½���̹�˶��������ھ������������
	m_pTankplayer->Init();
	m_vWeapon.push_back(m_pTankplayer);
	//m_pTankEnemy = new CTankEnemy("enemy");
	//m_pTankEnemy->Init();
	LoadMap();
	GrassMap();						//�ݵ�
	m_pAim_nor = new CWeapon("myaim_nor");
	m_pAim_nor->CloneSprite("aim_nor");
	m_vWeapon.push_back(m_pAim_nor);
	m_pAim_nor->SetSpriteCollisionReceive(true);
	m_pAim_nor->SetSpritePosition(0.f,20.f);
	m_fTankEnemyTime = 0.f;
	m_iTankEnemyNumber = 0;

	m_iBulletNum    =   0;
	m_iTankEnemyNumber  =  0;
	m_fTankEnemyTime = 4.f;
	m_iScore = 0;
	m_iHight = 0;
	m_iEnemy = 0;
	m_fDeltaTime = 0.f;

	FILE * fp =fopen("save.dat","r+");
	if(fp)
	{
		fread(&m_iHight,sizeof(int),1,fp);
		fclose(fp);
	}
	m_pHight = new CTextSprite("hight");
	m_pHight->SetTextValue(m_iHight);
}
//=============================================================================
//
// ÿ����Ϸ������
void CGameMain::GameRun(float fDeltaTime)
{
		// if(m_pTankEnemy)
		// {
		// 	m_pTankEnemy->OnMove(fDeltaTime);
		// 	m_pTankEnemy->OnFire(fDeltaTime);
		// }

	AddTankEnemy(fDeltaTime);
	m_fDeltaTime += fDeltaTime;
	for(int i=0;i<m_vWeapon.size();i++)
	{
		if(!m_vWeapon[i]->IsDead())
		  {

				m_vWeapon[i]->OnMove(fDeltaTime);
  				m_vWeapon[i]->OnFire(fDeltaTime);
			}
			else
			{
				DeleteWeaponByName(m_vWeapon[i]->GetName());
			}
	}
	m_pScore->SetTextValue(m_iScore);
	m_pHight->SetTextValue(m_iHight);
	m_pEnemy->SetTextValue(m_iEnemy);

}

//=============================================================================
//
// ������Ϸ����
void CGameMain::GameEnd()
{
	int n=m_vWeapon.size();
	while(m_vWeapon.size()!=0)
	{
		vector<CWeapon*>::iterator itr=m_vWeapon.begin();
		CWeapon* cw = *itr;
		m_vWeapon.erase(itr);
		cw->DeleteSprite();
		delete cw;
	}
	m_pSplash->SetSpriteVisible(true);
	m_pStart->SetSpriteVisible(true);
	SetGameState(0);

}


//==========================================================================
//
// ���沶׽����ƶ���Ϣ�󣬽����õ�������
void CGameMain::OnMouseMove(const float fMouseX, const float fMouseY)
{
	// �����ڴ������Ϸ��Ҫ����Ӧ����]

}
//==========================================================================
//
// ���沶׽�������Ϣ�󣬽����õ�������
void CGameMain::OnMouseClick(const int iMouseType, const float fMouseX, const float fMouseY)
{
	// �����ڴ������Ϸ��Ҫ����Ӧ����

}
//==========================================================================
//
// ���沶׽��굯����Ϣ�󣬽����õ�������
void CGameMain::OnMouseUp(const int iMouseType, const float fMouseX, const float fMouseY)
{
	// �����ڴ������Ϸ��Ҫ����Ӧ����
}
//==========================================================================
//
// ���沶׽���̰�����Ϣ�󣬽����õ�������
// bAltPress bShiftPress bCtrlPress �ֱ�Ϊ�ж�Shift��Alt��Ctrl��ǰ�Ƿ�Ҳ���ڰ���״̬����������ж�Ctrl+E��ϼ�
void CGameMain::OnKeyDown(const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress)
{
	// �����ڴ������Ϸ��Ҫ����Ӧ����
	if(0==GetGameState()){
		if(iKey==KEY_SPACE){
			m_iGameState=1;
		}
	}
	if(m_iGameState == 2)
	{
		m_pTankplayer->OnMove(iKey, true);
		if(iKey == KEY_J)//�жϰ��¼��ǹ�ΪJ��
		{
			m_pTankplayer->OnFire();
		}
		if(iKey==KEY_K){
			EnhanceHome();				//�ӹ��ϳ�

			//m_pTankplayer->SetSpritePosition(0,0);		//˲��

			//m_pTankplayer->SetSpeedX(m_pTankplayer->GetSpeedX()*2);		//����
			//m_pTankplayer->SetSpeedY(m_pTankplayer->GetSpeedY()*2);

			m_pTankplayer->SetHp(m_pTankplayer->GetHp()+100);				//��Ѫ�����ӽ��޵�
		}
	}
}
//==========================================================================
//
// ���沶׽���̵�����Ϣ�󣬽����õ�������
void CGameMain::OnKeyUp(const int iKey)
{
	// �����ڴ������Ϸ��Ҫ����Ӧ����
	if(m_iGameState == 2)
	{
		m_pTankplayer->OnMove(iKey, false);
	}

}

//===========================================================================
//
// ���沶׽�������뾫����ײ֮�󣬵��ô˺���
void CGameMain::OnSpriteColSprite(const char *szSrcName, const char *szTarName)
{
	CWeapon* tarSprite = FindWeaponByName(szTarName);
	if(strstr(szSrcName,"bullet") != NULL)//������ײΪ�ӵ�
	{

		CBullet *tmpBullet = (CBullet*)FindWeaponByName(szSrcName);
		tmpBullet->OnSpriteColSprite(tarSprite);
		if( tmpBullet->GetOwner()==1 && strstr(szTarName,"enemy") != NULL)
		{
			m_iScore++;
			m_iEnemy--;
		}
	}
	else if(strcmp(szSrcName,"myplayer")==0) //������ײΪ�ҷ�̹��
	{
		m_pTankplayer->OnSpriteColSprite(tarSprite);
	}
	else if(strstr(szSrcName,"enemy") != NULL)//������ײΪ�з�̹��
	{
		CTankEnemy* tmpEnemy = (CTankEnemy*)FindWeaponByName(szSrcName);
		tmpEnemy->OnSpriteColSprite(tarSprite);
	}

}

//===========================================================================
//
// ���沶׽������������߽���ײ֮�󣬵��ô˺���.
// iColSide : 0 ��ߣ�1 �ұߣ�2 �ϱߣ�3 �±�
void CGameMain::OnSpriteColWorldLimit(const char *szName, const int iColSide)
{
	if(strstr(szName,"player") != NULL) //�ж���������߽��̹���Ƿ�Ϊ�ҷ�̹��
	{
			m_pTankplayer->SetSpriteLinearVelocity(0,0);
	}
	else if(strstr(szName,"enemy") != NULL)
	{
		CWeapon* pEnemy = FindWeaponByName(szName);
		pEnemy->SetSpriteLinearVelocity(0.f,0.f);
		pEnemy->OnMove();
	}
	else if(strstr(szName,"bullet") != NULL)
	{
		CWeapon* pBullet = FindWeaponByName(szName);
		pBullet->SetHp(0);
	}



}
void CGameMain::AddBullet( int iDir,float fPosX,float fPosY ,int iOwner)
{
		char* szName = CSystem::MakeSpriteName("bullet",m_iBulletNum);//����̹������
		CBullet* pBullet = new CBullet(szName);
		// if(count%2==0){
		pBullet->CloneSprite("bullet");
		// }else{
		// 	pBullet->CloneSprite("hook");
		// }
		pBullet->SetSpriteWorldLimit(WORLD_LIMIT_NULL,-26, -22, 26, 22); //��������߽�
		pBullet->SetSpritePosition(fPosX,fPosY);
		pBullet->SetSpriteCollisionSend(true); //���ý� ����ײ
		pBullet->OnMove(iDir);
		m_iBulletNum++; //�ӵ�������1
		if(iOwner == 1)
		{
			pBullet->SetOwner(1);//1��ʾ�ҷ�̹�˷�����ӵ�
		}
		else
		{
			pBullet->SetOwner(0); //0��ʾ�ط�̹�˷�����ӵ�
		}
		m_vWeapon.push_back(pBullet);
}
void CGameMain::LoadMap()
{
		char* szName;
		int i,j;
		float x,y;
		for(i=0;i<11;i++)
		{
			for(j=0;j<13;j++)
			{
				if(g_iMap[i][j]==1)
				{
					szName = CSystem::MakeSpriteName("wall",j+i*13+i);//��������
					//CSprite* pWall = new CSprite(szName);
					CWeapon* pWall = new CWeapon(szName); //�½�����
					pWall->CloneSprite("wall"); //��¡ǽ��
					/*if(count%2==0){*/
						pWall->SetSpriteCollisionActive(0,1); //����Ϊ������ײ
						pWall->SetSpriteCollisionResponse(COL_RESPONSE_CUSTOM);
					/*}else{
						pWall->SetSpriteCollisionActive(0,1); //����Ϊ������ײ
						pWall->SetSpriteCollisionResponse(COL_RESPONSE_CUSTOM);
					}*/

					x =float(-24+4*j);
					y =float(-20+4*i);
					pWall->SetSpritePosition(x,y);
					m_vWeapon.push_back(pWall);
				}
			}
		}
}
CWeapon* CGameMain::FindWeaponByName(const char* szName)//�������ֲ��ҵ�����
{
	for(int i=0; i<m_vWeapon.size(); i++)
	{
			if(strcmp(szName,m_vWeapon[i]->GetName()) == 0)
			{
				return m_vWeapon[i];
			}
	}
}
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
void CGameMain::AddTankEnemy(float fDeltaTime)
{
	m_fTankEnemyTime += fDeltaTime;
	if(m_fTankEnemyTime > 5.f)
	{
		m_iEnemy++;
		char* szName = CSystem::MakeSpriteName("enemy",m_iTankEnemyNumber);
		CTankEnemy* m_pTankEnemy = new CTankEnemy(szName);
		m_pTankEnemy->CloneSprite("enemy");
		m_pTankEnemy->Init();
		m_iTankEnemyNumber++;
		m_vWeapon.push_back(m_pTankEnemy);  //�Ѵ����ĵз�̹�˲��뵽������
		m_fTankEnemyTime=0.f;
	}
}
void CGameMain::EnhanceHome()
{
		char* szName;
		int i,j;
		float x,y;
		for(i=0;i<11;i++)
		{
			for(j=0;j<13;j++)
			{
				if(g_iEnhanceMap[i][j]==1)
				{
					szName = CSystem::MakeSpriteName("tie",j+i*13+i);//��������
					//CSprite* pWall = new CSprite(szName);
					CWeapon* pWall = new CWeapon(szName); //�½�����
					pWall->CloneSprite("tie"); //��¡ǽ��
					pWall->SetSpriteCollisionActive(0,0); //����Ϊ������ײ
					pWall->SetSpriteCollisionResponse(COL_RESPONSE_OFF);
					x =float(-24+4*j);
					y =float(-20+4*i);
					pWall->SetSpritePosition(x,y);
					m_vWeapon.push_back(pWall);
				}
			}
		}
}
void CGameMain::GrassMap(){
			char* szName;
		int i,j;
		float x,y;
		for(i=0;i<11;i++)
		{
			for(j=0;j<13;j++)
			{
				if(g_iGrassMap[i][j]==1)
				{
					szName = CSystem::MakeSpriteName("grass",j+i*13+i);//��������
					//CSprite* pWall = new CSprite(szName);
					CWeapon* pWall = new CWeapon(szName); //�½�����
					pWall->CloneSprite("shu"); //��¡ǽ��
					pWall->SetSpriteCollisionActive(0,0); //����Ϊ������ײ
					pWall->SetSpriteCollisionResponse(COL_RESPONSE_OFF);
					x =float(-24+4*j);
					y =float(-20+4*i);
					pWall->SetSpritePosition(x,y);
					m_vWeapon.push_back(pWall);
				}
			}
		}
}
