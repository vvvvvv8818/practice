

#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

bool min_compare(int a, int b){ return a > b; };

int main(void){
    priority_queue < int, vector <int>, function< bool(int, int) > > minpq(min_compare);
    priority_queue < int > maxpq;
    int N, i, input;
    int diff;
    
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> N;
    maxpq.push(-99999);
    minpq.push(99999);
    
    for (i = 0; i < N; i++){
        cin >> input;
        diff = (int)(maxpq.size() - minpq.size());
        if ( diff <= 0 ){
            maxpq.push(input);
        }
        else{
            minpq.push(input);
        }
        
        if ( maxpq.top() > minpq.top() ){
            input = maxpq.top();
            maxpq.pop();
            maxpq.push(minpq.top());
            minpq.pop();
            minpq.push(input);
        }
        
        diff = (int)(maxpq.size() - minpq.size());
        if (diff >= 0)
            cout << maxpq.top() << '\n';
        else cout << minpq.top() << '\n';
        
    }
    return 0;
}

