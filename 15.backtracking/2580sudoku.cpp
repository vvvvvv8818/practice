//
//  2580sudokoo.cpp
//  Practice
//
//  Created by W on 2020. 3. 11..
//  Copyright © 2020년 W. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

void check();
void dfs(int index);

int board[9][9] = {0};
bool sub_board[3][3][10] = {0};
bool row[9][10] = {0};
bool col[9][10] = {0};
vector < pair <int,int> > blank;
bool FLAG = false;

int main(void)
{
    int p, i, j;

    for (i = 0; i < 9; i++){
        for (j = 0; j < 9; j++){
                scanf("%d", &board[i][j]);
                if ( board[i][j] == 0 )
                    blank.push_back(make_pair(i, j));
        }
    }

    check();
    
    dfs(0);
    
    //printf("===============\n");
    for (i = 0; i < 9; i++){
        for (j = 0; j < 9; j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

void check(){
    int i, j;
    int val;
    
    for (i = 0; i < 9; i++){
        for (j = 0; j < 9; j++){
            val = board[i][j];
            row[i][val] = true;
            col[j][val] = true;
            sub_board[i/3][j/3][val] = true;
        }
    }
}

void dfs(int index){
    int n, i, j;
    
    i = blank[index].first;
    j = blank[index].second;
    
    for (n = 1; n <= 9; n++){
        if ( row[i][n] == false &&
            col[j][n] == false &&
            sub_board[i/3][j/3][n] == false ){
            board[i][j] = n;
            row[i][n] = true;
            col[j][n] = true;
            sub_board[i/3][j/3][n] = true;
            if ( index == blank.size() - 1 ){
                FLAG = true;
                return ;
            }
            dfs(index+1);
            if ( FLAG ) return ;
            board[i][j] = 0;
            row[i][n] = false;
            col[j][n] = false;
            sub_board[i/3][j/3][n] = false;
        }
    }
}

/*
 for (i = 0; i < 9; i++){
 for (j = 0; j < 9; j++){
 printf("%d ", board[i][j]);
 }
 printf("\n");
 }
 */

