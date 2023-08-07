/***********************************************************
* 版权所有 (C)2023, caozhiqiang
*
* 文件名称： CWeapon.cpp
* 文件标识：无
* 内容摘要：pillar,player,CReward,CMonster的父类
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



#include "CWeapon.h"

CWeapon::CWeapon(const char *szName):CAnimateSprite(szName)
{
    //ctor
}

CWeapon::~CWeapon()
{
    //dtor
}
