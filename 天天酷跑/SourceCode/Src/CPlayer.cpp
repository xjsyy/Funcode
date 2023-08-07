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
