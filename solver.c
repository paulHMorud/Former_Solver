#include "board.h"
#include "solver.h"

int search(int board[], int clusterBoard[], int clusterPositions[], int depth) {
    if (depth == 0) {
        return staticEvaluation(board, clusterBoard, clusterPositions);
    }
    if (countPieces(board) == 0) {
        return (-depth - 10);
    }
    
    int numberOfClusters = findClusters(clusterBoard, board, clusterPositions);
    int eval = 1000000;
    int min_eval = 1000000;
    int copyOfBoard[BOARD_SIZE];
    int copyOfClusterBoard[BOARD_SIZE];
    int copyOfClusterPositions[BOARD_SIZE];
    // int copyNumberOfClusters = 0;
    for (int i = 1; i <= numberOfClusters; i++) {
        memcpy(copyOfBoard, board, BOARD_SIZE * sizeof(int));
        memcpy(copyOfClusterBoard, clusterBoard, BOARD_SIZE * sizeof(int));
        memcpy(copyOfClusterPositions, clusterPositions, BOARD_SIZE * sizeof(int));
        makeMove(copyOfBoard, clusterPositions[i]);
        // copyNumberOfClusters = findClusters(copyOfBoard, board, clusterPositions);
        eval = search(copyOfBoard, copyOfClusterBoard, copyOfClusterPositions, depth-1);
        if (eval < min_eval) {
            min_eval = eval;
            }
    }
    
    return min_eval;
}


int countPieces(int board[]) {
    int num_pieces = 0;
    for (int i=0; i<BOARD_SIZE; i++) {
        if (board[i] != E) {
            num_pieces += 1;
        }
    }
    return num_pieces;
}
int staticEvaluation(int board[], int clusterBoard[], int clusterPositions[]) {
    int n_pieces = countPieces(board);
    int n_clusters = findNumberOfClusters(clusterBoard, board);
    int w1 = 20;
    int w2 = 100-w1;
    int eval = n_pieces*w1 + n_clusters*w2;
    // int eval = findClusters(clusterBoard, board, clusterPositions);
    // if (eval < 10) {
    //     printBoard(board);
    // }
    // return eval;
    // if (countPieces(board) < 15) {
    //     printBoard(board); 
    // }
    return eval; 
}
int findBestMove(int board[], int clusterBoard[], int depth, int clusterPositions[]) {
    int numberOfClusters = findClusters(clusterBoard, board, clusterPositions);
    int valueOfMoves[BOARD_SIZE+1];
    int copyOfBoard[BOARD_SIZE];
    int copyOfClusterBoard[BOARD_SIZE];
    int copyOfClusterPositions[BOARD_SIZE];
    for (int i = 0; i < numberOfClusters; i++) {
        memcpy(copyOfBoard, board, BOARD_SIZE * sizeof(int));
        memcpy(copyOfClusterBoard, clusterBoard, BOARD_SIZE * sizeof(int));
        memcpy(copyOfClusterPositions, clusterPositions, BOARD_SIZE * sizeof(int));
        makeMove(copyOfBoard, clusterPositions[i+1]);
        valueOfMoves[i+1] = search(copyOfBoard, copyOfClusterBoard, copyOfClusterPositions, depth-1);
        printf("%d ", valueOfMoves[i+1]);
    }
    printf("\n");
    int bestMove = 0;
    int bestEval = 1000000;
    int eval = 1000000;
    for (int i = 0; i < numberOfClusters; i++) {
        eval = valueOfMoves[i+1];
        // printf("\tThe eval is: %d", valueOfMoves[i+1]);
        if (eval < bestEval) {
            bestEval = eval;
            bestMove = clusterPositions[i+1];
        }
        // printf("\tEvaluation: %d", eval);
        // printf("\nClusterpositions: %d", clusterPositions[i+1]);
    }
    // printf("\tNumber of clusters: %d ", numberOfClusters);
    return bestMove;
}