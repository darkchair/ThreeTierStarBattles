#include "StrategyGame.h"

StrategyGame::StrategyGame() {

    pieceSelected = -1;

    for(int i=0; i<STRATEGY_BOARD_WIDTH; i++) {
        pieceArray[8*1+i] = new StrategyPiece(PIECE_PAWN);
        pieceArray[8*2+i] = new StrategyPiece(PIECE_EMPTY);
        pieceArray[8*3+i] = new StrategyPiece(PIECE_EMPTY);
        pieceArray[8*4+i] = new StrategyPiece(PIECE_EMPTY);
        pieceArray[8*5+i] = new StrategyPiece(PIECE_EMPTY);
        pieceArray[8*6+i] = new StrategyPiece(PIECE_PAWN);
    }

    pieceArray[0] = new StrategyPiece(PIECE_ROOK);
    pieceArray[1] = new StrategyPiece(PIECE_KNIGHT);
    pieceArray[2] = new StrategyPiece(PIECE_BISHOP);
    pieceArray[3] = new StrategyPiece(PIECE_QUEEN);
    pieceArray[4] = new StrategyPiece(PIECE_KING);
    pieceArray[5] = new StrategyPiece(PIECE_BISHOP);
    pieceArray[6] = new StrategyPiece(PIECE_KNIGHT);
    pieceArray[7] = new StrategyPiece(PIECE_ROOK);

    pieceArray[56] = new StrategyPiece(PIECE_ROOK);
    pieceArray[57] = new StrategyPiece(PIECE_KNIGHT);
    pieceArray[58] = new StrategyPiece(PIECE_BISHOP);
    pieceArray[59] = new StrategyPiece(PIECE_QUEEN);
    pieceArray[60] = new StrategyPiece(PIECE_KING);
    pieceArray[61] = new StrategyPiece(PIECE_BISHOP);
    pieceArray[62] = new StrategyPiece(PIECE_KNIGHT);
    pieceArray[63] = new StrategyPiece(PIECE_ROOK);

}

StrategyGame::~StrategyGame() {



}

StrategyPiece** StrategyGame::getPieceArray() {

    return pieceArray;

}

void StrategyGame::OnLButtonDown(int mX, int mY) {

    pieceSelected = -1;

    for(int i=0; i<STRATEGY_BOARD_HEIGHT; i++) {

        for(int j=0; j<STRATEGY_BOARD_WIDTH; j++) {

            if((mX >= j*STRATEGY_BOARD_PIXELS_SIZE + STRATEGY_BOARD_X_OFFSET) &&
               (mX <= j*STRATEGY_BOARD_PIXELS_SIZE + STRATEGY_BOARD_PIXELS_SIZE + STRATEGY_BOARD_X_OFFSET) &&
               (mY >= i*STRATEGY_BOARD_PIXELS_SIZE + STRATEGY_BOARD_Y_OFFSET) &&
               (mY <= i*STRATEGY_BOARD_PIXELS_SIZE + STRATEGY_BOARD_PIXELS_SIZE + STRATEGY_BOARD_Y_OFFSET)) {

                if(pieceArray[i*STRATEGY_BOARD_WIDTH + j]->type != PIECE_EMPTY) {
                    pieceSelected = i*STRATEGY_BOARD_WIDTH + j;
                }

            }

        }

    }

}
