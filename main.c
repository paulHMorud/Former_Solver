#include "stdlib.h"
#include "stdio.h"
#include "board.h"

#define O 1
#define G 2
#define R 3
#define B 4

int board[63] = {O,R,G,B,O,R,B,
                B,B,B,R,O,R,G,
                R,G,R,O,O,B,O,
                G,G,O,O,R,R,B,
                R,G,R,R,B,B,O,
                O,G,O,R,O,O,B,
                O,O,B,R,B,B,G,
                B,B,B,R,G,B,O,
                R,B,G,G,R,O,R};


int main(int argc, char const *argv[])
{
    for(int i = 0; i < 63; i++) {
        printf("%d\n",board[i]);
    }
    
    return 0;
}

