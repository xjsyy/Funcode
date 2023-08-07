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
// ��Ϸ�ܹ��ࡣ��������Ϸ��ѭ������Ϸ��ʼ���������ȹ���
class	CGameMain
{
private:
    int				    m_iGameState;				// ��Ϸ״̬��0���������ߵȴ���ʼ��1����ʼ����2����Ϸ������
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
    int	                m_iHookState;	//0 ��ʾ������ת��1��ʾ�ͷ����������Ӳ���ת,2��ʾ��������
    float			    m_fHookRotation;		//����ͬ����ļн�
    int				    m_iHookRotToLeft;		//���Ӱڶ��ķ���1 �� ��0 ��
    CSprite*		    goldHook;			    //���Ӷ�Ӧ�ľ���
    //int		            m_iHookState;	        //����״̬��0 ��ʾ������ת��1��ʾ�ͷ����������Ӳ�ת
    float			    m_fHookSpeed;		    //�����ͷŵ��ٶ�
    CAnimateSprite*		goldMan;		        //�󹤶�Ӧ��Sprite
    vector<CSprite*>    golds;
    CSprite*		    m_gotGold;		        //�洢ץ���Ľ��
    CSprite*            m_gotRock;              //.........ʯ��
    vector<CSprite*>    rocks;

public:
    CGameMain();            //���캯��
    ~CGameMain();           //��������

    // Get����
    int				GetGameState()
    {
        return m_iGameState;
    }

    // Set����
    void			SetGameState( const int iState )
    {
        m_iGameState	=	iState;
    }

    // ��Ϸ��ѭ����
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
    void 		    SetSpriteLinearVelocityPolar( const float fSpeed, const float fPolar );    // SetSpriteLinearVelocityPolar�����Ƕȳ������þ����ƶ��ٶ�
    bool		    AnimateSpritePlayAnimation( const char *szAnim, const bool bRestore );    // AnimateSpritePlayAnimation���������鲥�Ŷ���
    float		    GetSpriteLinkPointPosX( const int iId );                                  //GetSpriteLinkPointPosX����ȡ�������ӵ�X���ꡣ���ӵ��������ھ����һ������㣬�����ڱ༭�������ӻ���ɾ��
	float		    GetSpriteLinkPointPosY( const int iId );                                  // GetSpriteLinkPointPosY����ȡ�������ӵ�Y���ꡣ���ӵ��������ھ����һ������㣬�����ڱ༭�������ӻ���ɾ��
	static void		DrawLine( const float fStartX, const float fStartY, const float fEndX, const float fEndY, const float fLineWidth, const int iLayer, const int iRed, const int iGreen, const int iBlue, const int iAlpha );      //DrawLine��������֮�仭һ����
    int			    SpriteMountToSpriteLinkPoint( const char *szDstName, const int iPointId );     // SpriteMountToSpriteLinkPoint����һ������󶨵���һ�������ϣ���λ��Ϊָ�������ӵ㣬��ʱ�ĳ�Ϊ��һ�������һ���֣��������˶���
    float		    GetSpritePositionX();                                                          // GetSpritePositionX����ȡ����X����
    float		    GetSpritePositionY();                                                         // GetSpritePositionY����ȡ����Y����
	CSprite*		FindGoldSpriteByName(const char* szName);
    void		    DeleteSprite();                                                                // DeleteSprite���ڵ�ͼ��ɾ���뱾����ʵ�������ľ���
    void		    SpriteDismount();                                                              // SpriteDismount�����Ѿ��󶨵ľ�����н��
    float 		    GetSpriteLinearVelocityX();                                                    // GetSpriteLinearVelocityX����ȡ����X�����ٶ�
    float 		    GetSpriteLinearVelocityY();                                                    // GetSpriteLinearVelocityY����ȡ����Y�����ٶ�
};

/////////////////////////////////////////////////////////////////////////////////
//
extern CGameMain	g_GameMain;

#endif // _LESSON_X_H_
    // for(iBLoop=0;iBLoop<4;iBLoop++){
    //     iBSize=5;
    //     char *tmpName2;
    //     tmpName2 = CSystem::MakeSpriteName("Bomp", iLoop); // ���ɽ������
    //     CSprite *tmpSprite2 = new CSprite(tmpName2);
    //     tmpSprite->CloneSprite("bompTemplate");
    //     tmpSprite2->SetSpriteWidth(iSize);  // ����ը���Ŀ��
    //     tmpSprite2->SetSpriteHeight(iSize); // ����ը���ĸ߶�
    //     iBPosX = CSystem::RandomRange(m_fBompBornMinX, m_fBompBornMaxX);
    //     iBPosY = CSystem::RandomRange(m_fBompBornMinY, m_fBompBornMaxY);
    //     tmpSprite2->SetSpritePosition(iBPosX, iBPosY);
    //     tmpSprite->SetSpriteCollisionReceive(true);
    // }
