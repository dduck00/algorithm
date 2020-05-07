#include <stdio.h>
#include <vector>
#include <queue>
#define WALL 1
#define VIRUS 2
#define EMPTY 0

using namespace std;

int di[4] = { 1, 0, -1, 0 };
int dj[4] = { 0, 1, 0, -1 };

int PAN[8][8];

int N, M;

int ret = -1;

void init() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &PAN[i][j]);
		}
	}
}

void spread() {
	queue<pair<int, int> > qu;
	int COPY_PAN[8][8] = { 0 };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (PAN[i][j] == VIRUS) {
				qu.push({ i, j });
			}
			COPY_PAN[i][j] = PAN[i][j];
		}
	}

	while (qu.empty() == false) {
		auto front = qu.front();
		qu.pop();

		int i = front.first;
		int j = front.second;

		for (int idx = 0; idx < 4; idx++) {
			int ii = i + di[idx];
			int jj = j + dj[idx];
			if (ii < 0 || ii >= N || jj < 0 || jj >= M)
				continue;
			if (COPY_PAN[ii][jj] == EMPTY) {
				qu.push({ ii, jj});
				COPY_PAN[ii][jj] = VIRUS;
			}
		}
	}
	int temp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (COPY_PAN[i][j] == EMPTY) {
				temp++;
			}
		}
	}
	if (ret < temp)
		ret = temp;

}


void setWall(int idx, int cnt) {
	if (cnt == 3) {
		spread();
		return;
	}

	for (int pivot = idx; pivot < N * M; pivot++) {
		int i = pivot / M;
		int j = pivot % M;
		if (PAN[i][j] != EMPTY) {
			continue;
		}
		PAN[i][j] = WALL;
		setWall(pivot + 1, cnt + 1);
		PAN[i][j] = EMPTY;
	}

}

int main(void) {
	init();
	setWall(0, 0);
	printf("%d", ret);
}
