#include "RhythmGame.h"

bool RhythmGame::started;

RhythmGame::RhythmGame() {

    started = false;
    nextNote = 0;
    secondChecker = 0;
    secondCheckerTimer = 0;
    currentRhythmTimings.assign(500, -2);
    currentRhythmDirections.assign(500, (directions)4);

    //Read rhythm from file
    FILE* rhythmFile = fopen("rhythmDirections1.txt", "r");

    int tempInt;
    int where = 0;

    while(!feof(rhythmFile)) {

        fscanf(rhythmFile, "%d", &tempInt);
        currentRhythmDirections[where] = ((directions)tempInt);
        where++;

    }

    fclose(rhythmFile);

    rhythmFile = fopen("rhythmTimings1.txt", "r");

    //int tempInt;
    where = 0;

    if(!feof(rhythmFile))
        fscanf(rhythmFile, "%d", &bpm);

    while(!feof(rhythmFile)) {

        fscanf(rhythmFile, "%d", &tempInt);
        currentRhythmTimings[where] = (tempInt);
        where++;

    }

    fclose(rhythmFile);

}

RhythmGame::~RhythmGame() {



}

void RhythmGame::startGame() {

    RhythmGame::started = true;
    startTime = SDL_GetTicks();

}

bool RhythmGame::isStarted() {

    if(started)
        return true;

    return false;

}

void RhythmGame::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {

    int timeOfPress = SDL_GetTicks();

    int tempDir;

    if(sym == SDLK_UP)
        tempDir = 0;
    if(sym == SDLK_DOWN)
        tempDir = 1;
    if(sym == SDLK_LEFT)
        tempDir = 2;
    if(sym == SDLK_RIGHT)
        tempDir = 3;

    if
    (
       tempDir == currentRhythmDirections.at(nextNote)
    && ((timeOfPress-startTime > currentRhythmTimings.at(nextNote) - 100) && (timeOfPress-startTime < currentRhythmTimings.at(nextNote) + 100))
    )
    {
        hits++;
    }

}

void RhythmGame::OnLoop() {

    //if 1000ms has passed, skip the -1 to the next section of notes
    secondChecker += SDL_GetTicks() - startTime - secondCheckerTimer;
    if(currentRhythmTimings.at(nextNote) != -1 && currentRhythmTimings.at(nextNote) != -2 && secondChecker > currentRhythmTimings.at(nextNote)) {

        nextNote++;

    }
    if(secondChecker > 1000) {

        if(currentRhythmTimings.at(nextNote) == -1) {
            nextNote++;
        }
        if(currentRhythmTimings.at(nextNote) == -2) {
            started = false;
        }
        else
            int notGood;

        secondChecker = 0;
        secondCheckerTimer += 1000;

    }

}

void RhythmGame::OnRender() {



}
