#include "TacticsTile.h"

TacticsTile::TacticsTile() {

    entity = new TacticsEntity(ENTITY_EMPTY);

}

TacticsTile::TacticsTile(Entity en) {

    entity = new TacticsEntity(en);

}

TacticsTile::~TacticsTile() {

}


void TacticsTile::randomAsteroid() {
//Makes a tile an asteroid one seventh of the time

    short rando = rand() % 7;//not sure if works
    Entity temp;
    if(rando == 0)
        temp = ENTITY_ASTEROID;
    else
        temp = ENTITY_EMPTY;
    delete entity;
    entity = new TacticsEntity(temp);

}
