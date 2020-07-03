#include <iostream>
#include <algorithm>
using namespace std;

int cards[500000];
int comp[500000];
bool ANS[500000];

int main(void)
{
    int N,M;
    int first, last, bina;
    
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> cards[i];
    cin >> M;
    for (int i = 0; i < M; i++)
        cin >> comp[i];
    
    sort(cards, cards+N);
    //sort(comp, comp+M);
    
    for (int i = 0; i < M; i++){
        first = 0;
        last = N-1;
        
        while (first <= last){
            bina = first + (last-first)/2;
            if (cards[bina] == comp[i]) break;
            else if(cards[bina] < comp[i]){
                first = bina+1;
            }
            else{
                last = bina-1;
            }
        }
        
        if (first > last)
            ANS[i] = 0;
        else ANS[i] = 1;
    }
    
    for (int i = 0; i < M; i++)
        cout << ANS[i] << " ";
    return 0;
}


