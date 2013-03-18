#include "CApp.h"

void CApp::OnCleanup() {

    SDL_FreeSurface(Surf_Background);
    SDL_FreeSurface(Surf_ShipPanel);
    SDL_FreeSurface(Surf_Ship);
    SDL_FreeSurface(Surf_InfoVisor);
    SDL_FreeSurface(Surf_InterceptorPanel);
    SDL_FreeSurface(Surf_TacticsGrid);
    SDL_FreeSurface(Surf_TacticsSelectionBorder);
    SDL_FreeSurface(Surf_Asteroids);
    SDL_FreeSurface(Surf_OverheadShip);
    SDL_FreeSurface(Surf_OverheadShip2);
    SDL_FreeSurface(Surf_CardSelectionPanel);
    SDL_FreeSurface(Surf_StrategicBoard);
    SDL_FreeSurface(Surf_StrategicSelectionBorder);
    SDL_FreeSurface(Surf_ChessPiecesLettersSheet);
    SDL_FreeSurface(Surf_RhythmBackground);
    SDL_FreeSurface(Surf_ArrowSheet);
    SDL_FreeSurface(Surf_ArrowNotesSheet);
    SDL_FreeSurface(Surf_DialogBackground);
    SDL_FreeSurface(Surf_DialogBox);
    SDL_FreeSurface(Surf_EnemyShip);
    SDL_FreeSurface(Surf_TextHolder);

    SDL_FreeSurface(Surf_Display);

    TTF_CloseFont(Sommet16);
    TTF_CloseFont(Sommet18);
    TTF_CloseFont(Sommet24);
    TTF_CloseFont(Sommet30);
    TTF_Quit();

    SDL_Quit();
}
