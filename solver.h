#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int search(struct board* board, int depth);
int staticEvaluation(struct board* board);
int findBestMove(struct board* board, int depth);
int countPieces(int8_t tiles[]);