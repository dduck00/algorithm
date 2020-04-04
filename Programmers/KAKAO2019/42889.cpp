#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int N, vector<int> stages) {

	vector<int> answer;

	vector<int> vec(502);
	vector<pair<float, int>> flot(502);
	for (int stage : stages) {
		vec[stage] ++;
	}

	for (int idx = N; idx > 0; idx--) {
		flot[idx].first = vec[idx] * -1;
		vec[idx] += vec[idx + 1];
		flot[idx].second = idx;
		flot[idx].first /= vec[idx];
	}

	sort(flot.begin(), flot.end());

	for (int idx = 0; idx < 502; idx++) {
		if (flot[idx].second != 0)
			answer.push_back(flot[idx].second);
	}


	return answer;

}
