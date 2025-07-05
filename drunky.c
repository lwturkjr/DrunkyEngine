// drunky.c
#include "stdio.h"
#include "stdlib.h"
#include "defs.h"
#include "string.h"

#define FEN00 "rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1"
#define FEN01 "rnbqkbnr/pp1ppppp/8/2p5/4P3/8/PPPP1PPP/RNBQKBNR w KQkq c6 0 2"
#define FEN02 "rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq - 1 2"

int main() {

    AllInit();

    //S_BOARD board[1];
    //ParseFen(START_FEN, board);
    S_BOARD board[1]; // This isn't working, something with ParseFen function?

    ParseFen(START_FEN, board);
    PrintBoard(board);
    ParseFen(FEN00, board);
    PrintBoard(board);
    ParseFen(FEN01, board);
    PrintBoard(board);
    ParseFen(FEN02, board);
    PrintBoard(board);

    return 0;

}