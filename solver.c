#include "board.h"
#include "solver.h"

int search(struct board* board, int depth) {
    if (depth == 0) {
        return staticEvaluation(board);
    }
    if (countPieces(board->tiles) == 0) {
        return (-depth);
    }
    
    int numberOfClusters = findClusters(board);
    int eval = 1000000;
    int min_eval = 1000000;
    struct board copyOfBoard;
    for (int i = 1; i <= numberOfClusters; i++) {
        memcpy(&copyOfBoard, board, sizeof(struct board));
        makeMove(&copyOfBoard, copyOfBoard.clusterPositions[i]);
        eval = search(&copyOfBoard, depth-1);
        if (eval < min_eval) {
            min_eval = eval;
        }
    }
    
    return min_eval;
}


int countPieces(int8_t tiles[]) {
    int num_pieces = 0;
    for (int i=0; i<BOARD_SIZE; i++) {
        if (tiles[i] != E) {
            num_pieces += 1;
        }
    }
    return num_pieces;
}
int staticEvaluation(struct board* board) {
    int n_pieces = countPieces(board->tiles);
    int n_clusters = findNumberOfClusters(board);
    int w1 = 20;
    int w2 = 100-w1;
    int eval = n_pieces*w1 + n_clusters*w2;
    return eval; 
}
int findBestMove(struct board* board, int depth) {
    int numberOfClusters = findClusters(board);
    int valueOfMoves[BOARD_SIZE+1];
    struct board copyOfBoard;
    for (int i = 0; i < numberOfClusters; i++) {
        memcpy(&copyOfBoard, board, sizeof(struct board));
        makeMove(&copyOfBoard, board->clusterPositions[i+1]);
        valueOfMoves[i+1] = search(&copyOfBoard, depth-1);
        printf("%d ", valueOfMoves[i+1]);
    }
    printf("\n");
    int bestMove = 0;
    int bestEval = 1000000;
    int eval = 1000000;
    for (int i = 0; i < numberOfClusters; i++) {
        eval = valueOfMoves[i+1];
        if (eval < bestEval) {
            bestEval = eval;
            bestMove = board->clusterPositions[i+1];
        }
    }
    return bestMove;
}