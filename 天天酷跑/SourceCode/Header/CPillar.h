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
