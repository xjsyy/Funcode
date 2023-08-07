#ifndef CBULLET_H
#define CBULLET_H

#include "CommonClass.h"
#include "CWeapon.h"

class CBullet : public  CWeapon
{
public:
    //virtual ~CBullet();
    CBullet(const char* szName);
    void    OnMove(int iDir);
    void    OnSpriteColSprite(CWeapon* pSprite);
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
    float SetOwner(int Owner)
    {
        m_iOwner=Owner;
    }
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
    float GetOwner()
    {
        return m_iOwner;
    }
protected:

private:
    // int     m_iDir;
    // float   m_fSpeedX;
    // float   m_fSpeedY;
    // int     m_iHp;
    float   m_iOwner;
};

#endif // CBULLET_H
