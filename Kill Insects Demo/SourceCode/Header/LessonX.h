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
#include<vector>
//#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////
//
// ��Ϸ�ܹ��ࡣ��������Ϸ��ѭ������Ϸ��ʼ���������ȹ���
class	CGameMain
{
private:
	int				m_iGameState;				// ��Ϸ״̬��0���������ߵȴ���ʼ��1����ʼ����2��ʾδ��ʼ����ʱ���Ӳ�������ƶ�����3 ��ʾ����ʱ�׶Σ� 4��ʾ��ʼ���ӿ���������ƶ����Ĵ�
	float			m_fRotateTime;		// �������º���븴λ�������ʱ��
	float			m_fOldRotation;		// ���ӵĳ�ʼ�Ƕ�
    CSprite*		paizi;
	int				countdownTime ;	        //����ʱʱ��
	float			countPassedTime;	    //����ʱ������ʱ��
	CTextSprite		*countdown;		        //����ʱ�����־���
    CSprite			*kaishi;			    //���ո�ʼ������
vector<CSprite*>  	m_mosquitos;
	int				m_iMosquitoCount;
	int				m_iGameScore;			//��ǰ�÷�
	CTextSprite		*score;					//score����
	float			m_fGameTime;			//��Ϸʱ��
	CTextSprite		*gameTime;				//��Ϸʱ�侫��



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
	void			SetSpriteRotation( const float fRot );						//SetSpriteRotation�����þ������ת�Ƕ�
	float			GetSpriteRotation();										// GetSpriteRotation����ȡ�������ת�Ƕ�
	static void		ShowCursor( const bool bShow );								// OnMouseClick����갴�º󽫱����õĺ��������ڴ˺�������(Main.cpp)�����Լ�����Ӧ����
	enum MouseTypes
	{
		MOUSE_LEFT	 =	0,		// ���
		MOUSE_RIGHT	 =	1,		// �Ҽ�
		MOUSE_MIDDLE =	2		// �м�
	};
	void		    SetTextValue( int iValue );                                   // SetTextValue�����־�����ʾĳ����ֵ
    void		    SetSpriteVisible( const bool bVisible );                      // SetSpriteVisible�����þ������ػ�����ʾ(�ɼ����ɼ�) 
	bool 			IsPointInSprite( const float fPosX, const float fPosY );	  // IsPointInSprite���ж�ĳ��������Ƿ�λ�ھ����ڲ�


};

/////////////////////////////////////////////////////////////////////////////////
//
extern CGameMain	g_GameMain;

#endif // _LESSON_X_H_
