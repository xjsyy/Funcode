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
// ����ĳ�������Ϊ��GameMainLoop����Ϊ��ѭ��������������ÿ֡ˢ����Ļͼ��֮�󣬶��ᱻ����һ�Ρ�

//==============================================================================
//
// ���캯��
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
// ��������
CGameMain::~CGameMain()
{
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
	m_iGameScore = 0;
	CSystem::ShowCursor(false); // �������
	m_fRotateTime = 0.f;
	m_fOldRotation = paizi->GetSpriteRotation(); // ��ȡ���ӵĳ�ʼ�Ƕ�
	countdownTime = 3;							 // ����ʱʱ��Ϊ5s
	countPassedTime = 0.f;
	countdown->SetSpriteVisible(false); // ���õ���ʱ���ɼ�
	m_iMosquitoCount = 20;
	gameTime = new CTextSprite("gameTime");
}
//=============================================================================
//
// ÿ����Ϸ������
void CGameMain::GameRun(float fDeltaTime)
{
	if (m_fRotateTime > 0)
	{
		m_fRotateTime -= fDeltaTime; // ÿ����fDeltaTime��������ת��ʱ ��Ҳ����fDeltaTime
		if (m_fRotateTime <= 0)
		{											  // ������0.2s�Ժ�
			paizi->SetSpriteRotation(m_fOldRotation); // �ָ����ӵĳ�ʼ��ת��
		}
	}
	if (m_iGameState == 3)
	{								   // m_iGameState Ϊ3ʱ��ִ��
		countPassedTime += fDeltaTime; // ͳ�ƾ�����ʱ�䣬���洢��countPassedTime
		countdown->SetTextValue(countdownTime - countPassedTime);
		if (countPassedTime >= countdownTime)
		{										// ������ʱ�䳬��countdownTime
			countdown->SetSpriteVisible(false); // ����countdown
			countPassedTime = 0;				// ���þ�����ʱ�䣬Ϊ��һ����Ϸ��׼��
			m_iGameState = 4;					// �л�g_iGameState 3->4
			int minX = CSystem::GetScreenLeft() + 5;
			int maxX = CSystem::GetScreenRight() - 5;
			int minY = CSystem::GetScreenBottom() - 5;
			int maxY = CSystem::GetScreenTop() + 5;
			int iPosX = 0, iPosY = 0, iSize = 0; // ��������ĺ�������λ��
			int iLoop = 0;						 // ѭ�����Ʊ���
			for (iLoop = 0; iLoop < m_iMosquitoCount; iLoop++)
			{
				if (iLoop < 10) // ����10��С���ӣ���СΪ4
				{
					iSize = 2;
				}
				else if (iLoop >= 10 && iLoop < 16) // ����6�������ӣ���СΪ6
				{
					iSize = 3;
				}
				else // ����4�������ӣ���СΪ8
				{
					iSize = 4;
				}
				// ��ʼ�����Ӿ���ʵ��
				char *szName = CSystem::MakeSpriteName("wenzi", iLoop); // ����iLoop������ͬ��������
				CSprite *wenzi = new CSprite(szName);
				wenzi->CloneSprite("wenziTemplate");	  // ����wenziTemplate
				wenzi->SetSpriteWidth(iSize);			  // �������ӵĿ��
				wenzi->SetSpriteHeight(iSize);			  // �������ӵĸ߶�
				iPosX = CSystem::RandomRange(minX, maxX); // �������X����
				iPosY = CSystem::RandomRange(minY, maxY); // �������Y����
				wenzi->SetSpritePosition(iPosX, iPosY);	  // ���ò������ӵ�λ��
				wenzi->SetSpriteCollisionReceive(true);
				m_mosquitos.push_back(wenzi); // ѹ��vector�м��й���
			}
		}
	}
	else if (m_iGameState == 4)
	{
		m_fGameTime -= fDeltaTime;
		if (m_fGameTime > 0)
		{
			gameTime->SetTextValue(m_fGameTime); // ����Ϸʱ��δ����������ʾʣ�����Ϸʱ��
		}
		else
		{
			m_iGameState = 2;				// ����Ϸʱ����������g_iGameState 2->0��ת��
			kaishi->SetSpriteVisible(true); // ��ʾ���ո�ʼ��
			m_fGameTime = 0;
			paizi->SetSpritePositionX(18);
			paizi->SetSpritePositionY(8);
			gameTime->SetTextValue(m_fGameTime);
		}
	}
}
//=============================================================================
//
// ������Ϸ����
void CGameMain::GameEnd()
{
}

