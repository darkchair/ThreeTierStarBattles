#ifndef TACTICSENTITY_H_INCLUDED
#define TACTICSENTITY_H_INCLUDED


enum Entity{
    empty,
    ship,
    asteroids
};

class TacticsEntity {

    public:

        Entity entity;

    public:

        TacticsEntity();
        ~TacticsEntity();

};

#endif // TACTICSENTITY_H_INCLUDED
