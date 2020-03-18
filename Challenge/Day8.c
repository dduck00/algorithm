#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// priorities_len은 배열 priorities의 길이입니다.
int solution(int priorities[], size_t priorities_len, int location) {
    int queue[100] = {0};
    int idx = 0;
    int count = 0;
    while(true){
        count++;
        int max = -1;
        int maxIdx = idx;
        for(int i = 0; i<priorities_len; i++){
            int index = (idx+i)%priorities_len;
            if(queue[index] != 0)
                continue;
            if(max == -1 || max < priorities[index]){
                max = priorities[index];
                maxIdx = index;
            }
        }
        idx = (maxIdx + 1 == priorities_len) ? 0 : maxIdx + 1;
        queue[maxIdx] = max;
        if(maxIdx == location){
            return count >= priorities_len ? priorities_len : count;
        }
    }
}
