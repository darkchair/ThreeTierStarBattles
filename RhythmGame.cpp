#include "RhythmGame.h"

bool RhythmGame::started;

RhythmGame::RhythmGame() {

    started = false;
    nextNote = 0;

    //Read rhythm from file
    FILE* rhythmFile = fopen("rhythmDirections1.txt", "r");

    int tempInt;

    while(!feof(rhythmFile)) {

        fscanf(rhythmFile, "%d", &tempInt);
        RhythmGame::currentRhythmDirections.push_back((directions)tempInt);

    }

    fclose(rhythmFile);

    rhythmFile = fopen("rhythmTimings1.txt", "r");

    //int tempInt;

    if(!feof(rhythmFile))
        fscanf(rhythmFile, "%d", &bpm);

    while(!feof(rhythmFile)) {

        fscanf(rhythmFile, "%d", &tempInt);
        RhythmGame::currentRhythmTimings.push_back((directions)tempInt);

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

    if(RhythmGame::currentRhythmDirections.size() == 0 || RhythmGame::currentRhythmTimings.size() == 0)
        int i = 9;

    else if
    (
       tempDir == currentRhythmDirections.at(nextNote)
    && ((timeOfPress-startTime > currentRhythmTimings.at(nextNote) - 100) && (timeOfPress-startTime < currentRhythmTimings.at(nextNote) + 100))
    )
    {
        hits++;
    }

}

void RhythmGame::OnLoop() {

    //if(SDL_GetTicks() > currentRhythmTimings[nextNote] + 100)
    //    nextNote++;

}
