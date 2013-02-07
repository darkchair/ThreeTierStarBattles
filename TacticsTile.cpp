#include "TacticsTile.h"

TacticsTile::TacticsTile() {
//Gives a random tile, one quarter of the time an asteroid, the rest blank

    //srand(time(NULL));

    short rando = rand() % 7;//probably doesn't work, results don't make sense
    Entity temp;
    if(rando == 0)//About one Quarter of tiles are asteroids, the rest are empty
        temp = (Entity)2;
    else
        temp = (Entity)0;
    entity = new TacticsEntity(temp);

}

TacticsTile::~TacticsTile() {
    //Do nothing
}
