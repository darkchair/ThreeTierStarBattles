#include "RhythmGame.h"

std::string RhythmGame::currentRhythm;

RhythmGame::RhythmGame() {

    FILE* rhythmFile = fopen("rhythm1.txt", "r");

    std::string tempStr;
    while(!feof(rhythmFile)) {

        fscanf(rhythmFile, "%s", &tempStr);
        RhythmGame::currentRhythm  += tempStr;
        RhythmGame::currentRhythm += ":";

    }

    fclose(rhythmFile);

}

RhythmGame::~RhythmGame() {



}
