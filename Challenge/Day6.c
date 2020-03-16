#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int pan[101] = {0};

// monster_len은 monster의 길이입니다.
int solution(int monster[], int monster_len, int S1, int S2, int S3) {
    for(int i = 1; i <= S1; i++)
        for(int j = 1; j <= S2; j++)
            for(int k = 1; k <= S3; k++)
                pan[i+j+k]++;
            
    int answer = S1*S2*S3;
    
    for(int i = 0; i < monster_len; i++){
        answer -= pan[monster[i]-1];
    }
    
    return (answer)*1000/(S1*S2*S3);
}
