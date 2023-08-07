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
#include<iostream>
#include <vector>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////
//
// 游戏总管类。负责处理游戏主循环、游戏初始化、结束等工作
class	CGameMain
{
private:
    int				    m_iGameState;				// 游戏状态，0：结束或者等待开始；1：初始化；2：游戏进行中
    float               m_fTotalTime;
    int                 m_fGoldBornMinX;
    int	                m_fGoldBornMaxX;
    int	                m_fGoldBornMinY;
    int	                m_fGoldBornMaxY;

    int                 m_fRockBornMinX;
    int	                m_fRockBornMaxX;
    int	                m_fRockBornMinY;
    int	                m_fRockBornMaxY;

    int                 m_fBompBornMinX;
    int	                m_fBompBornMaxX;
    int	                m_fBompBornMinY;
    int	                m_fBompBornMaxY;
    int                 m_iGoldCount;
    int                 m_iRockCount;
    int                 m_iBompCount;
    CSprite*            tmpSprite;
    CSprite*            Begin;
    float               m_fHookStartPosX;
    float               m_fHookStartPosY;
    int	                m_iHookState;	//0 表示钩子旋转，1表示释放绳索，钩子不旋转,2表示回拉过程
    float			    m_fHookRotation;		//钩子同地面的夹角
    int				    m_iHookRotToLeft;		//钩子摆动的方向：1 ← ；0 →
    CSprite*		    goldHook;			    //钩子对应的精灵
    //int		            m_iHookState;	        //钩子状态，0 表示钩子旋转，1表示释放绳索，钩子不转
    float			    m_fHookSpeed;		    //钩子释放的速度
    CAnimateSprite*		goldMan;		        //矿工对应的Sprite
    vector<CSprite*>    golds;
    CSprite*		    m_gotGold;		        //存储抓到的金块
    CSprite*            m_gotRock;              //.........石块
    vector<CSprite*>    rocks;

public:
    CGameMain();            //构造函数
    ~CGameMain();           //析构函数

    // Get方法
    int				GetGameState()
    {
        return m_iGameState;
    }

    // Set方法
    void			SetGameState( const int iState )
    {
        m_iGameState	=	iState;
    }

    // 游戏主循环等
    void			GameMainLoop( float	fDeltaTime );
    void			GameInit();
    void			GameRun( float fDeltaTime );
    void			GameEnd();
    void  			OnMouseMove( const float fMouseX, const float fMouseY );
    void 			OnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY );
    void 			OnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY );
    void 			OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress );
    void 	        OnKeyUp( const int iKey );
    void		    OnSpriteColSprite( const char *szSrcName, const char *szTarName );
    void 			OnSpriteColWorldLimit( const char *szName, const int iColSide );
   	void		    SetSpriteRotation( const float fRot );
    void 		    SetSpriteLinearVelocityPolar( const float fSpeed, const float fPolar );    // SetSpriteLinearVelocityPolar：按角度朝向设置精灵移动速度
    bool		    AnimateSpritePlayAnimation( const char *szAnim, const bool bRestore );    // AnimateSpritePlayAnimation：动画精灵播放动画
    float		    GetSpriteLinkPointPosX( const int iId );                                  //GetSpriteLinkPointPosX：获取精灵链接点X坐标。链接点是依附于精灵的一个坐标点，可以在编辑器里增加或者删除
	float		    GetSpriteLinkPointPosY( const int iId );                                  // GetSpriteLinkPointPosY：获取精灵链接点Y坐标。链接点是依附于精灵的一个坐标点，可以在编辑器里增加或者删除
	static void		DrawLine( const float fStartX, const float fStartY, const float fEndX, const float fEndY, const float fLineWidth, const int iLayer, const int iRed, const int iGreen, const int iBlue, const int iAlpha );      //DrawLine：在两点之间画一条线
    int			    SpriteMountToSpriteLinkPoint( const char *szDstName, const int iPointId );     // SpriteMountToSpriteLinkPoint：将一个精灵绑定到另一个精灵上，绑定位置为指定的链接点，暂时的成为另一个精灵的一部分，跟随其运动等
    float		    GetSpritePositionX();                                                          // GetSpritePositionX：获取精灵X坐标
    float		    GetSpritePositionY();                                                         // GetSpritePositionY：获取精灵Y坐标
	CSprite*		FindGoldSpriteByName(const char* szName);
    void		    DeleteSprite();                                                                // DeleteSprite：在地图中删除与本对象实例关联的精灵
    void		    SpriteDismount();                                                              // SpriteDismount：将已经绑定的精灵进行解绑
    float 		    GetSpriteLinearVelocityX();                                                    // GetSpriteLinearVelocityX：获取精灵X方向速度
    float 		    GetSpriteLinearVelocityY();                                                    // GetSpriteLinearVelocityY：获取精灵Y方向速度
};

/////////////////////////////////////////////////////////////////////////////////
//
extern CGameMain	g_GameMain;

#endif // _LESSON_X_H_
    // for(iBLoop=0;iBLoop<4;iBLoop++){
    //     iBSize=5;
    //     char *tmpName2;
    //     tmpName2 = CSystem::MakeSpriteName("Bomp", iLoop); // 生成金块名字
    //     CSprite *tmpSprite2 = new CSprite(tmpName2);
    //     tmpSprite->CloneSprite("bompTemplate");
    //     tmpSprite2->SetSpriteWidth(iSize);  // 设置炸弹的宽度
    //     tmpSprite2->SetSpriteHeight(iSize); // 设置炸弹的高度
    //     iBPosX = CSystem::RandomRange(m_fBompBornMinX, m_fBompBornMaxX);
    //     iBPosY = CSystem::RandomRange(m_fBompBornMinY, m_fBompBornMaxY);
    //     tmpSprite2->SetSpritePosition(iBPosX, iBPosY);
    //     tmpSprite->SetSpriteCollisionReceive(true);
    // }
