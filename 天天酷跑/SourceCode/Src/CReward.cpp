#include "CReward.h"

CReward::CReward(const char *szName):CWeapon(szName)
{
    //ctor
}

CReward::~CReward()
{
    //dtor
}


void CReward::init(){
    SetSpritePosition(GetPosX(),GetPosY());
    SetSpriteVisible(true);
}

void CReward::OnMove(){
    SetSpriteLinearVelocity(GetSpeedX(),GetSpeedY());
}
