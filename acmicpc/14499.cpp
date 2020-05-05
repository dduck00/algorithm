#include <vector>
#include <stdio.h>

#define EAST 1
#define WEST 2
#define NORTH 3
#define SOUTH 4
using namespace std;

int DICE[7] = { 0 };

int pan[20][20] = { 0 };
int orders[1000] = { 0 };
int N, M, r, c, K;


void init() {
	scanf("%d %d %d %d %d", &N, &M, &r, &c, &K);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &pan[i][j]);
		}
	}

	for (int i = 0; i < K; i++) {
		scanf("%d", &orders[i]);
	}
}

void moveEast() {
	int tmp = DICE[1];
	DICE[1] = DICE[4];
	DICE[4] = DICE[6];
	DICE[6] = DICE[3];
	DICE[3] = tmp;
}

void moveWest() {
	int tmp = DICE[1];
	DICE[1] = DICE[3];
	DICE[3] = DICE[6];
	DICE[6] = DICE[4];
	DICE[4] = tmp;
}

void moveNorth() {
	int tmp = DICE[2];
	DICE[2] = DICE[1];
	DICE[1] = DICE[5];
	DICE[5] = DICE[6];
	DICE[6] = tmp;
}

void moveSouth() {
	int tmp = DICE[1];
	DICE[1] = DICE[2];
	DICE[2] = DICE[6];
	DICE[6] = DICE[5];
	DICE[5] = tmp;
}

void move(int tr, int tc, int order) {
	if (tr < 0 || tc < 0 || tr >= N || tc >= M)
		return;

	switch (order) {
	case EAST:
		moveEast();
		break;
	case NORTH:
		moveNorth();
		break;
	case SOUTH:
		moveSouth();
		break;
	case WEST:
		moveWest();
		break;
	}

	printf("%d\n", DICE[1]);
	if (pan[tr][tc] == 0) {
		pan[tr][tc] = DICE[6];
	}
	else {
		DICE[6] = pan[tr][tc];
		pan[tr][tc] = 0;
	}

	r = tr;
	c = tc;

}

void solution() {
	for (int i = 0; i < K; i++) {
		int tr = r;
		int tc = c;
		switch (orders[i]) {
		case EAST:
			tc++;
			break;
		case NORTH:
			tr--;
			break;
		case SOUTH:
			tr++;
			break;
		case WEST:
			tc--;
			break;
		}
		move(tr, tc, orders[i]);
	}
}

int main(void) {
	init();
	solution();
}
