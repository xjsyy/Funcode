/***********************************************************
* 版权所有 (C)2023, caozhiqiang
*
* 文件名称： CPlayer.cpp
* 文件标识：无
* 内容摘要：pillar类的方法实现
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

#include "CPlayer.h"

CPlayer::CPlayer(const char *szName):CWeapon(szName)
{
    //ctor
}

CPlayer::~CPlayer()
{
    //dtor
}


void CPlayer::init(){
    setPosX(-26.f);
    setPosX(0.f);
    setPosY(19.f);
    setSpeedX(0.f);
    setSpeedY(0.f);
    SetSpriteLinearVelocity(GetSpeedX(),GetSpeedY());
    SetSpritePosition(GetPosX(),GetPosY());

}


void CPlayer::OnMove(){
    SetSpriteLinearVelocityY(GetSpeedY());
    if(GetSpritePositionY()-19.f>=0.f&&GetSpeedY()==25.f){
        SetSpriteLinearVelocityY(0.f);
        setSpeedY(0.f);
        setPosY(19.f);
        SetSpriteLinearVelocity(GetSpeedX(),GetSpeedY());
        SetSpritePosition(GetPosX(),GetPosY());
        AnimateSpritePlayAnimation("Ro11Animation",0);
    }
}
