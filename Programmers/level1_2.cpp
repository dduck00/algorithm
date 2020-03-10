#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;

    int len = arr.size();
    int min = arr[0];
    int index = 0;
    for(int i = 1; i<len ;i++){
        if(arr[i] < min){
            min = arr[i];
            index = i;
        }
    }

    if(len == 1){
        answer.push_back(-1);
    } else{
        answer = vector<int>(len-1);
        for(int i = 0; i<len; i++){
            if(i == index)
                continue;
            answer[i - (i < index ? 0 : 1)] = arr[i];
        }
    }

    return answer;
}
