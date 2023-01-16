#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

#define DIML 50
#define DIMC 200


void init_board (bool board [DIML+1][DIMC+1] )
{
    int i, j;
    for (i = 0; i < DIML+1; i++)
    {
        for (j = 0; j < DIMC+1; j++)
        {
            if (rand()%6==1){
                board[i][j] = rand()%2;
            }
            else{board[i][j]=0;}
        }
    }
}

void print_board (bool board [DIML+1][DIMC+1] )
{
    int i, j;
    for (i = 1; i < DIML; i++)
    {
        for (j = 1; j < DIMC; j++)
        {
            if (board[i][j] == true)
            {
                printf ("■");
            }
            else
            {
                printf ("□");
            }
        }
        printf ("\n");
        
    }
}

void copyvi(bool tab1[DIML+1][DIMC+1],bool tab2[DIML+1][DIMC+1]){
    for (int x=0;x<DIML+1;x++){
        for (int y=0; y<DIMC+1 ; y++){
            tab1[x][y]=tab2[x][y];
        }
    }
}

int nb_alive(bool board [DIML+1][DIMC+1] , int x , int y ){
    int count = 0 ;
    for (int i=-1;i<2;i++){
        for (int j=-1; j<2 ; j++){
            if (board[x+i][y+j]==true)count++;
        }
    }
    return count;
}


void update_board (bool board [DIML+1][DIMC+1]){
    bool temp [DIML+1] [DIMC+1];
    for (int x = 1 ; x<=DIML;x++){
        for (int y = 1 ; y<DIMC ; y++){
            if (nb_alive(board,x,y)!=3)
            {
                temp[x][y]=false;
            }
            else{
                temp[x][y]=true;
            }
            
        }

    }
    copyvi(board,temp);
}

int main(void){
    srand(time(NULL));
    bool board [DIML+1] [DIMC+1];
    init_board(board);
    while (1)
    {
        print_board(board);
        usleep(50000);
        printf("\033[2J");
        update_board(board);
    }
    
}