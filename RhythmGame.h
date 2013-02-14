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

        typedef void (RhythmGame::*func)();

    private:

        static std::vector<directions> currentRhythmDirections;
        static std::vector<directions> currentRhythmTimings;

        int bpm; //beats per minute

    public:

        RhythmGame();
        ~RhythmGame();

        static func OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);

};

#endif // RHYTHMGAME_H_INCLUDED
