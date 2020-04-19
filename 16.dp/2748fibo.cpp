#include <iostream>
using namespace std;

int main(void)
{
    int N, i;
    unsigned long fibo[90] = {0};
    
    fibo[0] = 0;
    fibo[1] = 1;
    
    cin >> N;
    
    for (i = 2; i <= N; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    
    cout << fibo[N];
    return 0;
}
