#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    int commandCount = commands.size();
    
    for(int idx = 0; idx < commandCount; idx++){
        vector<int>temp = array;
        sort(&temp[commands[idx][0]-1], &temp[commands[idx][1]], less<int>());
        answer.push_back(temp[commands[idx][2]+commands[idx][0]-2]);
    }
    
    return answer;
}
