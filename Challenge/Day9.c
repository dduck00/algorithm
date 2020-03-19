#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int brown, int red) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)*2);
    
    for(int i = 1; i*i<=red; i++){
        if(red%i != 0)
            continue;
        
        int col = (red/i)*2;
        int row = i*2;
        
        if(brown == (col + row + 4)){
            answer[0] = red/i+2;
            answer[1] = i+2;
            printf("%d %d", answer[0], answer[1]);
            return answer;
        }
    }
}
