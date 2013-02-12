#include "RhythmGame.h"

std::vector<directions> RhythmGame::currentRhythm;

RhythmGame::RhythmGame() {

    //Read rhythm from file
    FILE* rhythmFile = fopen("rhythm1.txt", "r");

    int tempInt;

    if(!feof(rhythmFile))
        fscanf(rhythmFile, "%d", &bpm);

    while(!feof(rhythmFile)) {

        fscanf(rhythmFile, "%d", &tempInt);
        RhythmGame::currentRhythm.push_back((directions)tempInt);

    }

    fclose(rhythmFile);

    //Convert rhythm string to bytes


}

RhythmGame::~RhythmGame() {



}
