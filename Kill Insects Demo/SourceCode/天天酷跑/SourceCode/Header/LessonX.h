/***********************************************************
* 版权所有 (C)2023, caozhiqiang，yangyvchun
*
* 文件名称：LessonX.h
* 文件标识：无
* 内容摘要：指针及方法的声明
* 其它说明：无
* 当前版本： V1.0
* 作   者：曹志强，杨钰春
* 完成日期： 20230530
*
* 修改记录1：
* 修改日期： 20230530
* 版本号： V1.0
* 修改人： 曹志强，杨钰春
* 修改内容：创建
**********************************************************/
//////////////////////////////////////////////////////////////////////////////////
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
// 游戏总管类。负责处理游戏主循环、游戏初始化、结束等工作
class	CGameMain
{
private:
    int             m_iGameState;				// 游戏状态，0：结束或者等待开始；1：初始化；2：游戏准备；3：游戏进行中；4：游戏结算
    int             m_iLevelState;              //关卡信息
    int             m_iPlayerState;             //角色信息，以确定是否结束，1为进行中，2为失败，3为胜利
    int             m_iScore;                   //当前分数

    float           m_fTotalTime;               //已经过时间

    vector<CWeapon*>m_vWeapon;
    //精灵成员

    CSprite         *m_pBackground;
    CSprite         *m_pStartBack;
    CSprite         *m_pRemieTitle;



    CSprite*        m_pInfo;




    CSprite         *m_pBegintext;

    CTextSprite     *m_pScore;
    CTextSprite     *m_pTitle;
    CTextSprite     *m_pWinText;
    CTextSprite     *m_pExitText;

    CPlayer         *m_pPlayer;




    CSprite*        m_pFlag;
    



    CPillar*        m_pPillar1;
    CPillar*        m_pPillar2;
    CPillar*        m_pPillar3;

    int             count;              //控制切换是否无敌




public:;
    CGameMain();            //构造函数
    ~CGameMain();           //析构函数

    // Get方法
    int	GetGameState()
    {
        return m_iGameState;
    }

    // Set方法
    void	SetGameState( const int iState )
    {
        m_iGameState	=	iState;
    }

    // 游戏主循环等
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

    //关卡设计函数
    void        BuildLevel1();
    void        BuildLevel2();
    void        BuildLevel3();
    void        BuildLevel4();

    //其他函数
    CWeapon*    FindWeaponByName(const char* szName);
    void        DeleteWeaponByName(const char* szName);
    void		wudi();
};

/////////////////////////////////////////////////////////////////////////////////
//
extern CGameMain	g_GameMain;

#endif // _LESSON_X_H_
