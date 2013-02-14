#include "RhythmGame.h"

std::vector<directions> RhythmGame::currentRhythmDirections;
std::vector<directions> RhythmGame::currentRhythmTimings;

RhythmGame::RhythmGame() {

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

void RhythmGame::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {

    /*if(sym == SDLK_SPACE) {
        if(state_infoVisorUp)
            state_infoVisorUp = false;
        else
            state_infoVisorUp = true;
    }
    if(sym == SDLK_RETURN) {
        if(state_dialog)
            testDialog->currentLine++;
    }*/

}
