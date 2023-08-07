#include "CMonster.h"

CMonster::CMonster(const char *szName):CWeapon(szName)
{
    //ctor
}

CMonster::~CMonster()
{
    //dtor
}


void CMonster::init(){
    SetSpritePosition(GetPosX(),GetPosY());
    SetSpriteVisible(true);
}

void CMonster::OnMove(){
    SetSpriteLinearVelocity(GetSpeedX(),GetSpeedY());
}
