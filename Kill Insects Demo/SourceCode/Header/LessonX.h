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
// 游戏总管类。负责处理游戏主循环、游戏初始化、结束等工作
class	CGameMain
{
private:
	int				m_iGameState;				// 游戏状态，0：结束或者等待开始；1：初始化；2表示未开始（此时拍子不随鼠标移动），3 表示倒计时阶段， 4表示开始拍子可以随鼠标移动并拍打
	float			m_fRotateTime;		// 拍子拍下后距离复位还差多少时间
	float			m_fOldRotation;		// 拍子的初始角度
    CSprite*		paizi;
	int				countdownTime ;	        //倒计时时间
	float			countPassedTime;	    //倒计时经过的时间
	CTextSprite		*countdown;		        //倒计时的文字精灵
    CSprite			*kaishi;			    //“空格开始”精灵
vector<CSprite*>  	m_mosquitos;
	int				m_iMosquitoCount;
	int				m_iGameScore;			//当前得分
	CTextSprite		*score;					//score精灵
	float			m_fGameTime;			//游戏时间
	CTextSprite		*gameTime;				//游戏时间精灵



public:
	CGameMain();            //构造函数
	~CGameMain();           //析构函数

	// Get方法
	int				GetGameState()											{ return m_iGameState; }

	// Set方法
	void			SetGameState( const int iState )				{ m_iGameState	=	iState; }

	// 游戏主循环等
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
	void			SetSpriteRotation( const float fRot );						//SetSpriteRotation：设置精灵的旋转角度
	float			GetSpriteRotation();										// GetSpriteRotation：获取精灵的旋转角度
	static void		ShowCursor( const bool bShow );								// OnMouseClick：鼠标按下后将被调用的函数，可在此函数体里(Main.cpp)增加自己的响应代码
	enum MouseTypes
	{
		MOUSE_LEFT	 =	0,		// 左键
		MOUSE_RIGHT	 =	1,		// 右键
		MOUSE_MIDDLE =	2		// 中键
	};
	void		    SetTextValue( int iValue );                                   // SetTextValue：文字精灵显示某个数值
    void		    SetSpriteVisible( const bool bVisible );                      // SetSpriteVisible：设置精灵隐藏或者显示(可见不可见) 
	bool 			IsPointInSprite( const float fPosX, const float fPosY );	  // IsPointInSprite：判断某个坐标点是否位于精灵内部


};

/////////////////////////////////////////////////////////////////////////////////
//
extern CGameMain	g_GameMain;

#endif // _LESSON_X_H_
