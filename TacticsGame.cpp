#include "TacticsGame.h"

TacticsGame::TacticsGame() {

    TacticsTile* tem = tilesArray[0];

    for(int i=0; i<TACTICS_BOARD_HEIGHT; i++)
    {
        for(int j=0; j<TACTICS_BOARD_WIDTH; j++)
        {
            tilesArray[i*TACTICS_BOARD_WIDTH + j] = new TacticsTile();
        }
    }

}

TacticsGame::~TacticsGame() {
    //Do nothing
}

TacticsTile** TacticsGame::getTilesArray() {

    return tilesArray;

}
