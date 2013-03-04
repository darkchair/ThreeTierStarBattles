#include "TacticsEntity.h"

TacticsEntity::TacticsEntity() {

    entityType = ENTITY_EMPTY;
    movementSpeed = -1;

}

TacticsEntity::TacticsEntity(Entity en) {

    entityType = en;
    if(en == ENTITY_SHIPENEMY || en == ENTITY_SHIPFRIEND)
        movementSpeed = 3;
    else
        movementSpeed = -1;

}

TacticsEntity::~TacticsEntity() {

}
