#ifndef TACTICSTILE_H_INCLUDED
#define TACTICSTILE_H_INCLUDED

#include "TacticsEntity.h"

#include <stdlib.h>

class TacticsTile {

    public:

        TacticsEntity* entity;

    public:

        TacticsTile();
        TacticsTile(Entity en);
        ~TacticsTile();

        void randomAsteroid();

};

#endif // TACTICSTILE_H_INCLUDED
