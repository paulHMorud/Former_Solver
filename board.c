#include <stdlib.h>
#include <stdio.h>
#include "board.h"
#include "print_colors.h"


void markCluster(struct board* board, int i, int clusterCount) {
    board->clusters[i] = clusterCount;
    if (i % ROW_SIZE != 0 && board->tiles[i] == board->tiles[i-1] && board->clusters[i-1] == 0) { //left
        markCluster(board, i-1, clusterCount);
    }
    if (i % ROW_SIZE != ROW_SIZE-1 && board->tiles[i] == board->tiles[i+1] && board->clusters[i+1] == 0) { //right
        markCluster(board, i+1, clusterCount);
    }
    if (i + UP >= 0 && board->tiles[i] == board->tiles[i+UP] && board->clusters[i+UP] == 0) { //up
        markCluster(board, i+UP, clusterCount);
    }
    if (i + DOWN < BOARD_SIZE && board->tiles[i] == board->tiles[i+DOWN] && board->clusters[i+DOWN] == 0) { //down
        markCluster(board, i+DOWN, clusterCount);
    }

}
int findClusters(struct board* board) {
    resetBoard(board->clusters);
    resetBoard(board->clusterPositions);
    int clusterCount = 1;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if ((board->clusters[i] != 0) || (board->tiles[i] == E)) {
            continue;
        }
        else {
            markCluster(board, i, clusterCount);
            board->clusterPositions[clusterCount] = i;
            clusterCount++;
        }
    }
    return clusterCount-1;
}

int findNumberOfClusters(struct board* board) {
    resetBoard(board->clusters);
    int clusterCount = 1;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if ((board->clusters[i] != 0) || (board->tiles[i] == E)) {
            continue;
        }
        else {
            markCluster(board, i, clusterCount);
            clusterCount++;
        }
    }
    return clusterCount-1;
}

void removeCluster(struct board* board, int i) {
    int color = board->tiles[i];
    board->tiles[i] = 0;
    if (i % ROW_SIZE != 0 && color == board->tiles[i-1] && board->tiles[i-1] != 0) { //left
        removeCluster(board, i-1);
    }
    if (i % ROW_SIZE != ROW_SIZE-1 && color == board->tiles[i+1] && board->tiles[i+1] != 0) { //right
        removeCluster(board, i+1);
    }
    if (i + UP >= 0 && color == board->tiles[i+UP] && board->tiles[i+UP] != 0) { //up
        removeCluster(board, i+UP);
    }
    if (i +DOWN < BOARD_SIZE && color == board->tiles[i+DOWN] && board->tiles[i+DOWN] != 0) { //down
        removeCluster(board, i+DOWN);
    }
}

void dropDown(struct board* board) {
    for (int col = 0; col < ROW_SIZE; col++) {
        int offset = 0;
        for (int row = COLUMN_SIZE-1; row >= 0; row--) {
            int idx = row*ROW_SIZE+col;
            if (board->tiles[idx] == E) {
                offset++;
            }
            else if (offset != 0) {
                board->tiles[idx+offset*ROW_SIZE]=board->tiles[idx];
                board->tiles[idx] = E;
            }
        }
    }
}

void makeMove(struct board* board, int idx) {
    if (board->tiles[idx] == E) {
        return;
    }
    removeCluster(board, idx);
    dropDown(board);
}

void printBoard(struct board* board) {
    printf("\n");
    for (int i = 0; i < COLUMN_SIZE; i++) {
        for (int j = 0; j < ROW_SIZE; j++) {
            int idx = i*ROW_SIZE+j;
            int color = board->tiles[idx];
            switch (color) 
            {
            case R:
                BG_RED();
                break;
            case G:
                BG_GREEN();
                break;
            case B:
                BG_BLUE();
                break;
            case O:
                BG_ORANGE();
                break;
            
            default:
                BG_WHITE();
                break;
            }
            char colorChar = color_to_char[board->tiles[idx]];
            printf("%c\t", colorChar); 
        }
        printf("\n");
    }
}

void printClusterBoard(struct board* board) {
    printf("\n");
     for (int i = 0; i < COLUMN_SIZE; i++) {
        for (int j = 0; j < ROW_SIZE; j++) {
            printf("%d\t", board->clusters[i*ROW_SIZE+j]); 
        }
        printf("\n");
    }
}

void resetBoard(int8_t arr[static BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        arr[i] = 0;
    }
}



