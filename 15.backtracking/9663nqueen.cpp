//
//  9663nqueen.cpp

#include <stdio.h>
#include <stdlib.h>

using namespace std;

int N = 0;
int ANS = 0;
int board[15];

void find(int k);
bool chk(int x, int y);

int main(void)
{
    int k = 0;

    for (k = 0; k < 15; k++)
        board[k] = -1;
    
    scanf("%d", &N);

    find(0);

    
    printf("%d\n", ANS);
    return 0;
}

void find(int i){
    int j;
/*
    printf("i:%d [ ", i);
    for (j = 0 ; j < N; j++)
        printf("%d ", board[j]);
    printf("]\n");
    */
    for (j = 0; j < N; j++){    // i행의 0~N-1열
        if ( chk(i, j) ){
            if (i == N-1){
                ANS++;
                //printf("%d (%d, %d)\n", ANS, i, j);
            }
            else{
                board[i] = j;
                find(i+1);
                board[i] = -1;
            }
        }
        else
            continue;
    }
}

// (x, y)에 놓을 수 있는지 board보면서 판단
bool chk(int x, int y){
    int k;
    
    for (k = 0; k < x; k++){ // k : x 앞까지의 행 번호
        if (board[k] == y)  // 열
            return false;
        if (x+y == k+board[k])  // 우상-좌하 대각선
            return false;
        if (x-y == k-board[k])    // 좌상-우하 대각선
            return false;
    }
    return true;
}


