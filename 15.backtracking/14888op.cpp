//
//  14888op.cpp
//  Practice
//
//  Created by W on 2020. 3. 24..
//  Copyright © 2020년 W. All rights reserved.
//

#include <stdio.h>

using namespace std;

void dfs(int index, long long result);

int op[4] = { 0 };    // + - * /
int num[10] = { 0 };  // 2~11, 1~100
long long MAX = -1000000000;
long long MIN = 1000000000;
int N;

int main()
{
	int i;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}
	for (i = 0; i < 4; i++) {
		scanf("%d", &op[i]);
	}

	dfs(0, (long long)num[0]);
	printf("%lld\n", MAX);
	printf("%lld", MIN);
	return 0;
}

void dfs(int index, long long result) {
	long long tmp;

	if (index == N - 1) {
		// end
		MIN = result < MIN ? result : MIN;
		MAX = result > MAX ? result : MAX;
		return;
	}

	if (op[0] > 0) {
		op[0]--;
		dfs(index + 1, result + (long long)num[index + 1]);
		op[0]++;
	}
	if (op[1] > 0) {
		op[1]--;
		dfs(index + 1, result - (long long)num[index + 1]);
		op[1]++;
	}
	if (op[2] > 0) {
		op[2]--;
		dfs(index + 1, result * (long long)num[index + 1]);
		op[2]++;
	}
	if (op[3] > 0) {
		op[3]--;
		tmp = (-1) * result;
		tmp = tmp / (long long)num[index + 1];
		tmp = (-1) * tmp;
		dfs(index + 1, tmp);
		op[3]++;
	}

}

