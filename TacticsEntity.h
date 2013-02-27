#ifndef TACTICSENTITY_H_INCLUDED
#define TACTICSENTITY_H_INCLUDED

enum Entity{
    empty,
    shipFriend,
    shipEnemy,
    asteroid
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
