//
//  1912serial.cpp
//  Practice
//
//  Created by W on 2020. 5. 19..
//  Copyright © 2020년 W. All rights reserved.
//

#include <iostream>
using namespace std;

int max(int a, int b){
    return a > b ? a : b;
}

int main(void)
{
    int N;
    int input[100000] = {0};
    int MAX, cur;
    
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> input[i];
    }
    
    cur = input[0];
    MAX = input[0];
    for (int i = 1; i < N; i++){
        cur = max(cur + input[i], input[i]);    // 여태 더해온 것과 이을거냐 새로 시작할거냐
        MAX = max(MAX, cur);    // 지금까지의 MAX와 현재 더해놓은(현재 숫자를이었든 새로 시작했든) 합 중 큰 값
    }
    cout << MAX;
    return 0;
}

