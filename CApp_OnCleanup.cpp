#include "CApp.h"

void CApp::OnCleanup() {
    SDL_FreeSurface(Surf_Background);
    SDL_FreeSurface(Surf_Display);

    TTF_CloseFont(Sommet18);
    TTF_CloseFont(Sommet24);
    TTF_CloseFont(Sommet30);
    TTF_Quit();

    SDL_Quit();
}
