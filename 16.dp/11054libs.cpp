
#include <iostream>
using namespace std;

int main(void)
{
    int N;
    int input[1000], inc[1000], dec[1000];
    int i, j;
    int MAX;
    int comp;
    
    for (i = 0; i < 1000; i++){
        input[i] = 0;
        inc[i] = 1;
        dec[i] = 1;
    }
    
    cin >> N;
    for (i = 0; i < N; i++)
        cin >> input[i];
    
    for (i = 1; i < N; i++){
        for (j = i-1; 0 <= j; j--){
            if (input[j] < input[i])
                if (inc[j] >= inc[i])
                    inc[i] = inc[j] + 1;
        }
    }
    
    for (i = N-2; 0 <= i; i--){
        for (j = i+1; j <= N-1; j++){
            if (input[i] > input[j])
                if (dec[i] <= dec[j])
                    dec[i] = dec[j] + 1;
        }
    }
    
    
  
    MAX = 0;
    for (i = 0; i < N; i++)
        MAX = MAX > inc[i] + dec[i] ? MAX : inc[i] + dec[i];
    cout << MAX-1;

    return 0;
}

