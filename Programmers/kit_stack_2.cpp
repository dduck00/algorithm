#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int index = 0;
    int limit = truck_weights.size();
    int nowWeight = 0;
    queue<pair<int, int>> bridge;
    
    while(index < limit){
        answer++;
        int truck = truck_weights[index];
        if(bridge.empty() == false && bridge.front().second + bridge_length <= answer){
            nowWeight-=bridge.front().first;
            bridge.pop();
        }
        if(nowWeight + truck <= weight){
            bridge.push({truck, answer});
            nowWeight+=truck;
            index++;
        }
    }
    while(bridge.size() != 1){
        bridge.pop();
    }
    return bridge.front().second + bridge_length;
}
