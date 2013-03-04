#ifndef TACTICSENTITY_H_INCLUDED
#define TACTICSENTITY_H_INCLUDED

enum Entity{
    ENTITY_SHIPFRIEND,
    ENTITY_SHIPENEMY,
    ENTITY_ASTEROID,
    ENTITY_EMPTY
};

class TacticsEntity {

    public:

        Entity entityType;

        int movementSpeed;

    public:

        TacticsEntity();
        TacticsEntity(Entity en);
        ~TacticsEntity();

};

/*class FriendlyShipEntity : public TacticsEntity {

    public:

        int movementSpeed;

};*/

#endif // TACTICSENTITY_H_INCLUDED
