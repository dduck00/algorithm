#include <string>
#include <vector>
#include <queue>

using namespace std;

int columSize;
int rowSize;
vector<vector<string>> inp;
queue<vector<int>>qu;
vector<vector<int>> arr;

void makeCombination(vector<int> arr, int idx, int n, int r, int target) {
    if (r == 0) qu.push(arr);
    else if (target == n) return;
    else {
        arr[idx] = target;
        makeCombination(arr, idx + 1, n, r - 1, target + 1);
        makeCombination(arr, idx, n, r, target + 1);
    }
}

bool judge(vector<int> vec) {
    for (int i = 0; i < rowSize; i++) {
        bool judgei = false;
        for (int j = i + 1; j < rowSize; j++) {
            bool judgej = true;
            for (int k = 0; k < vec.size(); k++) {
                if (inp[i][vec[k]] != inp[j][vec[k]]) {
                    judgej = false;
                    break;
                }
            }
            if (judgej) {
                judgei = true;
                break;
            }
        }
        if (judgei)
            return false;
    }
    return true;
}

bool canGo(vector<int> needJudgeVect) {

    for (auto answerVect : arr) {
        int count = 0;
        for (int answerIdx = 0; answerIdx < answerVect.size(); answerIdx++) {
            for (int judgeIdx = 0; judgeIdx < needJudgeVect.size(); judgeIdx++) {
                if (answerVect[answerIdx] == needJudgeVect[judgeIdx])
                    count++;
            }
        }
        if (count == answerVect.size())
            return false;
    }


    return true;
}

int solution(vector<vector<string>> relation) {
    inp = relation;
    int answer = 0;
    rowSize = relation.size();
    for (int i = 1; i <= relation[0].size(); i++) {
        vector<int> temp(i);
        makeCombination(temp, 0, relation[0].size(), i, 0);
    }
   
    for (int i = 0, size = qu.size(); i < size; i++) {
        auto front = qu.front();
        qu.pop();
        if (canGo(front) == false)
            continue;

        if (judge(front)) {
            arr.push_back(front);
            answer++;
        }
    }
    return answer;
}
