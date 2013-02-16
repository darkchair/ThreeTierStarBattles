#include "CApp.h"

void CApp::OnLoop() {

    CFPS::FPSControl.OnLoop();

    if(RhythmGame::started)
        rhythmGame->OnLoop();

}
