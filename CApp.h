#ifndef CAPP_H_INCLUDED
#define CAPP_H_INCLUDED

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include <time.h>

#include "CEvent.h"
#include "CSurface.h"
#include "CAnimation.h"
#include "CFPS.h"

#include "EnemyInterceptor.h"
#include "Dialog.h"
#include "StrategyGame.h"
#include "TacticsGame.h"
#include "SkillGame.h"
#include "RhythmGame.h"
#include "MelodyGame.h"



#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 700



class CApp : public CEvent {
    private:
        bool            Running;

        SDL_Surface*    Surf_Display;

    private:
        SDL_Surface*    Surf_Background;
        SDL_Surface*    Surf_ShipPanel;
        CAnimation      ShipPanelAnimation;
        SDL_Surface*    Surf_Ship;
        SDL_Surface*    Surf_InfoVisor;
        SDL_Surface*    Surf_InterceptorPanel;
        SDL_Surface*    Surf_TacticsGrid;
        SDL_Surface*    Surf_TacticsSelectionBorder;
        SDL_Surface*    Surf_Asteroids;
        SDL_Surface*    Surf_OverheadShip;
        SDL_Surface*    Surf_OverheadShip2;
        SDL_Surface*    Surf_CardSelectionPanel;
        SDL_Surface*    Surf_StrategicBoard;
        SDL_Surface*    Surf_StrategicSelectionBorder;
        SDL_Surface*    Surf_ChessPiecesLettersSheet;
        SDL_Surface*    Surf_RhythmBackground;
        SDL_Surface*    Surf_ArrowSheet;
        SDL_Surface*    Surf_ArrowNotesSheet;
        SDL_Surface*    Surf_DialogBackground;
        SDL_Surface*    Surf_DialogBox;
        SDL_Surface*    Surf_EnemyShip;
        SDL_Surface*    Surf_TextHolder;

        TTF_Font*       Sommet16;
        TTF_Font*       Sommet18;
        TTF_Font*       Sommet24;
        TTF_Font*       Sommet30;

        SDL_Color       textColor;

        Dialog*         testDialog;

        StrategyGame*   strategyGame;
        TacticsGame*    tacticsGame;
        RhythmGame*     rhythmGame;

    public:
        bool            state_infoVisorUp;
        bool            state_rhythmBattle;
        bool            state_melodyBattle;
        bool            state_tacticsBattle;
        bool            state_strategicBattle;
        bool            state_dialog;


    public:
        CApp();

        int OnExecute();

    public:
        bool OnInit();

            bool OnInitSurfaces();

        void OnEvent(SDL_Event* Event);

            void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
            void OnLButtonDown(int mX, int mY);
            void OnRButtonDown(int mX, int mY);

        void OnExit();

        void OnLoop();

        void OnRender();

            void drawTacticsEntities();
            void drawStrategicPieces();

        void OnCleanup();


};

#endif // CAPP_H_INCLUDED
