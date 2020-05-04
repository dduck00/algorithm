#include <stdio.h>

int N;
int room[1000000];
int b, c;


int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &room[i]);
	}
	scanf("%d", &b);
	scanf("%d", &c);

	long long int ret = N;

	for (int i = 0; i < N; i++) {
		room[i] -= b;
		if (room[i] <= 0)
			continue;
		ret += ((long long int)(room[i] / c) + (room[i] % c == 0 ? 0 : 1));

	}
	printf("%lld", ret);
}
