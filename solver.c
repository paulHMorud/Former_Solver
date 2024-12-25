#include "board.h"
#include "solver.h"

int search(int board[], int clusterBoard[], int clusterPositions[], int depth) {
    if (depth == 0) {
        return staticEvaluation(board, clusterBoard, clusterPositions);
    }
    
    int numberOfClusters = findClusters(clusterBoard, board, clusterPositions);
    volatile int eval = 100;
    volatile int min_eval = 100;
    int copyOfBoard[BOARD_SIZE];
    // int copyNumberOfClusters = 0;
    for (int i = 1; i <= numberOfClusters; i++) {
        memcpy(copyOfBoard, board, BOARD_SIZE * sizeof(int));
        makeMove(copyOfBoard, clusterPositions[i]);
        // copyNumberOfClusters = findClusters(copyOfBoard, board, clusterPositions);
        eval = search(copyOfBoard, clusterBoard, clusterPositions, depth-1);
        if (eval<min_eval) {
            min_eval = eval;
            }
    }
    
    return min_eval;
    
    
}
int staticEvaluation(int board[], int clusterBoard[], int clusterPositions[]) {
    return findClusters(clusterBoard, board, clusterPositions);
}
int findBestMove(int board[], int clusterBoard[], int depth, int clusterPositions[]) {
    volatile int numberOfClusters = findClusters(clusterBoard, board, clusterPositions);
    int valueOfMoves[numberOfClusters];
    int copyOfBoard[BOARD_SIZE];
    for (int i = 1; i <= numberOfClusters; i++) {
        memcpy(copyOfBoard, board, BOARD_SIZE * sizeof(int));
        makeMove(copyOfBoard, clusterPositions[i]);
        valueOfMoves[i] = search(copyOfBoard, clusterBoard, clusterPositions, depth-1);
    }
    volatile int bestMove = 0;
    volatile int bestEval = 100;
    volatile int eval = 50;
    for (int i = 1; i <= numberOfClusters; i++) {
        eval = valueOfMoves[i];
        if (eval < bestEval) {
            bestEval = eval;
            bestMove = clusterPositions[i];
        }
    }
    return bestMove;
}