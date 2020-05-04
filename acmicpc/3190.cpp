#include <queue>
#include <stdio.h>
#include <vector>
#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3
#define APPLE 9
#define SNAKE 8

using namespace std;

int N, K;
deque<pair<int, int> > snake;
queue<pair<int, char>> order;
int pan[101][101] = { 0 };
int toward;
int time;

void init() {
	scanf("%d%d", &N, &K);

	for (int i = 0; i < K; i++) {
		int t1, t2;
		scanf("%d%d", &t1, &t2);
		pan[t1][t2] = APPLE;
	}
	scanf("%d", &K);

	for (int i = 0; i < K; i++) {
		int t1;
		char t2;
		scanf("%d %c", &t1, &t2);
		order.push({ t1, t2 });
	}
}

void checkTime() {
	if (order.empty())
		return;
	if (time == order.front().first) {
		if (order.front().second == 'D') {
			toward++;
		}
		else {
			toward--;
		}
		if (toward == -1)
			toward = 3;
		if (toward == 4)
			toward = 0;
		order.pop();
	}
}

void doMove(pair<int, int> position) {
	snake.push_front(position);
	if (pan[position.first][position.second] != APPLE) {
		pan[snake.back().first][snake.back().second] = 0;
		snake.pop_back();
	}
	pan[position.first][position.second] = SNAKE;
}

pair<int, int> calPosition() {
	auto head = snake.front();
	switch (toward) {
	case UP:
		head.first--;
		break;
	case DOWN:
		head.first++;
		break;
	case LEFT:
		head.second--;
		break;
	case RIGHT:
		head.second++;
		break;
	}
	return head;
}

bool judgeMove(pair<int, int> to) {
	int i = to.first;
	if (i < 1 || i >N)
		return false;
	int j = to.second;
	if (j < 1 || j >N)
		return false;

	if (pan[i][j] == SNAKE)
		return false;

	return true;
}



int main(void) {
	init();
	snake.push_back({ 1, 1 });
	pan[1][1] = SNAKE;
	while (true) {
		time++;
		auto next = calPosition();
		if (judgeMove(next) == false) {
			printf("%d", time);
			return 0;
		}
		doMove(next);
		checkTime();
	}
}
