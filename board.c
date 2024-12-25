#include <stdlib.h>
#include <stdio.h>
#include "board.h"
#include "print_colors.h"


void markCluster(int clusterBoard[], int board[], int i, int clusterCount) {
    clusterBoard[i] = clusterCount;
    if (i % ROW_SIZE != 0 && board[i] == board[i-1] && clusterBoard[i-1] == 0) { //left
        markCluster(clusterBoard, board, i-1, clusterCount);
    }
    if (i % ROW_SIZE != ROW_SIZE-1 && board[i] == board[i+1] && clusterBoard[i+1] == 0) { //right
        markCluster(clusterBoard, board, i+1, clusterCount);
    }
    if (i / COLUMN_SIZE != 0 && board[i] == board[i+UP] && clusterBoard[i+UP] == 0) { //up
        markCluster(clusterBoard, board, i+UP, clusterCount);
    }
    if (i / COLUMN_SIZE != COLUMN_SIZE-1 && board[i] == board[i+DOWN] && clusterBoard[i+DOWN] == 0) { //down
        markCluster(clusterBoard, board, i+DOWN, clusterCount);
    }

}
int findClusters(int clusterBoard[], int board[], int clusterPositions[]) {
    resetBoard(clusterBoard);
    resetBoard(clusterPositions);
    int clusterCount = 1;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if ((clusterBoard[i] != 0) || (board[i] == E)) {
            continue;
        }
        else {
            markCluster(clusterBoard, board, i, clusterCount);
            clusterPositions[clusterCount] = i;
            clusterCount++;
        }
    }
    return clusterCount;
}

void removeCluster(int board[], int i) {
    int color = board[i];
    board[i] = 0;
    if (i % ROW_SIZE != 0 && color == board[i-1] && board[i-1] != 0) { //left
        removeCluster(board, i-1);
    }
    if (i % ROW_SIZE != ROW_SIZE-1 && color == board[i+1] && board[i+1] != 0) { //right
        removeCluster(board, i+1);
    }
    if (i / COLUMN_SIZE != 0 && color == board[i+UP] && board[i+UP] != 0) { //up
        removeCluster(board, i+UP);
    }
    if (i / COLUMN_SIZE != COLUMN_SIZE-1 && color == board[i+DOWN] && board[i+DOWN] != 0) { //down
        removeCluster(board, i+DOWN);
    }
}

void dropDown(int board[]) {
    for (int col = 0; col < ROW_SIZE; col++) {
        int offset = 0;
        for (int row = COLUMN_SIZE-1; row >= 0; row--) {
            int idx = row*ROW_SIZE+col;
            if (board[idx] == E) {
                offset++;
            }
            else if (offset != 0) {
                board[idx+offset*ROW_SIZE]=board[idx];
                board[idx] = E;
            }
        }
    }
}

void makeMove(int board[], int idx) {
    removeCluster(board, idx);
    dropDown(board);
}

void printBoard(int board[]) {
    printf("\n");
    for (int i = 0; i < COLUMN_SIZE; i++) {
        for (int j = 0; j < ROW_SIZE; j++) {
            int idx = i*ROW_SIZE+j;
            int color = board[idx];
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
            char colorChar = color_to_char[board[idx]];
            printf("%c\t", colorChar); 
        }
        printf("\n");
    }
}

void printClusterBoard(int clusterBoard[]) {
    printf("\n");
     for (int i = 0; i < COLUMN_SIZE; i++) {
        for (int j = 0; j < ROW_SIZE; j++) {
            printf("%d\t", clusterBoard[i*ROW_SIZE+j]); 
        }
        printf("\n");
    }
}

void resetBoard(int clusterBoard[]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        clusterBoard[i] = 0;
    }
}



