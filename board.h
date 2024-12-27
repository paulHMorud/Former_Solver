#include <stdint.h>

#define E 0
#define O 1
#define G 2
#define R 3
#define B 4

#define ROW_SIZE 7
#define COLUMN_SIZE 9
#define BOARD_SIZE (ROW_SIZE*COLUMN_SIZE)

#define DOWN ROW_SIZE
#define LEFT -1
#define RIGTH 1
#define UP -ROW_SIZE

struct board {
    int8_t  tiles[BOARD_SIZE];
    int8_t  clusters[BOARD_SIZE];
    int8_t clusterPositions[BOARD_SIZE];
};

static char color_to_char[] = {
    [E] = 'E',
    [B] = 'B',
    [O] = 'O',
    [G] = 'G',
    [R] = 'R'
};

void markCluster(struct board* board, int i, int clusterCount);

int findClusters(struct board* board);

int findNumberOfClusters(struct board* board);

void removeCluster(struct board* board, int i);

void dropDown(struct board* board);

void makeMove(struct board* board, int idx);

void printBoard(struct board* board);

void printClusterBoard(struct board* board);

void resetBoard(int8_t arr[static BOARD_SIZE]);