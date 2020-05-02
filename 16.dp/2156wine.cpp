#include <iostream>
using namespace std;

int max(int a, int b, int c);

int main(void)
{
  int N;
  int wine[10000] = {0};
  int dp[10000] = {0};
  int i;

  cin >> N;

  for (i = 0; i < N; i++){
    cin >> wine[i];
  }

  dp[0] = wine[0];
  dp[1] = wine[0] + wine[1];
  dp[2] = max(dp[1], dp[0] + wine[2], wine[1] + wine[2]);

  for (i = 3; i < N; i++){
    dp[i] = max(dp[i-1], dp[i-2] + wine[i], dp[i-3] + wine[i-1] + wine[i]);
  }

  cout << dp[N-1];

  return 0;
}

int max(int a, int b, int c){
  return a > b ? (a > c ? a : c) : (b > c ? b : c);
}
