#include "TacticsGame.h"

TacticsGame::TacticsGame() {

    shipSelected = -1;

    cardSelection = false;

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
        //Randomly place ships in left-most two columns
        randLoc = rand() % TACTICS_BOARD_HEIGHT*2;
        if(randLoc < TACTICS_BOARD_HEIGHT) {
            if(tilesArray[randLoc*10]->entity->entityType == ENTITY_EMPTY) {
                tilesArray[randLoc*10] = new TacticsTile(ENTITY_SHIPFRIEND);
                friendlyCount--;
            }
        }
        else {
            if(tilesArray[(randLoc-TACTICS_BOARD_HEIGHT)*10 + 1]->entity->entityType == ENTITY_EMPTY) {
                tilesArray[(randLoc-TACTICS_BOARD_HEIGHT)*10 + 1] = new TacticsTile(ENTITY_SHIPFRIEND);
                friendlyCount--;
            }
        }
    }

    while(enemyCount != 0) {
        //Randomly place ships in right-most two columns
        randLoc = rand() % TACTICS_BOARD_HEIGHT*2;
        if(randLoc < TACTICS_BOARD_HEIGHT) {
            if(tilesArray[randLoc*10 + 9]->entity->entityType == ENTITY_EMPTY) {
                tilesArray[randLoc*10 + 9] = new TacticsTile(ENTITY_SHIPENEMY);
                enemyCount--;
            }
        }
        else {
            if(tilesArray[(randLoc-TACTICS_BOARD_HEIGHT)*10 + 8]->entity->entityType == ENTITY_EMPTY) {
                tilesArray[(randLoc-TACTICS_BOARD_HEIGHT)*10 + 8] = new TacticsTile(ENTITY_SHIPENEMY);
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

    shipSelected = -1;

    for(int i=0; i<TACTICS_BOARD_HEIGHT; i++) {

        for(int j=0; j<TACTICS_BOARD_WIDTH; j++) {

            if((mX >= j*TACTICS_BOARD_PIXELS_SIZE) &&
               (mX <= j*TACTICS_BOARD_PIXELS_SIZE + TACTICS_BOARD_PIXELS_SIZE) &&
               (mY >= i*TACTICS_BOARD_PIXELS_SIZE) &&
               (mY <= i*TACTICS_BOARD_PIXELS_SIZE + TACTICS_BOARD_PIXELS_SIZE)) {

                if(tilesArray[i*TACTICS_BOARD_WIDTH + j]->entity->entityType == ENTITY_SHIPFRIEND) {
                    shipSelected = i*TACTICS_BOARD_WIDTH + j;
                    return;
                }

            }

        }

    }

}

void TacticsGame::OnRButtonDown(int mX, int mY) {

    if(shipSelected != -1) {

        int locationSelected = TACTICS_BOARD_WIDTH*(mY/TACTICS_BOARD_PIXELS_SIZE) + mX/TACTICS_BOARD_PIXELS_SIZE; //index in array of space selected
        if(tilesArray[shipSelected]->entity->movementSpeed >=
               ( abs(shipSelected/TACTICS_BOARD_WIDTH - locationSelected/TACTICS_BOARD_WIDTH) +
                 abs(shipSelected%TACTICS_BOARD_WIDTH - locationSelected%TACTICS_BOARD_WIDTH)  )
           ) {

            if(tilesArray[locationSelected]->entity->entityType == ENTITY_EMPTY) {

                TacticsTile* hold = tilesArray[locationSelected];
                tilesArray[locationSelected] = tilesArray[shipSelected];
                tilesArray[shipSelected] =  hold;
                shipSelected = -1;

            }

        }

    }

}
