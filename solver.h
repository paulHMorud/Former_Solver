#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int search(int board[], int clusterBoard[], int clusterPositions[], int depth);
int staticEvaluation(int board[], int clusterBoard[], int clusterPositions[]);
int findBestMove(int board[], int clusterBoard[], int depth, int clusterPositions[]);