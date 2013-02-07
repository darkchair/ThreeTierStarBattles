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

    public:

        TacticsEntity();
        TacticsEntity(Entity en);
        ~TacticsEntity();

};

#endif // TACTICSENTITY_H_INCLUDED
