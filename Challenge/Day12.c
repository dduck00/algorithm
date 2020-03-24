#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int arr[1000] = {0};

int strike = 0;
int ball = 0;

void comp(int new, int sample){
    int n_a = new /100, n_b = (new/10)%10, n_c = new%10;
    int s_a = sample /100, s_b = (sample/10)%10, s_c = sample%10;
    
    if(n_a == s_a)
        strike++;
    if(n_b == s_b)
        strike++;
    if(n_c == s_c)
        strike++;
    
    if(n_a == s_b || n_a == s_c)
        ball++;
    if(n_b == s_a || n_b == s_c)
        ball++;
    if(n_c == s_a || n_c == s_b)
        ball++;
}

// baseball_len은 2차원 배열 baseball의 행(세로) 길이입니다.
int solution(int baseball[][3], size_t baseball_len) {
    int answer = 0;
    for(int i = 123; i<=987; i++){
        int pivot = 0;
        int a = i/100, b = (i/10)%10, c = i%10;
        if(a == b || b == c || a == c){
            continue;
        }
        if(a == 0 || b == 0 || c == 0){
            continue;
        }
        
        for(int j = 0; j<baseball_len; j++){
            strike = 0;
            ball = 0;
            if(i == baseball[j][0]){
                pivot = 1;
                break;
            }
            comp(i, baseball[j][0]);
            if(strike == baseball[j][1] && ball == baseball[j][2])
                continue;
            pivot = 1;
            break;
        }
        
        if(pivot == 1)
            continue;
        answer++;
    }
    return answer;
}
