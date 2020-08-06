#include <iostream>
using namespace std;

int parent[1000001] = {0};


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
    int op, a, b;
    string output;
    
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
        parent[i] = i;
    
    for (int i = 0; i < m; i++){
        cin >> op >> a >> b;
        if ( op == 0 ){
            union_f(a, b);
        }
        else{
            // find 끼리 비교
            a = find(a);
            b = find(b);
            output = a == b ? "YES" : "NO";
            cout << output << "\n";
        }
    }
    
    return 0;
}

