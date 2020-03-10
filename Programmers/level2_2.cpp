/*
0 또는 양의 정수가 주어졌을 때, 정수를 이어 붙여 만들 수 있는 가장 큰 수를 알아내 주세요.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string &a, string &b){
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    int len = numbers.size();
    
    vector<string> str = vector<string>(len);
    
    for(int i = 0; i<len; i++){
        str[i] = to_string(numbers[i]);
    }
    
    sort(str.begin(), str.end(), compare);
    
    for(int i = 0; i<len; i++){
        answer += str[i];
    }
    
    if(answer[0] == '0')
        answer = "0";
    
    
    return answer;
}
