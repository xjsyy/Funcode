#include "CPillar.h"

CPillar::CPillar(const char *szName):CWeapon(szName)
{
    //ctor
}

CPillar::~CPillar()
{
    //dtor
}

void CPillar::init(){
    SetSpritePosition(GetPosX(),GetPosY());
    SetSpriteVisible(true);
}

void CPillar::OnMove(){
    SetSpriteLinearVelocity(GetSpeedX(),GetSpeedY());
}
