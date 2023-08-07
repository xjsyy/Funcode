#ifndef M_IREWARD_H
#define M_IREWARD_H
#include"CWeapon.h"

class CReward:public CWeapon
{
    public:
        CReward(const char *szName);
        virtual ~CReward();
        void init();
        void OnMove();

    protected:

    private:
};

#endif // M_IREWARD_H
