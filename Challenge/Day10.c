#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char operators[20] = {0};
int len = 0;
int trg = 0;
int count = 0;
int * number;

int calc(){
    int ret = 0;
    for(int i = 0; i<len ;i++){
        ret += (operators[i] == '+' ?  number[i] : number[i] * -1);
    }
    return ret;
}

void dfs(int depth){
    if(depth == len){
        if(calc() == trg){
            count++;
        }
        return;
    }
    operators[depth] = '+';
    dfs(depth+1);
    operators[depth] = '-';
    dfs(depth+1);
}

int solution(int numbers[], size_t numbers_len, int target) {
    number = numbers;
    
    trg = target;
    
    len = numbers_len;
    
    dfs(0);
    return count;
}
