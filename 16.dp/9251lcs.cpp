#include <iostream>
using namespace std;

int max( int a, int b ){
    return a > b ? a : b;
}

int main(void)
{
    int lcs[1001][1001] = {0};
    string str1, str2;
    int len1, len2;
    int i, j;
    int m;

    
    cin >> str1;
    cin >> str2;
    len1 = (int) str1.size();
    len2 = (int) str2.size();
    cout << str1 << "-" << endl;
    cout << str2 << "-" << endl;
    
    for (i = 1; i <= len1; i++){
        for (j = 1; j <= len2; j++){
            m = max( lcs[i][j-1], lcs[i-1][j] );
            if ( str1[i-1] == str2[j-1]  && m < i && m < j){
                m = lcs[i-1][j-1] + 1; // 현재 비교하는 글자가 같으면 +1 // 이전과 중복되는 글자 나오면 중복해서 더해질 수 있음
            }
            lcs[i][j] = m;
            cout << "[" << i << "][" << j << "]" << lcs[i][j] << endl;
        }
    }
    
    cout << lcs[len1][len2];
    
    return 0;
}
