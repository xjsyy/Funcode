/***********************************************************
* 版权所有 (C)2023, caozhiqiang
*
* 文件名称： CMonster.h
* 文件标识：无
* 内容摘要：CMonster类的构造方法定义
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
#ifndef CMONSTER_H
#define CMONSTER_H
#include"CWeapon.h"

class CMonster : public CWeapon
{
    public:
        CMonster(const char* szName);
        virtual ~CMonster();

        void init();
        void OnMove();

    protected:

    private:
};

#endif // CMONSTER_H
