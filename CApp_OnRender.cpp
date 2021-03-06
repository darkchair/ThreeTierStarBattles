#include "CApp.h"

void CApp::OnRender() {
    if(state_dialog) {
        drawDialog();
    }
    else {
        CSurface::OnDraw(Surf_Display, Surf_Background, 0, 0);

        if(state_tacticsBattle) {
            drawTacticsGame();
        }
        else if(state_strategicBattle) {
            drawStrategyGame();
        }
        else if(state_rhythmBattle) {
            drawRhythmGame();
        }
        else if(state_melodyBattle) {

        }
        else {
            drawMainScreen();
        }
    }
    if(state_infoVisorUp) {
        drawInfoVisorIn();
    }
    else {
        drawInfoVisorOut();
    }

    SDL_Flip(Surf_Display);
}



void CApp::drawDialog() {

    CSurface::OnDraw(Surf_Display, Surf_DialogBackground, 0, 0);
    CSurface::OnDraw(Surf_Display, Surf_DialogBox, 0, 420);

    //If there are more than 9 lines, scrolling needs to happen
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
    SDL_FreeSurface(Surf_TextHolder);

}

void CApp::drawTacticsGame() {

    CSurface::OnDraw(Surf_Display, Surf_TacticsGrid, 0, 0);

    drawTacticsEntities();

    if(tacticsGame->cardSelection)
        CSurface::OnDraw(Surf_Display, Surf_CardSelectionPanel, 0, 0);

    if(tacticsGame->shipSelected != -1) {
        CSurface::OnDraw(Surf_Display, Surf_TacticsSelectionBorder,
                        (tacticsGame->shipSelected%TACTICS_BOARD_WIDTH)*TACTICS_BOARD_PIXELS_SIZE,
                        (tacticsGame->shipSelected/TACTICS_BOARD_WIDTH)*TACTICS_BOARD_PIXELS_SIZE);

        Surf_TextHolder = TTF_RenderText_Blended( Sommet18, "<R-Click>", textColor );
        CSurface::OnDraw(Surf_Display, Surf_TextHolder, 900, 600);
        SDL_FreeSurface(Surf_TextHolder);
    }
    else {
        Surf_TextHolder = TTF_RenderText_Blended( Sommet18, "<L-Click>", textColor );
        CSurface::OnDraw(Surf_Display, Surf_TextHolder, 900, 600);
        SDL_FreeSurface(Surf_TextHolder);
    }

}

void CApp::drawTacticsEntities() {

    TacticsTile** tacticsTilesArray = tacticsGame->getTilesArray();
    for(int i=0; i<TACTICS_BOARD_HEIGHT; i++)
    {

        for(int j=0; j<TACTICS_BOARD_WIDTH; j++)
        {
            if(tacticsTilesArray[i*TACTICS_BOARD_WIDTH + j]->entity->entityType == ENTITY_ASTEROID)
                CSurface::OnDraw(Surf_Display, Surf_Asteroids, j*TACTICS_BOARD_PIXELS_SIZE, i*TACTICS_BOARD_PIXELS_SIZE);
            else if(tacticsTilesArray[i*TACTICS_BOARD_WIDTH + j]->entity->entityType == ENTITY_SHIPFRIEND)
                CSurface::OnDraw(Surf_Display, Surf_OverheadShip, j*TACTICS_BOARD_PIXELS_SIZE, i*TACTICS_BOARD_PIXELS_SIZE);
            else if(tacticsTilesArray[i*TACTICS_BOARD_WIDTH + j]->entity->entityType == ENTITY_SHIPENEMY)
                CSurface::OnDraw(Surf_Display, Surf_OverheadShip2, j*TACTICS_BOARD_PIXELS_SIZE, i*TACTICS_BOARD_PIXELS_SIZE);
            //Else the space is blank
        }

    }

}

void CApp::drawStrategyGame() {

    CSurface::OnDraw(Surf_Display, Surf_StrategicBoard, 0, 0);
    drawStrategyPieces();
    if(strategyGame->pieceSelected != -1) {
        CSurface::OnDraw(Surf_Display, Surf_StrategicSelectionBorder,
                        (strategyGame->pieceSelected%STRATEGY_BOARD_WIDTH)*STRATEGY_BOARD_PIXELS_SIZE + STRATEGY_BOARD_X_OFFSET,
                        (strategyGame->pieceSelected/STRATEGY_BOARD_WIDTH)*STRATEGY_BOARD_PIXELS_SIZE + STRATEGY_BOARD_Y_OFFSET);
    }

}

