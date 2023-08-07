#ifndef CWEAPON_H
#define CWEAPON_H
#include"CommonClass.h"

class CWeapon : public CAnimateSprite
{
    public:
        CWeapon(const char *szName);
        virtual ~CWeapon();

        float GetPosX(){
            return m_fPosX;
        }
        float GetPosY(){
            return m_fPosY;
        }
        float GetSpeedX(){
            return m_fSpeedX;
        }
        float GetSpeedY(){
            return m_fSpeedY;
        }

        void setPosX(float PosX){
            m_fPosX=PosX;
        }
        void setPosY(float PosY){
            m_fPosY=PosY;
        }
        void setSpeedX(float SpeedX){
            m_fSpeedX=SpeedX;
        }
        void setSpeedY(float SpeedY){
            m_fSpeedY=SpeedY;
        }
        virtual void init(){};
        virtual void OnSpriteColSprite(CWeapon *pSprite){};
        virtual void OnMove(){};
    protected:

    private:
    float m_fSpeedX;
    float m_fSpeedY;
    float m_fPosX;
    float m_fPosY;
};

#endif // CWEAPON_H
