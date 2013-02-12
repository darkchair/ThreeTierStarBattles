#ifndef RHYTHMGAME_H_INCLUDED
#define RHYTHMGAME_H_INCLUDED

#include <vector>
#include <stdio.h>

enum directions {

    up,
    down,
    left,
    right

};

class RhythmGame {

    private:

        static std::vector<directions> currentRhythm;

        int bpm; //beats per minute

    public:

        RhythmGame();
        ~RhythmGame();

};

#endif // RHYTHMGAME_H_INCLUDED
