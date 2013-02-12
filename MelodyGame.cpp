#include "MelodyGame.h"

std::string MelodyGame::currentMelody;

MelodyGame::MelodyGame() {

    FILE* melodyFile = fopen("melody1.txt", "r");

    std::string tempStr;
    while(!feof(melodyFile)) {

        fscanf(melodyFile, "%s", &tempStr);
        MelodyGame::currentMelody += tempStr;
        MelodyGame::currentMelody += ":";

    }

    fclose(melodyFile);

}

MelodyGame::~MelodyGame() {



}
