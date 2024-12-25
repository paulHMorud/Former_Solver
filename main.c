#include <stdlib.h>
#include <stdio.h>
#include "board.h"
#include "print_colors.h"
#include "solver.h"



static int board[BOARD_SIZE] = {O,R,G,B,O,R,B,
                B,B,B,R,O,R,G,
                R,G,R,O,O,B,O,
                G,G,O,O,R,R,B,
                R,G,R,R,B,B,O,
                O,G,O,R,O,O,B,
                O,O,B,R,B,B,G,
                B,B,B,R,G,B,O,
                R,B,G,G,R,O,R};

static int clusterBoard[BOARD_SIZE]; 
static int clusterPositions[BOARD_SIZE];


int main(int argc, char const *argv[]) {   
    // BG_RED();

    // int numMoves = 0;
    // volatile int x, y;
    // while (findClusters(clusterBoard, board, clusterPositions) != 0) {
    //     printf("\n");
    //     printBoard(board);
    //     BG_WHITE();
    //     printf("\n\nSkriv in input på format (x y): ");
    //     scanf("%i %i", &x, &y);
    //     int idx = x*ROW_SIZE+y;
    //     if (board[idx] == E) {
    //         resetBoard(clusterBoard);
    //         continue;
    //     }
    //     makeMove(board, idx);
    //     numMoves++;
    //     resetBoard(clusterBoard);
    // }
    // printf("Congratulerer du fikk det til på dette antall trekk din amøbe: %d,", numMoves);
    int move = findBestMove(board, clusterBoard, 5, clusterPositions);
    printf("The best move found is: %d", move);
    return 0;
}

