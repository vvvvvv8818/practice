#include <stdio.h>

int main(void)
{
	int input;
	int N;
	int i;
	int fibo[40][2] = { 0 };
	fibo[0][0] = 1;
	fibo[0][1] = 0;
	fibo[1][0] = 0;
	fibo[1][1] = 1;

	scanf("%d", &input);
	for (; input > 0; input--)
	{
		scanf("%d", &N);

		for (i = 2; i <= N; i++) {
			fibo[i][0] = fibo[i - 1][0] + fibo[i - 2][0];
			fibo[i][1] = fibo[i - 1][1] + fibo[i - 2][1];
		}

		printf("%d %d\n", fibo[N][0], fibo[N][1]);
	}
	return 0;
}
