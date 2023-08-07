#ifndef CTANKENEMY_H
#define CTANKENEMY_H

#include <CommonClass.h>
#include "CWeapon.h"

class CTankEnemy : public  CWeapon
{
public:
    CTankEnemy(const char* szName);
    virtual ~CTankEnemy();
    void        Init();
    void        OnMove();
    void        OnMove(float fDeltaTime);
    void        OnFire(float fDeltaTime);
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
    //}
    void Setdir(float dir)
    {
        iDir = dir;
    }
    void SetChangeDirTime(float Changedirtime)
    {
        m_fChangeDirTime = Changedirtime;
    }
    void SetBulletCreateTime(int BulletCreateTime)
    {
        m_fBulletCreateTime = BulletCreateTime;
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
    float Getidir()
    {
        return iDir;
    }
    float GetChangeDirTime()
    {
        return m_fChangeDirTime;
    }
    float GetBulletCreateTime()
    {
        return m_fBulletCreateTime;
    }
    protected:

private:
    // int         m_iDir;
    // float       m_fSpeedX;
    // float       m_fSpeedY;
    // int         m_iHp;
    int         iDir;
    float       m_fChangeDirTime;
    float       m_fBulletCreateTime;
};

#endif // CTANKENEMY_H
