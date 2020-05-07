#include <vector>
#include<algorithm>
#include<stdio.h>
using namespace std;

int N;
int time[15];
int pay[15];
int ret = -1;

void init() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &time[i], &pay[i]);
	}
}

void calc(int nowDay, int money) {
	if (ret < money) {
		ret = money;
	}

	for (int i = nowDay; i < N; i++) {
		if (i + time[i] <= N) {
			calc(i + time[i], money+pay[i]);
		}
	}
}

int main(void) {
	init();
	calc(0, 0);
	printf("%d", ret);
}
