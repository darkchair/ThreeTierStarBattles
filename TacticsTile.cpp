#include "TacticsTile.h"

TacticsTile::TacticsTile() {

    entity = new TacticsEntity(empty);

}

TacticsTile::TacticsTile(Entity en) {

    entity = new TacticsEntity(en);

}

TacticsTile::~TacticsTile() {
    //Do nothing
}


void TacticsTile::randomAsteroid() {
//Makes a tile an asteroid one seventh of the time

    short rando = rand() % 7;//not sure if works
    Entity temp;
    if(rando == 0)
        temp = asteroid;
    else
        temp = empty;
    entity = new TacticsEntity(temp);

}
