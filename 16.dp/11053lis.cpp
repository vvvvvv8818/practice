#include <iostream>
using namespace std;

int main(void)
{
    int N;
    int input[1000], len[1000];
    int i, j;
    int MAX;
    
    for (i = 0; i < 1000; i++){
        input[i] = 0;
        len[i] = 1;
    }
    
    cin >> N;
    for (i = 0; i < N; i++)
        cin >> input[i];
    
    for (i = 1; i < N; i++){
        for (j = i-1; 0 <= j; j--){
            if (input[j] < input[i])
                if (len[j] >= len[i])
                    len[i] = len[j] + 1;
        }
    }

    MAX = 0;
    for (i = 0; i < N; i++){
        MAX = MAX > len[i] ? MAX : len[i];
        //cout << len[i] << " ";
    }
    //cout << endl;
    cout << MAX;
    return 0;
}

