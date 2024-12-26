#include <stdlib.h>
#include <stdio.h>
#include "board.h"
#include "print_colors.h"
#include "solver.h"
#include <string.h>

void counter(int board[], int clusterPositions[]);

static int oldBoard[BOARD_SIZE] = {O,R,G,B,O,R,B,
                B,B,B,R,O,R,G,
                R,G,R,O,O,B,O,
                G,G,O,O,R,R,B,
                R,G,R,R,B,B,O,
                O,G,O,R,O,O,B,
                O,O,B,R,B,B,G,
                B,B,B,R,G,B,O,
                R,B,G,G,R,O,R};

static int board[BOARD_SIZE] = {G, R, B, G, O, B, B,
                                    B, G, B, G, R, G, B,
                                    O, B, B, R, G, R, R,
                                    B, R, B, B, R, O, R,
                                    G, O, B, G, O, O, O,
                                    B, O, O, G, B, O, O,
                                    B, B, O, R, O, G, G,
                                    O, B, O, B, G, G, G,
                                    G, B, G, R, B, B, B
                                    };

static int clusterBoard[BOARD_SIZE]; 
static int clusterPositions[BOARD_SIZE];


int main(int argc, char const *argv[]) {   
    int savedMoves[BOARD_SIZE];
    int numMoves = 0;
    // volatile int x, y;
    int move;
    while (findClusters(clusterBoard, board, clusterPositions) > 0) {
        printf("\n");
        printBoard(board);
        BG_WHITE();
        printf("ClusterBoard: \n");
        printClusterBoard(clusterBoard);
        // printf("\n\nSkriv in input på format (x y): ");
        // scanf("%i %i", &x, &y);
        // int idx = x*ROW_SIZE+y;
        move = findBestMove(board, clusterBoard, 5, clusterPositions);
        savedMoves[numMoves] = move;
        // printf("The move is: %d", move);
        if (board[move] == E) {
            //printf("%d", move);
            continue;
        }

        counter(board, clusterPositions);
        makeMove(board, move);
        numMoves++;
    }
    printf("Congratulerer du fikk det til på dette antall trekk din amøbe: %d,", numMoves);
    printf("The moves are: ");
    for (int i = 0; i < numMoves; i++) {
        int move = savedMoves[i];
        int row = move / ROW_SIZE;
        int col = move % ROW_SIZE;
        printf(" (%d, %d)", row, col);
    }
    return 0;
}






void counter(int board[], int clusterPositions[]) {
    int numberOfClusters = findClusters(clusterBoard, board, clusterPositions);
    int copyOfBoard[BOARD_SIZE];
    int countingArray[BOARD_SIZE];
    int count;
    for (int i = 1; i <= numberOfClusters; i++) {
        memcpy(copyOfBoard, board, BOARD_SIZE * sizeof(int));
        makeMove(copyOfBoard, clusterPositions[i]);
        count = countPieces(copyOfBoard);
        printf("Count: %d", count);
    }
    

    return;
}
