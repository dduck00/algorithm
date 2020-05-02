#include <string>

using namespace std;

bool isNumber(char c) {
	return c >= '0' && c <= '9';
}

int solution(string resultDart) {
	int answer[3] = { 0 };
	int idx = 0;
	for (int i = 0; i < 3; i++) {
		int num = 0;
		for (; isNumber(resultDart[idx]); idx++) {
			num = num * 10 + resultDart[idx] - '0';
		}
		switch (resultDart[idx]) {
		case 'S':
			break;
		case 'D':
			num = num * num;
			break;
		case 'T':
			num = num * num * num;
			break;
		}
		idx++;
		answer[i] = num;
		switch (resultDart[idx]) {
		case '*':
			answer[i] *= 2;
			if (i != 0)
				answer[i - 1] *= 2;
			idx++;
			break;
		case '#':
			answer[i]*=-1;
			idx++;
			break;
		}
	}
	int ret = 0;

	for (int i = 0; i < 3; i++) {
		ret += answer[i];
	}

	return ret;
}
