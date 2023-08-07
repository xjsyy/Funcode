#ifndef CTANKPLAYER_H
#define CTANKPLAYER_H

#include "CommonClass.h"
#include "CWeapon.h"

class CTankPlayer : public CWeapon
{
public:
    CTankPlayer();
    //virtual ~CTankPlayer();
    CTankPlayer(const char* szName);
    void        OnSpriteColSprite(CWeapon* pSprite);
    // set方法

    // void SetHp(int hp)
    // {
    //     m_iHp = hp;
    // }
    // void SetDir(int dir)
    // {
    //     m_iDir = dir;
    // }
    // void SetSpeedX(float speedX)
    // {
    //     m_fSpeedX = speedX;
    // }
    // void SetSpeedY(float speedY)
    // {
    //     m_fSpeedY = speedY;
    // }
    // get方法
    // int GetHp()
    // {
    //     return m_iHp;
    // }
    // int GetDir()
    // {
    //     return m_iDir;
    // }
    // float GetSpeedX()
    // {
    //     return m_fSpeedX;
    // }
    // float GetSpeedY()
    // {
    //     return m_fSpeedY;
    // }
    void            Init();
    void            OnMove(int iKey,bool bPress);
    void            OnFire();
protected:
private:
    // int         m_iDir;
    // float       m_fSpeedX;
    // float       m_fSpeedY;
    // int         m_iHp;
};

#endif // CTANKPLAYER_H
