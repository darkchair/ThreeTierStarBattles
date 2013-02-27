#include "TacticsEntity.h"

TacticsEntity::TacticsEntity() {

    entityType = empty;
    movementSpeed = -1;

}

TacticsEntity::TacticsEntity(Entity en) {

    entityType = en;
    if(en == shipEnemy || en == shipFriend)
        movementSpeed = 3;
    else
        movementSpeed = -1;

}

TacticsEntity::~TacticsEntity() {

}
