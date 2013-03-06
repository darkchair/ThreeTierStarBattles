#include "CApp.h"

void CApp::OnEvent(SDL_Event* Event) {
    CEvent::OnEvent(Event);
}

void CApp::OnExit() {
    Running = false;
}

void CApp::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {

    if(state_rhythmBattle && RhythmGame::started) {
        rhythmGame->OnKeyDown(sym, mod, unicode);
    }
    else if(state_melodyBattle) {
        //RhythmGame::OnKeyDown(sym, mod, unicode);
    }

    if(sym == SDLK_SPACE) {
        if(state_infoVisorUp)
            state_infoVisorUp = false;
        else
            state_infoVisorUp = true;
    }
    if(sym == SDLK_RETURN) {
        if(state_dialog)
            testDialog->currentLine++;
        if(state_rhythmBattle && !RhythmGame::started) {
            rhythmGame = new RhythmGame();
            rhythmGame->startGame();
        }
    }

}

void CApp::OnLButtonDown(int mX, int mY) {

    if(state_infoVisorUp) {

        if(mX >= 560+306 && mY >= 160 && mX <= 1000 && mY <= 492) {
            state_tacticsBattle = true;
            state_strategicBattle = false;
            state_rhythmBattle = false;
            state_melodyBattle = false;
        }
        else if(mX >= 560 && mY >= 392 && mX <= 560+140 && mY <= 492) {
            //if(state_interceptorBattle) {
                EnemyInterceptor::exitBattle();
                state_tacticsBattle = false;
            //}
            if(state_strategicBattle)
                state_strategicBattle = false;
            else if(state_rhythmBattle)
                state_rhythmBattle = false;
            else if(state_melodyBattle)
                state_melodyBattle = false;
        }
        else if(mX >= 560+145 && mY >= 160 && mX <= 560+301 && mY <= 492) {
            state_rhythmBattle = false;
            state_melodyBattle = false;
            state_tacticsBattle = false;
            state_strategicBattle = true;
        }
        else if(mX >= 560 && mY >= 160 && mX <= 560+140 && mY <= 390) {
            state_tacticsBattle = false;
            state_strategicBattle = false;
            //-------------------------
            state_rhythmBattle = true;
            state_melodyBattle = false;
            //-------------------------
        }

    }

    else if(state_tacticsBattle) {

        tacticsGame->OnLButtonDown(mX, mY);

    }

    else if(state_strategicBattle) {

        if(mX >= 0 && mY >= 0 && mX <= 205 && mY <= 246) {
            //Show Commands
        }

        strategyGame->OnLButtonDown(mX, mY);

    }

}

void CApp::OnRButtonDown(int mX, int mY) {

    if(state_tacticsBattle) {

        tacticsGame->OnRButtonDown(mX, mY);

    }

}
