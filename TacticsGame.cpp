#include "TacticsGame.h"

TacticsGame::TacticsGame() {

    //Randomly fill the board with asteroids
    for(int i=0; i<TACTICS_BOARD_HEIGHT; i++)
    {
        for(int j=0; j<TACTICS_BOARD_WIDTH; j++)
        {
            tilesArray[i*TACTICS_BOARD_WIDTH + j] = new TacticsTile();
            tilesArray[i*TACTICS_BOARD_WIDTH + j]->randomAsteroid();
        }
    }

    //Randomly place both teams of ships
    short randLoc = rand() % TACTICS_BOARD_HEIGHT*2;
    if(randLoc < TACTICS_BOARD_HEIGHT)
        tilesArray[randLoc*10] = new TacticsTile(shipFriend);
    else
        tilesArray[(randLoc-7)*10 + 1] = new TacticsTile(shipFriend);

    randLoc = rand() % TACTICS_BOARD_HEIGHT*2;
    if(randLoc < TACTICS_BOARD_HEIGHT)
        tilesArray[randLoc*10 + 9] = new TacticsTile(shipEnemy);
    else
        tilesArray[(randLoc-7)*10 + 8] = new TacticsTile(shipEnemy);

}

TacticsGame::~TacticsGame() {
    //Do nothing
}

TacticsTile** TacticsGame::getTilesArray() {

    return tilesArray;

}
