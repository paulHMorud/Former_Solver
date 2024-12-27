#include <stdlib.h>
#include <stdio.h>
#include "board.h"
#include "print_colors.h"
#include "solver.h"
#include <string.h>

void counter(struct board* board);

static struct board board = {
    .tiles = {
        O, G, B, O, B, G, B,
        O, G, O, O, O, G, R,
        R, G, R, R, G, O, G,
        O, G, O, G, G, G, R,
        O, R, G, R, O, G, O,
        R, B, G, R, R, R, G,
        O, G, R, R, R, G, O,
        B, B, R, B, B, R, O,
        G, O, B, O, O, O, G
    },
    .clusters = {0},
    .clusterPositions = {0},
};


int main(int argc, char const *argv[]) {   
    int savedMoves[BOARD_SIZE];
    int numMoves = 0;
    int move;
    while (findClusters(&board) > 0) {
        printf("\n");
        printBoard(&board);
        BG_WHITE();
        // printf("ClusterBoard: \n");
        // printClusterBoard(&board);
        move = findBestMove(&board, 4);
        savedMoves[numMoves] = move;
        if (board.tiles[move] == E) {
            continue;
        }
        makeMove(&board, move);
        numMoves++;
    }
    printf("Congratulerer du fikk det til på dette antall trekk din amøbe: %d\n", numMoves);
    printf("The moves are: ");
    for (int i = 0; i < numMoves; i++) {
        int move = savedMoves[i];
        int row = move / ROW_SIZE;
        int col = move % ROW_SIZE;
        printf(" (%d, %d)", row, col);
    }
    return 0;
}
