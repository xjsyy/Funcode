#ifndef CPLAYER_H
#define CPLAYER_H

#include"CWeapon.h"
class CPlayer:public CWeapon
{
    public:
        CPlayer(const char *szName);
        virtual ~CPlayer();

        void init();
        void OnMove();

    protected:

    private:

};

#endif // CPLAYER_H
