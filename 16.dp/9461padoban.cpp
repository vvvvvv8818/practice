//
//  9461padoban.cpp
//  Practice
//
//  Created by W on 2020. 4. 20..
//  Copyright © 2020년 W. All rights reserved.
//

#include <stdio.h>

long long l[101] = {0};

int main(void)
{
    int T, input;
    int i, n;
    int index = 8;
    l[1] = 1; l[2] = 1; l[3] = 1; l[4] = 2; l[5] = 2;
    l[6] = 3; l[7] = 4; l[8] = 5;
    
    scanf("%d", &T);
    for (i = 0; i < T; i++){
        scanf("%d", &input);
        
        if (l[input] != 0){
            printf("%lld\n", l[input]);
            continue;
        }
        for (n = index + 1; n <= input; n++){
            l[n] = l[n-5] + l[n-1];
            index++;
        }
        
        printf("%lld\n", l[input]);
    }
    return 0;
}

