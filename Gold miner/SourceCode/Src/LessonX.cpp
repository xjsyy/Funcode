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
// ����ĳ�������Ϊ��GameMainLoop����Ϊ��ѭ��������������ÿ֡ˢ����Ļͼ��֮�󣬶��ᱻ����һ�Ρ�

//==============================================================================
//
// ���캯��
CGameMain::CGameMain()
{
    // m_iGameState = 1;
    goldHook = new CSprite("goldhook"); // ��������ʵ��
    Begin = new CSprite("begin");
    goldMan = new CAnimateSprite("goldman");
    m_fTotalTime = 0.0f;
    m_iGameState = 0;
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
        if (m_iGoldCount > 0)
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
    m_iHookState = 0; // ��ʼ�����ʹ������ת
    m_fHookSpeed = 30.f;

    int m_fGoldBornMinX = 0;
    int m_fGoldBornMaxX = 0;
    int m_fGoldBornMinY = 0;
    int m_fGoldBornMaxY = 0;

    Begin->SetSpriteVisible(false);

    m_fHookStartPosX = 0.f;
    m_fHookStartPosY = 0.f;
    m_iHookRotToLeft = 1;  // ���ӳ�ʼ������Ϊ��
    m_fHookRotation = 0.f; // ��ʼ���ļн�Ϊ0
    m_iGoldCount = 20;     // ���ӳ�ʼ����
    static int IinitedHookPos = 0;
    if (IinitedHookPos == 0)
    {
        IinitedHookPos = 1;

        m_fHookStartPosX = goldHook->GetSpritePositionX(); // ��ȡ���ӵĳ�ʼ��X����
        m_fHookStartPosY = goldHook->GetSpritePositionY(); // ��ȡ���ӵĳ�ʼ��Y����

        m_fGoldBornMinX = CSystem::GetScreenLeft() + 5;   // ������߽�
        m_fGoldBornMaxX = CSystem::GetScreenRight() - 5;  // �����ұ߽�
        m_fGoldBornMinY = CSystem::GetScreenTop() + 20;   // �����ϱ߽�
        m_fGoldBornMaxY = CSystem::GetScreenBottom() - 5; // �����±߽�

        m_fRockBornMinX = CSystem::GetScreenLeft() + 5;   // ʯ����߽�
        m_fRockBornMaxX = CSystem::GetScreenRight() - 5;  // ʯ���ұ߽�
        m_fRockBornMinY = CSystem::GetScreenTop() + 20;   // ʯ���ϱ߽�
        m_fRockBornMaxY = CSystem::GetScreenBottom() - 5; // ʯ���±߽�

        m_fBompBornMinX = CSystem::GetScreenLeft() + 5;   // ը����߽�
        m_fBompBornMaxX = CSystem::GetScreenRight() - 5;  // ը���ұ߽�
        m_fBompBornMinY = CSystem::GetScreenTop() + 20;   // ը���ϱ߽�
        m_fBompBornMaxY = CSystem::GetScreenBottom() - 5; // ը���±߽�
    }

    int iLoop = 0,iBLoop=0,iRLoop;                       // ѭ����������
    int iSize = 4,iBSize=4,iRSize=4, iPosX = 0, iPosY = 0, iBPosX = 0, iBPosY = 0, iRPosX = 0, iRPosY = 0; // iSize��ʾ����С�ı���
    for (iLoop = 0; iLoop < m_iGoldCount; iLoop++)
    {
        if (iLoop < 10) // ����10��С��飬��СΪ4
        {
            iSize = 4;
        }
        else if (iLoop >= 10 && iLoop < 16) // ����6���н�飬��СΪ6
        {
            iSize = 6;
        }
        else // ����4�����飬��СΪ8
        {
            iSize = 8;
        }
        // ��ʼ�����Ӿ���ʵ��
        char *tmpName;//*tmpName2;
        tmpName = CSystem::MakeSpriteName("GoldBlock", iLoop); // ���ɽ������
        CSprite *tmpSprite = new CSprite(tmpName);
        tmpSprite->CloneSprite("goldTemplate");
        tmpSprite->SetSpriteWidth(iSize);  // ���ý��Ŀ��
        tmpSprite->SetSpriteHeight(iSize); // ���ý��ĸ߶�
        // ����Ļ�ȡ���ӵ�X�����Y����
        iPosX = CSystem::RandomRange(m_fGoldBornMinX, m_fGoldBornMaxX);
        iPosY = CSystem::RandomRange(m_fGoldBornMinY, m_fGoldBornMaxY);
        // ���ý�龫���λ��
        tmpSprite->SetSpritePosition(iPosX, iPosY);
        tmpSprite->SetSpriteCollisionReceive(true);

        golds.push_back(tmpSprite); // �����ѹ��golds vector�м��й���*/
    }
    for(iBLoop=0;iBLoop<4;iBLoop++){
        iBSize=5;
        char *tmpName2;
        tmpName2 = CSystem::MakeSpriteName("Bomp", iBLoop); // ���ɽ������
        CSprite *tmpSprite2 = new CSprite(tmpName2);
        tmpSprite2->CloneSprite("bompTemplate");
        tmpSprite2->SetSpriteWidth(iBSize);  // ����ը���Ŀ��
        tmpSprite2->SetSpriteHeight(iBSize); // ����ը���ĸ߶�
        iBPosX = CSystem::RandomRange(m_fBompBornMinX, m_fBompBornMaxX);
        iBPosY = CSystem::RandomRange(m_fBompBornMinY, m_fBompBornMaxY);
        tmpSprite2->SetSpritePosition(iBPosX, iBPosY);
        tmpSprite2->SetSpriteCollisionReceive(true);
    }
    for(iRLoop=0;iRLoop<4;iRLoop++){
        iRSize=5;
        char *tmpName;
        tmpName = CSystem::MakeSpriteName("Rock", iRLoop); // ����ʯͷ����
        CSprite *tmpSprite = new CSprite(tmpName);
        tmpSprite->CloneSprite("rockTemplate");
        tmpSprite->SetSpriteWidth(iRSize);  // ����ʯͷ�Ŀ��
        tmpSprite->SetSpriteHeight(iRSize); // ����ʯͷ�ĸ߶�
        iRPosX = CSystem::RandomRange(m_fRockBornMinX, m_fRockBornMaxX);
        iRPosY = CSystem::RandomRange(m_fRockBornMinY, m_fRockBornMaxY);
        tmpSprite->SetSpritePosition(iRPosX, iRPosY);
        tmpSprite->SetSpriteCollisionReceive(true);

        rocks.push_back(tmpSprite); // �����ѹ��golds vector�м��й���*/
    }
}
//=============================================================================
//
// ÿ����Ϸ������
void CGameMain::GameRun(float fDeltaTime)
{
    if (m_iHookState == 0)
    {
        const float fRotateSpeed = 45.f;               //  ҡ���ٶȣ���λ ��/��
        float fThisRotate = fRotateSpeed * fDeltaTime; // ������ת�ĽǶ�
        // m_fTotalTime+=fDeltaTime;

        if (m_iHookRotToLeft)
        {
            // ���� ת���������ϱ��
            m_fHookRotation += fThisRotate;
            if (m_fHookRotation >= 180.f)
            {
                // ����180����Ϊ����ת����0
                m_fHookRotation = 180.f;
                m_iHookRotToLeft = 0;
            }
        }
        else // ����ת���������ϱ�С
        {
            m_fHookRotation -= fThisRotate; // С��0����Ϊ����ת���� 1
            if (m_fHookRotation <= 0.f)
            {
                m_fHookRotation = 0.f;
                m_iHookRotToLeft = 1;
            }
        }
        goldHook->SetSpriteRotation(m_fHookRotation); // ���ù��ӵĵ�ǰ�Ƕ�*/
    }
    else if (m_iHookState == 1 || m_iHookState == 2)
    { // ��������������Ҫ����
        // ���ȣ��ӿ󹤾����ϻ�ȡһ���������ӵ���Ϊ���ӵ���ʼ��(�����ӵ��ڱ༭����༭��)
        float fStartX = goldMan->GetSpriteLinkPointPosX(1);
        float fStartY = goldMan->GetSpriteLinkPointPosY(1);
        // �����յ��ڹ��Ӿ����ϻ�ȡ(�����ӵ��ڱ༭����༭��)
        float fEndX = goldHook->GetSpriteLinkPointPosX(1);
        float fEndY = goldHook->GetSpriteLinkPointPosY(1);
        // ��������֮�仮��.�ߵ���ɫ������ֵ��Ϊ50������ɫ��255��ʾ��͸����2.0f��ʾ�ߵĴ�ϸ��0��ʾ���ڵĲ�
        CSystem::DrawLine(fStartX, fStartY, fEndX, fEndY, 2.f, 0, 50, 10, 10, 255);
        	if(m_iHookState == 2){		//����������
			float	fSpeedX	=	goldHook->GetSpriteLinearVelocityX();	//��ȡ����X������ٶ�
			float	fSpeedY	=	goldHook->GetSpriteLinearVelocityY();	//��ȡ����Y������ٶ�
			//���ٶȽӽ�Ϊ0ʱ�������ж����ѵ����ʼ��
			if( fSpeedX < 0.00001f && fSpeedX > -0.00001f && fSpeedY < 0.00001f && fSpeedY > -0.00001f ){
				m_gotGold->SpriteDismount();	//�������빳�ӵ�ê��
				//m_gotRock->SpriteDismount();
				m_gotGold->DeleteSprite();		//ɾ����ȡ�Ľ��
				//m_gotRock->DeleteSprite();
				m_iHookState = 0;				//�����������趨����״̬Ϊ0,�������ذڶ�
				goldMan->AnimateSpritePlayAnimation("GolderManAnimation2", false);	//���ſ󹤵Ķ�������׼�������ӵĶ���
			}
		}

    }
}
//=============================================================================
//
// ������Ϸ����
void CGameMain::GameEnd()
{
    m_fTotalTime = 0.0f;
}
//==========================================================================
//
// ���沶׽����ƶ���Ϣ�󣬽����õ�������
void CGameMain::OnMouseMove(const float fMouseX, const float fMouseY)
{
    // �����ڴ������Ϸ��Ҫ����Ӧ����
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
    if (iKey == KEY_SPACE && m_iGameState == 0)
        SetGameState(1);
    if (KEY_DOWN == iKey && m_iHookState == 0)
    {                     // ���¡�������Ϸ״̬Ϊ��1��
        m_iHookState = 1; // ����Ϸ״̬Ϊ1�������ڿ��ƹ����Ƿ�ڶ�
        // �Ե�ǰ���������һ����ǰ���ٶ�
        goldHook->SetSpriteLinearVelocityPolar(m_fHookSpeed, m_fHookRotation);
        // �����ڽ��ߵĶ���(һ���첲����ѹ�Ķ���)
        goldMan->AnimateSpritePlayAnimation("GolderManAnimation3", 0); // 0 ��ʾ����һ�Σ�����첲����ѹ����һ��
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
    if (strcmp(szSrcName, "goldhook") == 0 && strstr(szTarName, "GoldBlock") != NULL)
    {
        m_fHookSpeed=10.f;
        m_gotGold=FindGoldSpriteByName(szTarName); // ��golds�в����Ƿ���ڶ�Ӧ�Ľ�飬������CSprite*ָ��ָ��ý��
        if (m_gotGold != NULL)
        {
            m_gotGold->SpriteMountToSpriteLinkPoint("goldhook", 2);                      // �����ê���ڹ�����
            goldHook->SpriteMoveTo(m_fHookStartPosX, m_fHookStartPosY, m_fHookSpeed, 1); // ʹ�������ʼλ���ƶ���������
            goldMan->AnimateSpritePlayAnimation("GolderManAnimation3", true);           // ���������Ķ���
            m_iHookState = 2;		                                                     //��ʾ��������״̬
        }
    }
    else if (strcmp(szSrcName, "goldhook") == 0 && strstr(szTarName, "Rock") != NULL)
    {
        m_fHookSpeed=5.f;
        m_gotGold=FindGoldSpriteByName(szTarName); // ��golds�в����Ƿ���ڶ�Ӧ��ʯ�飬������CSprite*ָ��ָ��ý��
        if (m_gotGold != NULL)
        {
            m_gotGold->SpriteMountToSpriteLinkPoint("goldhook", 2);                      // �����ê���ڹ�����
            goldHook->SpriteMoveTo(m_fHookStartPosX, m_fHookStartPosY, m_fHookSpeed, 1); // ʹ�������ʼλ���ƶ���������
            goldMan->AnimateSpritePlayAnimation("GolderManAnimation2", false);           // ���������Ķ���
            m_iHookState = 2;
            m_fHookSpeed=5.f;	                                                     //��ʾʯ�������״̬
        }
    }
    m_fHookSpeed=30.f;
}

//===========================================================================
//
// ���沶׽������������߽���ײ֮�󣬵��ô˺���.
// iColSide : 0 ��ߣ�1 �ұߣ�2 �ϱߣ�3 �±�
void CGameMain::OnSpriteColWorldLimit(const char *szName, const int iColSide)
{
	if(strcmp(szName,"goldhook") == 0){		//�����߽��Ϊ����ʱ
			goldHook->SpriteMoveTo(m_fHookStartPosX, m_fHookStartPosY, m_fHookSpeed, 1);
		goldMan->AnimateSpritePlayAnimation("GolderManAnimation3", false );
		m_iHookState = 2;	//ͬ������Ϊ������ֻ��û����������
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
