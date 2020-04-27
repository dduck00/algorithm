#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

queue<pair<int, pair<pair<int, int>, pair<int, int> > > > qu;
vector<pair<pair<int, int>, pair<int, int>>> vec;
char pan[13][14];
int N, M;

void init() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%s", &pan[i]);
	}
	pair<int, pair<pair<int, int>, pair<int, int>>>  data = { 0, {} };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			switch (pan[i][j]) {
			case 'R':
				data.second.first = { i, j };
				pan[i][j] = '.';
				break;
			case 'B':
				data.second.second = { i, j };
				pan[i][j] = '.';
				break;
			}

		}
	}
	qu.push(data);
}

pair<pair<int, int>, pair<int, int>> leftMove(pair<int, int> red, pair<int, int> blue) {
	pair<int, int> faster, slower;
	if (blue.second > red.second) {
		faster = red;
		slower = blue;
	}
	else {
		faster = blue;
		slower = red;
	}

	int fi = faster.first;
	int fj = faster.second;

	while (pan[fi][fj] != '#' && pan[fi][fj] != 'O') {
		fj--;
	}
	if (pan[fi][fj] == 'O') {
		fj = -1;
		fi = -1;
	}
	else
		fj++;

	int si = slower.first;
	int sj = slower.second;

	while (pan[si][sj] != '#' && pan[si][sj] != 'O' && ((si == fi && sj != fj) || (si != fi))) {
		sj--;
	}
	if (pan[si][sj] == 'O') {
		sj = -1;
		si = -1;
	}
	else
		sj++;

	if (blue.second > red.second) {
		return { {fi, fj} , {si, sj} };
	}
	else {
		return { {si, sj}, {fi, fj} };
	}
}

pair<pair<int, int>, pair<int, int>> rightMove(pair<int, int> red, pair<int, int> blue) {
	pair<int, int> faster, slower;
	if (blue.second < red.second) {
		faster = red;
		slower = blue;
	}
	else {
		faster = blue;
		slower = red;
	}

	int fi = faster.first;
	int fj = faster.second;

	while (pan[fi][fj] != '#' && pan[fi][fj] != 'O') {
		fj++;
	}
	if (pan[fi][fj] == 'O') {
		fj = -1;
		fi = -1;
	}
	else
		fj--;

	int si = slower.first;
	int sj = slower.second;

	while (pan[si][sj] != '#' && pan[si][sj] != 'O' && ((si == fi && sj != fj) || (si != fi))) {
		sj++;
	}
	if (pan[si][sj] == 'O') {
		sj = -1;
		si = -1;
	}
	else
		sj--;

	if (blue.second < red.second) {
		return { {fi, fj} , {si, sj} };
	}
	else {
		return { {si, sj}, {fi, fj} };
	}
}

pair<pair<int, int>, pair<int, int>> upMove(pair<int, int> red, pair<int, int> blue) {
	pair<int, int> faster, slower;
	if (blue.first > red.first) {
		faster = red;
		slower = blue;
	}
	else {
		faster = blue;
		slower = red;
	}

	int fi = faster.first;
	int fj = faster.second;

	while (pan[fi][fj] != '#' && pan[fi][fj] != 'O') {
		fi--;
	}
	if (pan[fi][fj] == 'O') {
		fj = -1;
		fi = -1;
	}
	else
		fi++;

	int si = slower.first;
	int sj = slower.second;

	while (pan[si][sj] != '#' && pan[si][sj] != 'O' && ((sj == fj && si != fi) || (sj != fj))) {
		si--;
	}
	if (pan[si][sj] == 'O') {
		sj = -1;
		si = -1;
	}
	else
		si++;

	if (blue.first > red.first) {
		return { {fi, fj} , {si, sj} };
	}
	else {
		return { {si, sj}, {fi, fj} };
	}
}

pair<pair<int, int>, pair<int, int>> downMove(pair<int, int> red, pair<int, int> blue) {
	pair<int, int> faster, slower;
	if (blue.first < red.first) {
		faster = red;
		slower = blue;
	}
	else {
		faster = blue;
		slower = red;
	}

	int fi = faster.first;
	int fj = faster.second;

	while (pan[fi][fj] != '#' && pan[fi][fj] != 'O') {
		fi++;
	}
	if (pan[fi][fj] == 'O') {
		fj = -1;
		fi = -1;
	}
	else
		fi--;

	int si = slower.first;
	int sj = slower.second;

	while (pan[si][sj] != '#' && pan[si][sj] != 'O' && ((sj == fj && si != fi) || (sj != fj))) {
		si++;
	}
	if (pan[si][sj] == 'O') {
		sj = -1;
		si = -1;
	}
	else
		si--;

	if (blue.first < red.first) {
		return { {fi, fj} , {si, sj} };
	}
	else {
		return { {si, sj}, {fi, fj} };
	}
}

bool judge(pair<int, int> red, pair<int, int> blue) {
	if (blue.first == -1)
		return false;

	if (red.first == -1 && blue.first == -1)
		return false;


	for (auto node : vec) {
		if (node.first == red && node.second == blue)
			return false;
	}

	return true;
}


int solution() {
	while (!qu.empty()) {
		auto node = qu.front();
		qu.pop();
		int time = node.first + 1;

		if (time == 11)
			return -1;

		auto red = node.second.first;
		auto blue = node.second.second;

		vec.push_back(node.second);

		auto left = leftMove(red, blue);
		if (judge(left.first, left.second)) {
			if (left.first.first == -1)
				return time;
			qu.push({ time, left });
		}

		auto right = rightMove(red, blue);
		if (judge(right.first, right.second)) {
			if (right.first.first == -1)
				return time;
			qu.push({ time, right });
		}

		auto up = upMove(red, blue);
		if (judge(up.first, up.second)) {
			if (up.first.first == -1)
				return time;
			qu.push({ time, up });
		}

		auto down = downMove(red, blue);
		if (judge(down.first, down.second)) {
			if (down.first.first == -1)
				return time;
			qu.push({ time, down });
		}
	}
	return -1;
}

int main(void) {
	init();
	printf("%d", solution());
}
