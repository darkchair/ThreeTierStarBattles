#include "CApp.h"

bool CApp::OnInit() {

    srand( time(NULL) );

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        return false;
    }

    if (TTF_Init() < 0) {
        return false;
    }

    if(!OnInitSurfaces()) {
        return false;
    }

    Sommet16 = TTF_OpenFont("Sommet.ttf", 16);
    Sommet18 = TTF_OpenFont("Sommet.ttf", 18);
    Sommet24 = TTF_OpenFont("Sommet.ttf", 24);
    Sommet30 = TTF_OpenFont("Sommet.ttf", 30);

    testDialog = new Dialog();
    testDialog->openDialog("introDialog.txt");

    int random = rand() % 5 + 1;
    for(int i=0; i<random; i++)
        EnemyInterceptor::interceptors.push_back(new EnemyInterceptor());

    tacticsGame = new TacticsGame::TacticsGame();


    return true;
}

bool CApp::OnInitSurfaces() {

    if((Surf_Display = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        return false;
    }

    if((Surf_Background = CSurface::OnLoad("Images/background.png")) == NULL) {
        return false;
    }
    if((Surf_ShipPanel = CSurface::OnLoad("Images/shipPanelTemplate.png")) == NULL) {
        return false;
    }
        ShipPanelAnimation.MaxFrames = 500;

    if((Surf_Ship = CSurface::OnLoad("Images/ship1Template.png")) == NULL) {
        return false;
    }
    if((Surf_InfoVisor = CSurface::OnLoad("Images/infoVisorTemplate.png")) == NULL) {
        return false;
    }
    if((Surf_InterceptorPanel = CSurface::OnLoad("Images/interceptorTemplate.png")) == NULL) {
        return false;
    }
    if((Surf_TacticsGrid = CSurface::OnLoad("Images/tacticsGrid.png")) == NULL) {
        return false;
    }
    if((Surf_Asteroids = CSurface::OnLoad("Images/asteroids.png")) == NULL) {
        return false;
    }
    if((Surf_OverheadShip = CSurface::OnLoad("Images/overheadShip1.png")) == NULL) {
        return false;
    }
    if((Surf_OverheadShip2 = CSurface::OnLoad("Images/overheadShip2.png")) == NULL) {
        return false;
    }
    if((Surf_CardSelectionPanel = CSurface::OnLoad("Images/cardSelectionVisor.png")) == NULL) {
        return false;
    }
    if((Surf_DialogBackground = CSurface::OnLoad("Images/dialogBackground.png")) == NULL) {
        return false;
    }
    if((Surf_DialogBox = CSurface::OnLoad("Images/dialogBox.png")) == NULL) {
        return false;
    }
    if((Surf_EnemyShip = CSurface::OnLoad("Images/enemyShip1Template.png")) == NULL) {
        return false;
    }
    if((Surf_StrategicBoard = CSurface::OnLoad("Images/strategicBoard.png")) == NULL) {
        return false;
    }
    if((Surf_TextHolder = CSurface::OnLoad("Images/opponentsStats.png")) == NULL) {
        return false;
    }

    return true;

}
