#ifndef TACTICSGAME_H_INCLUDED
#define TACTICSGAME_H_INCLUDED

#include "TacticsTile.h"
#include <vector>

#define TACTICS_BOARD_HEIGHT 7
#define TACTICS_BOARD_WIDTH 10
#define TACTICS_BOARD_PIXELS_SIZE 100

class TacticsGame {

    public:

        TacticsTile* tilesArray [TACTICS_BOARD_HEIGHT*TACTICS_BOARD_WIDTH];

    public:

        TacticsGame();
        ~TacticsGame();

        TacticsTile** getTilesArray();
        
        void OnKeyPress(SDLKey sym, SDLMod mod, Uint16 unicode);
        
        void OnLButtonDown(int mX, int mY);

};

#endif // TACTICSGAME_H_INCLUDED
