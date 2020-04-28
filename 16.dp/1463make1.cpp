//
//  1463make1.cpp
//  Practice
//
//  Created by W on 2020. 4. 26..
//  Copyright © 2020년 W. All rights reserved.
//

#include <stdio.h>

int get_count(int n);

int input;
int memo[1000001] = { 0 };

int main(void)
{
    scanf("%d", &input);
    
    printf("%d", get_count(input));
    return 0;
}

int get_count(int n){
    int CNT3 = 1000000, CNT2 = 1000000, CNT1= 1000000, min;
    //printf(" %d\n", n);
    if ( n == 1 )
        return 0;
    
    if ( memo[n] != 0 ){
        return memo[n];
    }

        if ( n%3 == 0){
            CNT3 = get_count(n/3);
            CNT3++;
        }
        if ( n%2 == 0){
            CNT2 = get_count(n/2);
            CNT2++;
        }
        {
            CNT1 = get_count(n-1);
            CNT1++;
        }
    min = CNT3 < CNT2 ? CNT3 : CNT2 ;
    min = min < CNT1 ? min : CNT1 ;
    memo[n] = min;
    return min;
}

