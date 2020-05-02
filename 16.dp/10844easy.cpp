#include <iostream>

using namespace std;

int main()
{
  int N;
  int len, i;
  long long sum;
  long long arr[101][10] = {0};

  cin >> N;

  for (i = 1; i <= 9; i++){
    arr[1][i] = 1;
  }

  for (len = 2; len <= N; len++){
    //cout << "len : " << N << endl;
    arr[len][0] = arr[len-1][1];
    //cout << arr[len][0] << " ";
    for (i = 1; i <= 8; i++){
      arr[len][i] = arr[len-1][i-1] + arr[len-1][i+1];
      arr[len][i] %= 1000000000;
      //cout << arr[len][i] << " ";
    }
    arr[len][9] = arr[len-1][8];
    //cout << arr[len][9] << endl;
  }

  sum = 0;
  for (i = 0; i <= 9; i++){
    sum += arr[N][i];
    sum %= 1000000000;
  }
  cout << sum;

  return 0;
}