void CApp::drawStrategyPieces() {

    StrategyPiece** pieceArray = strategyGame->getPieceArray();

    for(int i=0; i<STRATEGY_BOARD_WIDTH*STRATEGY_BOARD_HEIGHT; i++) {

        if(pieceArray[i]->type != PIECE_EMPTY) {
            CSurface::OnDraw(Surf_Display, Surf_ChessPiecesLettersSheet,
                            i%STRATEGY_BOARD_WIDTH * STRATEGY_BOARD_PIXELS_SIZE + STRATEGY_BOARD_X_OFFSET,
                            i/STRATEGY_BOARD_HEIGHT * STRATEGY_BOARD_PIXELS_SIZE + STRATEGY_BOARD_Y_OFFSET,
                            pieceArray[i]->type * STRATEGY_BOARD_PIXELS_SIZE,
                            0,
                            STRATEGY_BOARD_PIXELS_SIZE, STRATEGY_BOARD_PIXELS_SIZE);
        }

    }

}

void CApp::drawRhythmGame() {

    char temp [50];

    int tempTime  = SDL_GetTicks();

    CSurface::OnDraw(Surf_Display, Surf_RhythmBackground, 200, 50);
    if(!rhythmGame->isStarted()) {
        Surf_TextHolder = TTF_RenderText_Blended( Sommet18, "<Enter>", textColor );
        CSurface::OnDraw(Surf_Display, Surf_TextHolder, 850, 600);
        SDL_FreeSurface(Surf_TextHolder);
    }
    else {
        //Draw the background arrows onto the board
        CSurface::OnDraw(Surf_Display, Surf_ArrowSheet, 225, 500, 200, 0, 100, 100);
        CSurface::OnDraw(Surf_Display, Surf_ArrowSheet, 375, 500, 0, 0, 100, 100);
        CSurface::OnDraw(Surf_Display, Surf_ArrowSheet, 525, 500, 100, 0, 100, 100);
        CSurface::OnDraw(Surf_Display, Surf_ArrowSheet, 675, 500, 300, 0, 100, 100);

        int currTime = SDL_GetTicks() - rhythmGame->startTime;
        int timeCount = currTime;
        //For the rest of the current second display the notes onto
        //the screen based on when they should be pressed
        for(int i = rhythmGame->nextNote; timeCount < currTime + 1000; i++) {
            /* The rhythm game 'songs' are made from two files, a Timings file
            and a Directions file. The timings file is a series of integers listing
            at what millisecond the note is to be played. A -1 indicates the end
            of a second of time, breaking up the timings into seconds. A -2 indicates
            the end of the song. So a file reading '200 400 650 -1 200 400 700 -2'
            would have a note at 200ms, 400ms, 650ms, 1200ms, 1400ms, and 1700ms.
            The Directions file matches one to one with each note timing in
            the Timings file.*/

            int width; int height;
            int timing = rhythmGame->currentRhythmTimings[i]; //
            directions dir = rhythmGame->currentRhythmDirections[i];

            if(timing == -2)
                break;//Song is over
            else if(timing == -1)
                timeCount += 1000;//Current second is over
            else if(timeCount + timing < currTime + 1000) {

                width = 150*static_cast<int>(dir);
                height = 500 - ((timing - currTime%1000));
                CSurface::OnDraw(Surf_Display, Surf_ArrowNotesSheet, 225 + width, height, 100*(int)dir, 0,
                                 TACTICS_BOARD_PIXELS_SIZE, TACTICS_BOARD_PIXELS_SIZE);

            }

        }
        //Display number of milliseconds since the start of the game
        Surf_TextHolder = TTF_RenderText_Blended( Sommet18, itoa(static_cast<int>(SDL_GetTicks()) - rhythmGame->startTime, temp, 10), textColor );
        CSurface::OnDraw(Surf_Display, Surf_TextHolder, 850, 100);
        SDL_FreeSurface(Surf_TextHolder);
    }

}

void CApp::drawMainScreen() {

    CSurface::OnDraw(Surf_Display, Surf_ShipPanel, 0, 0);
    CSurface::OnDraw(Surf_Display, Surf_Ship, 75, 140);
    if(!state_infoVisorUp) {
        Surf_TextHolder = TTF_RenderText_Blended( Sommet18, "<Space>", textColor );
        CSurface::OnDraw(Surf_Display, Surf_TextHolder, 850, 600);
        SDL_FreeSurface(Surf_TextHolder);
    }

}

void CApp::drawInfoVisorIn() {

    CSurface::OnDraw(Surf_Display, Surf_InfoVisor, 1000 - ShipPanelAnimation.CurrentFrame, 0);
    if(ShipPanelAnimation.CurrentFrame < 500)
        ShipPanelAnimation.CurrentFrame += INFO_VISOR_PPS*CFPS::FPSControl.GetSpeedFactor();
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

void CApp::drawInfoVisorOut() {

    if(ShipPanelAnimation.CurrentFrame > 0) {
        CSurface::OnDraw(Surf_Display, Surf_InfoVisor, 1000 - ShipPanelAnimation.CurrentFrame, 0);
        ShipPanelAnimation.CurrentFrame -= INFO_VISOR_PPS*CFPS::FPSControl.GetSpeedFactor();
    }

}
