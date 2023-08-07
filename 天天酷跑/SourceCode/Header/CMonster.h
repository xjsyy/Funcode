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
