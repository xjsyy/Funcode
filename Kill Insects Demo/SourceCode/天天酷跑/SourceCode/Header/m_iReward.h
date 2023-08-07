/***********************************************************
* 版权所有 (C)2023, caozhiqiang
*
* 文件名称：m_iReward.h
* 文件标识：无
* 内容摘要：Reward类构造方法声明
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
#ifndef M_IREWARD_H
#define M_IREWARD_H
#include"CWeapon.h"

class CReward:public CWeapon
{
    public:
        CReward(const char *szName);
        virtual ~CReward();

    protected:

    private:
};

#endif // M_IREWARD_H
