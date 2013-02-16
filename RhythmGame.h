#ifndef RHYTHMGAME_H_INCLUDED
#define RHYTHMGAME_H_INCLUDED

#include <vector>
#include <stdio.h>
#include <SDL/SDL.h>

enum directions {

    up,
    down,
    left,
    right

};

class RhythmGame {

    public:

        std::vector<directions> currentRhythmDirections;
        std::vector<directions> currentRhythmTimings;

        int bpm; //beats per minute

        int startTime;

        int nextNote; //location in vector of next note that needs to be pressed

        int hits; //notes hit

    public:

        static bool started;

    public:

        RhythmGame();
        ~RhythmGame();

        void startGame();
        bool isStarted();

        void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);

        void OnLoop();

};

#endif // RHYTHMGAME_H_INCLUDED
