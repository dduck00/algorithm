#include <string>
#include <vector>
#include <queue>
using namespace std;

int maxi = 0;
vector<vector<int>> arr;
bool row[200] = { 0 };

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    maxi = n;
    arr = computers;
    for (int i = 0; i < n; i++) {
        queue<int> qu;
        if (row[i] == false) {
            answer++;
            qu.push(i);
            row[i] = true;
        }

        while (!qu.empty()) {
            int idx = qu.front();
            qu.pop();
            for (int j = 0; j < n; j++) {
                if (row[j] == false && computers[idx][j] == 1) {
                    row[j] = true;
                    qu.push(j);
                }
            }
        }
    }

    return answer;
}
