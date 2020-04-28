#include <stdio.h>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>

#define PAN vector<vector<int>>

using namespace std;

int N;
int maxi = -1;
queue<pair<int, PAN>> qu;

void init() {
	scanf("%d", &N);

	PAN temp = PAN(N);
	for (int i = 0; i < N; i++) {
		temp[i] = vector<int>(N);
		for (int j = 0; j < N; j++) {
			scanf("%d", &temp[i][j]);
			maxi = maxi > temp[i][j] ? maxi : temp[i][j];
		}
	}
	qu.push({ 0, temp });
}

PAN moveCol(PAN origin) {
	for (int j = 0; j < N; j++) {
		stack<int> st;
		st.push(origin[0][j]);
		for (int i = 1; i < N; i++) {
			if (origin[i][j] == 0)
				continue;
			if (st.top() == origin[i][j]) {
				st.top() *= 2;
				st.push(0);
			}
			else
				st.push(origin[i][j]);
		}
		vector<int> temp;
		while(!st.empty()) {
			if (st.top() != 0){
				maxi = maxi > st.top() ? maxi : st.top();
				temp.push_back(st.top());
			}
			st.pop();
		}
		reverse(temp.begin(), temp.end());
		for (int i = 0; i < N; i++) {
			if (temp.size() > i)
				origin[i][j] = temp[i];
			else
				origin[i][j] = 0;
		}
	}
	return origin;
}

PAN moveRow(PAN origin) {
	for (int i = 0; i < N; i++) {
		stack<int> st;
		st.push(origin[i][0]);
		for (int j = 1; j < N; j++) {
			if (origin[i][j] == 0)
				continue;
			if (st.top() == origin[i][j]) {
				st.top() *= 2;
				st.push(0);
			}
			else
				st.push(origin[i][j]);
		}
		vector<int> temp;
		while (!st.empty()) {
			if (st.top() != 0) {
				maxi = maxi > st.top() ? maxi : st.top();
				temp.push_back(st.top());
			}
			st.pop();
		}
		reverse(temp.begin(), temp.end());
		for (int j = 0; j < N; j++) {
			if (temp.size() > j)
				origin[i][j] = temp[j];
			else
				origin[i][j] = 0;
		}
	}
	return origin;
}

PAN UP(PAN origin) {
	return moveCol(origin);
}

PAN DOWN(PAN origin) {
	PAN temp = PAN(N);
	for (int i = 0; i < N; i++) {
		temp[i] = vector<int>(N);
		for (int j = 0; j < N; j++) {
			temp[i][j] = origin[N - i - 1][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (origin[i][j] != temp[i][j])
				return moveCol(temp);
		}
	}
	return PAN();
}

PAN LEFT(PAN origin) {
	return moveRow(origin);
}

PAN RIGHT(PAN origin) {
	PAN temp = PAN(N);
	for (int i = 0; i < N; i++) {
		temp[i] = vector<int>(N);
		for (int j = 0; j < N; j++) {
			temp[i][j] = origin[i][N - j - 1];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (origin[i][j] != temp[i][j])
				return moveRow(temp);
		}
	}
	return PAN();
}



int solution() {

	while (!qu.empty()) {
		auto front = qu.front();
		qu.pop();
		int time = front.first;
		if (time == 5) {
			return maxi;
		}
		auto vec = front.second;

		auto right = RIGHT(vec);
		auto left = LEFT(vec);
		auto up = UP(vec);
		auto down = DOWN(vec);

		if (right.size() != 0)
			qu.push({ time + 1, right });
		if (down.size() != 0)
			qu.push({ time + 1, down });
		qu.push({ time + 1, up });
		qu.push({ time + 1, left });
	}
}


int main(void) {
	init();
	printf("%d", solution());
}
