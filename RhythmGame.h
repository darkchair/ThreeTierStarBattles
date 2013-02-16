#ifndef RHYTHMGAME_H_INCLUDED
#define RHYTHMGAME_H_INCLUDED

#include <vector>
#include <stdio.h>
#include <SDL/SDL.h>

#include "CSurface.h"

enum directions {

    left,
    up,
    down,
    right,
    none

};

class RhythmGame {

    public:

        std::vector<directions> currentRhythmDirections;
        std::vector<int> currentRhythmTimings;

        int bpm; //beats per minute

        int startTime;

        int nextNote; //location in vector of next note that needs to be pressed

        int hits; //notes hit

        int secondChecker;
        int secondCheckerTimer;

    public:

        static bool started;

    public:

        RhythmGame();
        ~RhythmGame();

        void startGame();
        bool isStarted();

        void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);

        void OnLoop();

        void OnRender();

};

#endif // RHYTHMGAME_H_INCLUDED
