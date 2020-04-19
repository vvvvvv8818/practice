#include <stdio.h>

int cases[1000001] = { 0 };

int oprnd = 15746;
int main(void)
{
	int N;	// N <= 1000 000
	int i;

	cases[0] = 0;
	cases[1] = 1;
	cases[2] = 2;

	scanf("%d", &N);

	for (i = 3; i <= N; i++){
		cases[i] = (cases[i - 1] + cases[i - 2]) % oprnd;
	}

	printf("%d", cases[N]);
	return 0;
}

