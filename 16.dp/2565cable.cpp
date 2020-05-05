
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    int N;
    vector< pair< int, int > > pole;
    int lis[500];
    int i, j, a, b;
    int MAX;
    
    cin >> N;
    for (i = 0; i < N; i++){
        cin >> a >> b;
        pole.push_back(make_pair(a,b));
        lis[i] = 1;
    }
    sort(pole.begin(), pole.end());
    /*
    for ( i = 0; i < N; i++)
        cout << pole[i].first << " " << pole[i].second << endl;
    */
    for (i = N-2; 0 <= i; i--){
        for (j = i+1; j < N; j++){
            if (pole[i].second < pole[j].second)
                if (lis[i] <= lis[j])
                    lis[i] = lis[j] + 1;
        }
    }
    /*
    for (i = 0; i < N ; i++){
        cout << lis[i] << " ";
    }
    cout << endl;
    */
    MAX = 0;
    for (i = 0; i < N; i++){
        MAX = MAX < lis[i] ? lis[i] : MAX;
    }
    cout << N-MAX;
    return 0;
}