//==========================================================================
//
// ���沶׽����ƶ���Ϣ�󣬽����õ�������
void CGameMain::OnMouseMove(const float fMouseX, const float fMouseY)
{
	// �����ڴ������Ϸ��Ҫ����Ӧ����]
	if (m_iGameState == 4)
	{
		paizi->SetSpritePosition(fMouseX, fMouseY); // ʹ���ӵ�λ�ú����һ��
	}
}
//==========================================================================
//
// ���沶׽�������Ϣ�󣬽����õ�������
void CGameMain::OnMouseClick(const int iMouseType, const float fMouseX, const float fMouseY)
{
	// �����ڴ������Ϸ��Ҫ����Ӧ����
	if (iMouseType == MOUSE_LEFT && m_iGameState == 4) // ����������
	{
		paizi->SetSpriteRotation(m_fOldRotation - 10); // �������ӵ���ת�ǣ�Ϊ��ʼֵ-10
		m_fRotateTime = 0.1f;						   // �Ĵ��ʱ���� 0.2s����0.2s��ָ����ӳ�ʼ�Ƕ�
		// �����ж������Ƿ񱻻���
		float fX, fY;
		for (int i = 0; i < m_mosquitos.size(); i++)
		{											   // ����vector�е�����
			fX = m_mosquitos[i]->GetSpritePositionX(); // ��ȡ�������ڵĺ�����
			fY = m_mosquitos[i]->GetSpritePositionY(); // ��ȡ�������ڵ�������
			if (paizi->IsPointInSprite(fX, fY))		   // �ж������Ƿ������ӵķ�Χ��
			{
				m_mosquitos[i]->DeleteSprite(); // ɾ��������
				m_iGameScore++;					// ÿ��һֻ���Ӽ�һ��
				score->SetTextValue(m_iGameScore);
				break;
			}
		}
	}
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
	if (KEY_SPACE == iKey && 2 == m_iGameState) // ���¿ո�����Ϸ״̬Ϊ2ʱ
	{
		m_iGameState = 3;				   // ������Ϸ״̬���뵹��ʱ����3
		countdown->SetSpriteVisible(true); // ��ʾ����ʱ�ı���
		kaishi->SetSpriteVisible(false);   // ���ء��ո�ʼ��
		m_iGameScore = 0.f;				   // ��ʼ����һ����Ϸ����
		m_fGameTime = 10.f;				   // ��ʼ����һ����Ϸʱ��
		score->SetTextValue(m_iGameScore);
		gameTime->SetTextValue(m_fGameTime);
		for (int i = 0; i < m_mosquitos.size(); i++)
		{ // ɾ����һ����Ϸ��ʣ�������
			m_mosquitos[i]->DeleteSprite();
		}
		m_mosquitos.clear(); // ���vector
	}
}
//==========================================================================
//
// ���沶׽���̵�����Ϣ�󣬽����õ�������
void CGameMain::OnKeyUp(const int iKey)
{
	// �����ڴ������Ϸ��Ҫ����Ӧ����
}

//===========================================================================
//
// ���沶׽�������뾫����ײ֮�󣬵��ô˺���
void CGameMain::OnSpriteColSprite(const char *szSrcName, const char *szTarName)
{
}

//===========================================================================
//
// ���沶׽������������߽���ײ֮�󣬵��ô˺���.
// iColSide : 0 ��ߣ�1 �ұߣ�2 �ϱߣ�3 �±�
void CGameMain::OnSpriteColWorldLimit(const char *szName, const int iColSide)
{
}
