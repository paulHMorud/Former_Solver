#include "board.h"
#include "solver.h"

int search(int board[], int clusterBoard[], int clusterPositions[], int depth) {
    if (depth == 0) {
        return staticEvaluation(board, clusterBoard, clusterPositions);
    }
    
    int numberOfClusters = findClusters(clusterBoard, board, clusterPositions);
    int eval = 100;
    int min_eval = 100;
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
    int numberOfClusters = findClusters(clusterBoard, board, clusterPositions);
    int valueOfMoves[numberOfClusters];
    for (int i = 0; i < numberOfClusters; i++) {
        valueOfMoves[i] = search(board, clusterBoard, clusterPositions, depth);
    }
    int bestMove = 0;
    int bestEval = 100;
    int eval = 50;
    for (int i = 0; i < numberOfClusters; i++) {
        eval = valueOfMoves[i];
        printf("%d", eval);
        if (eval < bestEval) {
            bestEval = eval;
            bestMove = i;
        }
    }
    printf("Best evaluation is: %d", bestEval);
    return bestMove;
}