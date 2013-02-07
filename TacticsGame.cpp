#include "TacticsGame.h"

TacticsGame::TacticsGame() {

    for(int i=0; i<TACTICS_BOARD_HEIGHT; i++)
    {
        for(int j=0; j<TACTICS_BOARD_WIDTH; j++)
        {
            tilesMatrix[i][j] = new TacticsTile();
        }
    }

}

TacticsGame::~TacticsGame() {
    //Do nothing
}

TacticsTile*** TacticsGame::getTilesMatrix() {

    return tilesMatrix;

}
