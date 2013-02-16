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
    short friendlyCount = 3;
    short enemyCount = 3;
    short randLoc;

    while(friendlyCount != 0){
        randLoc = rand() % TACTICS_BOARD_HEIGHT*2;
        if(randLoc < TACTICS_BOARD_HEIGHT) {
            if(tilesArray[randLoc*10]->entity->entityType == empty) {
                tilesArray[randLoc*10] = new TacticsTile(shipFriend);
                friendlyCount--;
            }
        }
        else {
            if(tilesArray[(randLoc-TACTICS_BOARD_HEIGHT)*10 + 1]->entity->entityType == empty) {
                tilesArray[(randLoc-TACTICS_BOARD_HEIGHT)*10 + 1] = new TacticsTile(shipFriend);
                friendlyCount--;
            }
        }
    }

    while(enemyCount != 0) {
        randLoc = rand() % TACTICS_BOARD_HEIGHT*2;
        if(randLoc < TACTICS_BOARD_HEIGHT) {
            if(tilesArray[randLoc*10 + 9]->entity->entityType == empty) {
                tilesArray[randLoc*10 + 9] = new TacticsTile(shipEnemy);
                enemyCount--;
            }
        }
        else {
            if(tilesArray[(randLoc-TACTICS_BOARD_HEIGHT)*10 + 8]->entity->entityType == empty) {
                tilesArray[(randLoc-TACTICS_BOARD_HEIGHT)*10 + 8] = new TacticsTile(shipEnemy);
                enemyCount--;
            }
        }
    }

}

TacticsGame::~TacticsGame() {

}

TacticsTile** TacticsGame::getTilesArray() {

    return tilesArray;

}

void TacticsGame::OnKeyPress(SDLKey sym, SDLMod mod, Uint16 unicode) {
    
   /* if(sym == SDLK_UP)
        tempDir = 0;
    if(sym == SDLK_DOWN)
        tempDir = 1;
    if(sym == SDLK_LEFT)
        tempDir = 2;
    if(sym == SDLK_RIGHT)
        tempDir = 3;    */
    
}

void TacticsGame::OnLButtonDown(int mX, int mY) {
    
    
    
    
}
