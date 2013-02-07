#ifndef TACTICSGAME_H_INCLUDED
#define TACTICSGAME_H_INCLUDED

#include "TacticsTile.h"

#define TACTICS_BOARD_HEIGHT 7
#define TACTICS_BOARD_WIDTH 10
#define TACTICS_BOARD_PIXELS_SIZE 100

class TacticsGame {

    public:

        TacticsTile* tilesMatrix [TACTICS_BOARD_HEIGHT][TACTICS_BOARD_WIDTH];


    public:

        TacticsGame();
        ~TacticsGame();

        TacticsTile*** getTilesMatrix();

};

#endif // TACTICSGAME_H_INCLUDED
