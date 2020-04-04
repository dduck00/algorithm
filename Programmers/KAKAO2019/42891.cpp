#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}


int solution(vector<int> food_times, long long k) {
	vector<pair<int, int>> vectorWithIndex;
    int size = food_times.size();
	for (int i = 0; i < size; i++)	{
		vectorWithIndex.push_back(make_pair(food_times.at(i), i + 1 ));
	}

	sort(vectorWithIndex.begin(), vectorWithIndex.end());

	int time = 0;
	for (vector<pair<int, int>>::iterator iter = vectorWithIndex.begin(); iter != vectorWithIndex.end(); iter++, size--) {
		long long tmp = (long long)(iter->first - time) * size;

		if (tmp < 0)
			continue;

		if (tmp <= k) {
			k -= tmp;
			time = iter->first;
		}
		else {
			k %= size;
			sort(iter, vectorWithIndex.end(), compare);
			return (iter + k)->second;
		}

	}

	return -1;
}
