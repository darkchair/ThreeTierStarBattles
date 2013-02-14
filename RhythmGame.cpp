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
       tempDir == currentRhythmDirections[nextNote]
    && ((timeOfPress-startTime > currentRhythmTimings[nextNote] - 200) && (timeOfPress-startTime < currentRhythmTimings[nextNote] + 200))
    )
    {
        hits++;
    }

}
