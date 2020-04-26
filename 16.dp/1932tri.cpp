//
//  1932tri.cpp
//  Practice
//
//  Created by W on 2020. 4. 22..
//  Copyright © 2020년 W. All rights reserved.
//

#include <stdio.h>

int N;  // 1<=N<=500
int tri[500][500] = {0};
int score[500][500] = {0};

int main(void)
{
    int i, line;
    char tmp;
    int MAX;
    
    scanf("%d", &N);
    for (line = 0; line < N; line++){
        for (i = 0; i <= line; i++){
            scanf("%d", &tri[line][i]);
        }
        scanf("%c", &tmp);
    }
    /*
    for (line = 0; line < N; line++){
        for (i = 0; i <= line; i++){
            printf("%d", tri[line][i]);
        }
        printf("\n");
    }
    */
    score[0][0] = tri[0][0];
    for (line = 0; line < N - 1; line++){
        for (i = 0; i <= line; i++){
            MAX = score[line][i] + tri[line+1][i];
            score[line+1][i] = score[line+1][i] < MAX ? MAX : score[line+1][i];
            MAX = score[line][i] + tri[line+1][i+1];
            score[line+1][i+1] = score[line+1][i+1] < MAX ? MAX : score[line+1][i+1];
        }
    }
    /*
    for (line = 0; line < N; line++){
        for (i = 0; i <= line; i++){
            printf("%d ", score[line][i]);
        }
        printf("\n");
    }
*/
    
    for (i = 0; i < N; i++){
        MAX = MAX < score[N-1][i] ? score[N-1][i] : MAX ;
    }
    printf("%d", MAX);
    
    return 0;
}

