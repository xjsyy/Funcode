/***********************************************************
* 版权所有 (C)2023, caozhiqiang
*
* 文件名称：CWeapon.h
* 文件标识：无
* 内容摘要：声明get/set方法
* 其它说明：无
* 当前版本： V1.0
* 作   者：曹志强
* 完成日期： 20230530
*
* 修改记录1：
* 修改日期： 20230530
* 版本号： V1.0
* 修改人： 曹志强
* 修改内容：创建
**********************************************************/

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
