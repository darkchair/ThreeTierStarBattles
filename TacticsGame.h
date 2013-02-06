#ifndef TACTICSGAME_H_INCLUDED
#define TACTICSGAME_H_INCLUDED

#include "TacticsTile.h"

#define TACTICS_BOARD_HEIGHT 7
#define TACTICS_BOARD_WIDTH 10

class TacticsGame {

    public:

        TacticsTile* tilesMatrix [TACTICS_BOARD_HEIGHT][TACTICS_BOARD_WIDTH];


    public:

        TacticsGame();
        ~TacticsGame();

};

#endif // TACTICSGAME_H_INCLUDED
