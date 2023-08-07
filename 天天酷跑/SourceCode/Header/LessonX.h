 /////////////////////////////////////////////////////////////////////////////////
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////
#ifndef _LESSON_X_H_
#define _LESSON_X_H_
//
#include"CWeapon.h"
#include"CPlayer.h"
#include"CPillar.h"
#include"CReward.h"
#include"CMonster.h"
#include <Windows.h>
#include<vector>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////
//
// ��Ϸ�ܹ��ࡣ��������Ϸ��ѭ������Ϸ��ʼ���������ȹ���
class	CGameMain
{
private:
    int             m_iGameState;				// ��Ϸ״̬��0���������ߵȴ���ʼ��1����ʼ����2����Ϸ׼����3����Ϸ�����У�4����Ϸ����
    int             m_iLevelState;              //�ؿ���Ϣ
    int             m_iPlayerState;             //��ɫ��Ϣ����ȷ���Ƿ������1Ϊ�����У�2Ϊʧ�ܣ�3Ϊʤ��
    int             m_iScore;                   //��ǰ����

    float           m_fTotalTime;               //�Ѿ���ʱ��

    vector<CWeapon*>m_vWeapon;
    //�����Ա

    CSprite         *m_pBackground;
    CSprite         *m_pStartBack;
    CSprite         *m_pRemieTitle;
    CSprite         *m_pBegintext;

    CTextSprite     *m_pScore;
    CTextSprite     *m_pTitle;
    CTextSprite     *m_pWinText;
    CTextSprite     *m_pExitText;

    CPlayer         *m_pPlayer;


public:;
    CGameMain();            //���캯��
    ~CGameMain();           //��������

    // Get����
    int	GetGameState()
    {
        return m_iGameState;
    }

    // Set����
    void	SetGameState( const int iState )
    {
        m_iGameState	=	iState;
    }

    // ��Ϸ��ѭ����
    void        GameMainLoop( float	fDeltaTime );
    void        GameInit();
    void        GameReady();
    void        GameRun( float fDeltaTime );
    void        GameEnd();
    void        OnMouseMove( const float fMouseX, const float fMouseY );
    void        OnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY );
    void        OnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY );
    void        OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress );
    void        OnKeyUp( const int iKey );
    void        OnSpriteColSprite( const char *szSrcName, const char *szTarName );
    void        OnSpriteColWorldLimit( const char *szName, const int iColSide );

    //�ؿ���ƺ���
    void        BuildLevel1();
    void        BuildLevel2();
    void        BuildLevel3();
    void        BuildLevel4();

    //��������
    CWeapon*    FindWeaponByName(const char* szName);
    void        DeleteWeaponByName(const char* szName);
};

/////////////////////////////////////////////////////////////////////////////////
//
extern CGameMain	g_GameMain;

#endif // _LESSON_X_H_
