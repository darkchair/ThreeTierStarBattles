#include "CApp.h"

void CApp::OnRender() {
    if(state_dialog) {
        CSurface::OnDraw(Surf_Display, Surf_DialogBackground, 0, 0);
        CSurface::OnDraw(Surf_Display, Surf_DialogBox, 0, 420);

     /*   //If there are more than 9 lines, scrolling needs to happen
        //If there are more than 140 characters on a line, a new line needs to be made
        int i=0;
        while(testDialog->dialog.at(i) != "" && i <= testDialog->currentLine) {
            Surf_TextHolder = TTF_RenderText_Blended( Sommet16, testDialog->dialog.at(i).c_str(), textColor );
            CSurface::OnDraw(Surf_Display, Surf_TextHolder, 40, 450 + 25*i);
            SDL_FreeSurface(Surf_TextHolder);
            i++;
        }

        Surf_TextHolder = TTF_RenderText_Blended( Sommet18, "<Enter>", textColor );
        CSurface::OnDraw(Surf_Display, Surf_TextHolder, 900, 670);
        SDL_FreeSurface(Surf_TextHolder);*/
    }
    else {
        CSurface::OnDraw(Surf_Display, Surf_Background, 0, 0);

        if(state_tacticsBattle) {
            CSurface::OnDraw(Surf_Display, Surf_TacticsGrid, 0, 0);
            //CSurface::OnDraw(Surf_Display, Surf_Asteroids, 300, 200);
            //CSurface::OnDraw(Surf_Display, Surf_OverheadShip, 20, 120);

            TacticsTile** tacticsTilesArray = tacticsGame->getTilesArray();
            for(int i=0; i<TACTICS_BOARD_HEIGHT; i++)
            {

                for(int j=0; j<TACTICS_BOARD_WIDTH; j++)
                {
                    if(tacticsTilesArray[i*TACTICS_BOARD_WIDTH + j]->entity->entityType == asteroid)
                        CSurface::OnDraw(Surf_Display, Surf_Asteroids, j*TACTICS_BOARD_PIXELS_SIZE, i*TACTICS_BOARD_PIXELS_SIZE);
                    else if(tacticsTilesArray[i*TACTICS_BOARD_WIDTH + j]->entity->entityType == shipFriend)
                        CSurface::OnDraw(Surf_Display, Surf_OverheadShip, j*TACTICS_BOARD_PIXELS_SIZE, i*TACTICS_BOARD_PIXELS_SIZE);
                    else if(tacticsTilesArray[i*TACTICS_BOARD_WIDTH + j]->entity->entityType == shipEnemy)
                        CSurface::OnDraw(Surf_Display, Surf_OverheadShip2, j*TACTICS_BOARD_PIXELS_SIZE, i*TACTICS_BOARD_PIXELS_SIZE);
                    //Else the space is blank
                }

            }

            if(state_cardSelection)
                CSurface::OnDraw(Surf_Display, Surf_CardSelectionPanel, 0, 0);
        }
        else if(state_strategicBattle) {
            CSurface::OnDraw(Surf_Display, Surf_StrategicBoard, 150, 50);
        }
        else {
            CSurface::OnDraw(Surf_Display, Surf_ShipPanel, 0, 0);
            CSurface::OnDraw(Surf_Display, Surf_Ship, 75, 140);
        }
    }
    if(state_infoVisorUp) {
        CSurface::OnDraw(Surf_Display, Surf_InfoVisor, 1000 - ShipPanelAnimation.CurrentFrame, 0);
        if(ShipPanelAnimation.CurrentFrame < 500)
            ShipPanelAnimation.CurrentFrame += 4;
        else {
            Surf_TextHolder = TTF_RenderText_Blended( Sommet18, "Dialog", textColor );
            CSurface::OnDraw(Surf_Display, Surf_TextHolder, 1070 - ShipPanelAnimation.CurrentFrame, 360);
            SDL_FreeSurface(Surf_TextHolder);
            Surf_TextHolder = TTF_RenderText_Blended( Sommet18, "Home", textColor );
            CSurface::OnDraw(Surf_Display, Surf_TextHolder, 1070 - ShipPanelAnimation.CurrentFrame, 460);
            SDL_FreeSurface(Surf_TextHolder);
            Surf_TextHolder = TTF_RenderText_Blended( Sommet18, "Strategic", textColor );
            CSurface::OnDraw(Surf_Display, Surf_TextHolder, 1220 - ShipPanelAnimation.CurrentFrame, 460);
            SDL_FreeSurface(Surf_TextHolder);
            Surf_TextHolder = TTF_RenderText_Blended( Sommet18, "Tactical", textColor );
            CSurface::OnDraw(Surf_Display, Surf_TextHolder, 1370 - ShipPanelAnimation.CurrentFrame, 460);
            SDL_FreeSurface(Surf_TextHolder);
        }
    }
    else {
        if(ShipPanelAnimation.CurrentFrame > 0) {
            CSurface::OnDraw(Surf_Display, Surf_InfoVisor, 1000 - ShipPanelAnimation.CurrentFrame, 0);
            ShipPanelAnimation.CurrentFrame -= 4;
        }
    }

    SDL_Flip(Surf_Display);
}
