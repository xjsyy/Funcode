/////////////////////////////////////////////////////////////////////////////////
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////
#ifndef _LESSON_X_H_
#define _LESSON_X_H_
//
#include <Windows.h>
#include "CommonClass.h"
#include "CTankPlayer.h"
#include "CBullet.h"
#include "CWeapon.h"
#include "CTankEnemy.h"
#include<vector>
using namespace std;


/////////////////////////////////////////////////////////////////////////////////
//
// ��Ϸ�ܹ��ࡣ��������Ϸ��ѭ������Ϸ��ʼ���������ȹ���
class	CGameMain
{
private:
	int				m_iGameState;				// ��Ϸ״̬��0���������ߵȴ���ʼ��1����ʼ����2����Ϸ������
	CSprite*		m_pSplash;
	CSprite*		m_pStart;
	CTankPlayer*	m_pTankplayer;
	int				m_iBulletNum=0;
	CTankEnemy*		m_pTankEnemy;
vector<CWeapon*>	m_vWeapon;
	int 			g_iMap[11][13]=
	{
			{0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,1,0,0,0,1,0,1,0,0,0,1,0},
			{1,1,1,1,1,1,1,1,1,1,1,1,1},
			{0,0,0,1,0,1,0,1,0,1,0,0,0},
			{0,0,0,1,0,0,0,0,0,1,0,0,0},
			{0,0,0,1,0,1,0,1,0,1,0,0,0},
			{1,1,1,1,1,1,1,1,1,1,1,1,1},
			{0,1,0,1,0,0,0,0,0,1,0,1,0},
			{0,0,0,0,0,1,1,1,0,0,0,0,0},
			{0,0,0,0,0,1,0,1,0,0,0,0,0}
	};
	int 			g_iEnhanceMap[11][13]=
	{
			{0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,1,1,1,0,0,0,0,0},
			{0,0,0,0,0,1,0,1,0,0,0,0,0}
	};
	int 			g_iGrassMap[11][13]=
	{
			{0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0},
			{1,1,1,0,0,0,0,0,0,0,1,1,1},
			{1,1,1,0,0,0,0,0,0,0,1,1,1},
			{1,1,1,0,0,0,0,0,0,0,1,1,1},
			{0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0,0,0,0}
	};
	float			m_fTankEnemyTime;
	int				m_iTankEnemyNumber;
	CWeapon*		m_pAim_nor;
	CTextSprite*	 m_pScore; 								//��ʾ�������ı�����
	CTextSprite* 	 m_pHight;							 //��ʾ��߷ֵ��ı�����
	CTextSprite*	 m_pEnemy;										//��ʾ�����������ı�����
	int 			 m_iScore;											//����
	int 			 m_iEnemy;											//��������
	int 			 m_iHight;												//������߷�
	int  			 m_fDeltaTime;											//��ʾ��Ϸʱ��
	//CBullet*		 tmpBullet;
	int				 count;
public:
	CGameMain();            //���캯��
	~CGameMain();           //��������

	// Get����
	int				GetGameState()											{ return m_iGameState; }

	// Set����
	void			SetGameState( const int iState )				{ m_iGameState	=	iState; }

	// ��Ϸ��ѭ����
	void			GameMainLoop( float	fDeltaTime );
	void			GameInit();
	void			GameRun( float fDeltaTime );
	void			GameEnd();
	void			OnMouseMove( const float fMouseX, const float fMouseY );
	void			OnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY );
	void			OnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY );
	void			OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress );
	void			OnKeyUp( const int iKey );
	void			OnSpriteColSprite( const char *szSrcName, const char *szTarName );
	void			OnSpriteColWorldLimit( const char *szName, const int iColSide );
	void			AddBullet( int iDir,float fPosX,float fPosY ,int iOwner);
	void			LoadMap();															//���س�ʼ��ͼ
	CWeapon* 		FindWeaponByName(const char* szName);
	void			DeleteWeaponByName(const char* szName);
	void 			AddTankEnemy(float fDeltaTime);
	void			EnhanceHome();
	void			GrassMap();
};

/////////////////////////////////////////////////////////////////////////////////
//
extern CGameMain	g_GameMain;

#endif // _LESSON_X_H_
