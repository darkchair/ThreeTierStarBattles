#include "CApp.h"

void CApp::OnLoop() {

    CFPS::FPSControl.OnLoop();

    rhythmGame->OnLoop();

}
