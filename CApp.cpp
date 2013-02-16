#include "CApp.h"

CApp::CApp() {
    Surf_Background = NULL;
    Surf_ShipPanel = NULL;
    Surf_Ship = NULL;
    Surf_InfoVisor = NULL;
    Surf_InterceptorPanel = NULL;
    Surf_TacticsGrid = NULL;
    Surf_Asteroids = NULL;
    Surf_OverheadShip = NULL;
    Surf_OverheadShip2 = NULL;
    Surf_CardSelectionPanel = NULL;
    Surf_StrategicBoard = NULL;
    Surf_RhythmBackground = NULL;
    Surf_LeftArrow = NULL;
    Surf_DialogBackground = NULL;
    Surf_DialogBox = NULL;
    Surf_EnemyShip = NULL;
    Surf_TextHolder = NULL;

    Surf_Display = NULL;

    Sommet16 = NULL;
    Sommet18 = NULL;
    Sommet24 = NULL;
    Sommet30 = NULL;
    textColor = {255, 255, 255};


    state_infoVisorUp = false;
    state_rhythmBattle = false;
    state_melodyBattle = false;
    state_tacticsBattle = false;
    state_cardSelection = false;
    state_strategicBattle = false;
    state_dialog = false;



    Running = true;
}

int CApp::OnExecute() {
    if(OnInit() == false) {
        return -1;
    }

    SDL_Event Event;

    while(Running) {
        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }

        OnLoop();
        OnRender();
    }

    OnCleanup();

    return 0;
}

int main(int argc, char* argv[]) {
    CApp theApp;

    return theApp.OnExecute();
}
