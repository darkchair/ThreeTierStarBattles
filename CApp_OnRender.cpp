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

            if(tacticsGame->cardSelection)
                CSurface::OnDraw(Surf_Display, Surf_CardSelectionPanel, 0, 0);
        }
        else if(state_strategicBattle) {

            CSurface::OnDraw(Surf_Display, Surf_StrategicBoard, 150, 50);

        }
        else if(state_rhythmBattle) {

            char temp [50];

            int tempTime  = SDL_GetTicks();

            CSurface::OnDraw(Surf_Display, Surf_RhythmBackground, 200, 50);
            if(!rhythmGame->isStarted()) {
                Surf_TextHolder = TTF_RenderText_Blended( Sommet18, "<Enter>", textColor );
                CSurface::OnDraw(Surf_Display, Surf_TextHolder, 850, 600);
                SDL_FreeSurface(Surf_TextHolder);
            }
            else {
                CSurface::OnDraw(Surf_Display, Surf_ArrowSheet, 225, 500, 200, 0, 100, 100);
                CSurface::OnDraw(Surf_Display, Surf_ArrowSheet, 375, 500, 0, 0, 100, 100);
                CSurface::OnDraw(Surf_Display, Surf_ArrowSheet, 525, 500, 100, 0, 100, 100);
                CSurface::OnDraw(Surf_Display, Surf_ArrowSheet, 675, 500, 300, 0, 100, 100);

                int currTime = SDL_GetTicks() - rhythmGame->startTime;
                int timeCount = currTime;
                for(int i = rhythmGame->nextNote; timeCount < currTime + 1000; i++) {

                    int width; int height;
                    int timing = rhythmGame->currentRhythmTimings[i];
                    directions dir = rhythmGame->currentRhythmDirections[i];

                    if(timing == -2)
                        break;
                    else if(timing == -1)
                        timeCount += 1000;
                    else if(timeCount + timing < currTime + 1000) {

                        width = 150*(int)dir;
                        height = 500 - ((timing - currTime%1000)*6)/7;
                        CSurface::OnDraw(Surf_Display, Surf_ArrowNotesSheet, 225 + width, height, 100*(int)dir, 0, 100, 100);

                    }

                }

                Surf_TextHolder = TTF_RenderText_Blended( Sommet18, itoa((int)SDL_GetTicks() - rhythmGame->startTime, temp, 10), textColor );
                CSurface::OnDraw(Surf_Display, Surf_TextHolder, 850, 100);
                SDL_FreeSurface(Surf_TextHolder);
            }

        }
        else if(state_melodyBattle) {



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
            Surf_TextHolder = TTF_RenderText_Blended( Sommet18, "Skill", textColor );
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
