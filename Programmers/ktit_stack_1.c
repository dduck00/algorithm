#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// heights_len은 배열 heights의 길이입니다.
int* solution(int heights[], size_t heights_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int answer[100] = {0};
    
    for(int i = 0; i<heights_len - 1 ; i++){
        if(heights[i] > heights[i+1]){
            answer[i+1] = i+1;
            continue;
        }
        int idx = answer[i]-1;
        while(idx >= 0 && heights[idx] < heights[i+1]){
            idx = answer[idx]-1;
        }
        answer[i+1] = idx + 1;
    }
    
    return answer;
}
