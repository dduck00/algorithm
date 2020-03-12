#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> sucTime;
    int count = progresses.size();
    for(int i = 0; i<count; i++){
        int time  = (100-progresses[i])/speeds[i] + (100-progresses[i])%speeds[i] != 0? 1: 0;
        sucTime.push_back(time);
    }
    
    for(int i = 0; i<count;){
        int ret = 1;
        for(int j = i+1; j<count; j++){
            if(sucTime[i] < sucTime[j]){  
                i = j;
                break;
            }
            ret++;
        }
        answer.push_back(ret);
    }
    
    return answer;
}
