/***********************************************************
* 版权所有 (C)2023, caozhiqiang
*
* 文件名称：LessonX.h
* 文件标识：无
* 内容摘要：Pillar类的方法定义
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

#ifndef CPILLAR_H
#define CPILLAR_H
#include"CWeapon.h"


class CPillar:public CWeapon
{
    public:
        CPillar(const char* szName);
        virtual ~CPillar();
        void init();
        void OnMove();

    protected:

    private:
};

#endif // CPILLAR_H
