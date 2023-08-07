/***********************************************************
* 版权所有 (C)2023, caozhiqiang
*
* 文件名称： CMonster.cpp
* 文件标识：无
* 内容摘要：CMonster类的方法实现
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
