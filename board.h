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

static char color_to_char[] = {
    [E] = 'E',
    [B] = 'B',
    [O] = 'O',
    [G] = 'G',
    [R] = 'R'
};

void markCluster(int clusterBoard[], int board[], int i, int clusterCount);
int findClusters(int clusterBoard[], int board[], int clusterPositions[]);
int findNumberOfClusters(int clusterBoard[], int board[]);
void removeCluster(int board[], int i);
void dropDown(int board[]);
void makeMove(int board[], int idx);
void printBoard(int board[]);
void printClusterBoard(int clusterBoard[]);
void resetBoard(int clusterBoard[]);