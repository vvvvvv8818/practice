
#include <iostream>
using namespace std;

int parent[201] = {0};


int find(int x){
    int p;
    if (x == parent[x])
        return x;
    else{
        p = find(parent[x]);
        parent[x] = p;
        return p;
    }
}

void union_f(int a, int b){
    int pa = find(a);
    int pb = find(b);
    
    if (pa < pb) parent[pb] = pa;
    else    parent[pa] = pb;
}


int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    int input;
    int p;
    string ANS;
    
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    
    // 입력 받으면서 union
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> input;
            if (input == 1){
                union_f(i, j);
            }
        }
    }
    // 주어진 도시들 find
    p = 0;
    ANS="YES";
    for (int i = 1; i <= m; i++){
        cin >> input;
        if (p == 0)
            p = find(input);
        else if ( p != find(input) ){
            ANS = "NO";
            break;
        }
    }
    cout << ANS;
    return 0;
}

