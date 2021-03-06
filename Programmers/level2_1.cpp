/*
무인도에 갇힌 사람들을 구명보트를 이용하여 구출하려고 합니다. 구명보트는 작아서 한 번에 최대 2명씩 밖에 탈 수 없고, 무게 제한도 있습니다.
*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int popu = people.size();
    sort(people.begin(), people.end(), greater<int>());
    
    vector<bool> judge = vector<bool>(popu);
    int used = 0;
    for(int i = 0; i<popu; i++){
        int temp = people[i];
        if(judge[i])
            continue;
        answer++;
        for(int j = popu-1 - used; j>i; j--){
            if(judge[j])
                continue;
            if(temp + people[j] > limit){
                break;
            }
            used++;
            temp+=people[j];
            judge[j] = true;
        }
    }
    
    return answer;
}
