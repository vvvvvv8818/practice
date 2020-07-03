//
//  12865normalKnapsack.cpp
//  Practice
//
//  Created by W on 2020. 5. 31..
//  Copyright © 2020년 W. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int stuff[101][2] = {0};
int bag[101][100001] = {0};

int main(void)
{
    int N, K;
    
    cin >> N;
    cin >> K;
    
    for (int i=1; i <= N; i++){
        cin >> stuff[i][0] >> stuff[i][1];
    }
    
    for (int i=1; i <= N; i++){
        for (int j=1; j <= K; j++){
            
            if (j - stuff[i][0] >= 0){
                bag[i][j] = max( bag[i-1][j], // 같은 무게를 담은 다른 경우
                                bag[i-1][j-stuff[i][0]] + stuff[i][1]);
            }
            else{
                bag[i][j] = bag[i-1][j];
            }
            cout << bag[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << bag[N][K];
    return 0;
}

