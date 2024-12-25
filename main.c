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
    int numMoves = 0;
    // volatile int x, y;
    volatile int move;
    while (findClusters(clusterBoard, board, clusterPositions) > 1) {
        printf("\n");
        printBoard(board);
        BG_WHITE();
        // printf("\n\nSkriv in input på format (x y): ");
        // scanf("%i %i", &x, &y);
        // int idx = x*ROW_SIZE+y;
        move = findBestMove(board, clusterBoard, 4, clusterPositions);
        if (board[move] == E) {
            printf("%d", move);
            continue;
        }
        makeMove(board, move);
        numMoves++;
    }
    printf("Congratulerer du fikk det til på dette antall trekk din amøbe: %d,", numMoves);
    return 0;
}

