#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define ALPHA 26

char answer[11] = {0};
int strToInt[ALPHA];
int intToStr[10];
int N;

void init(char * rule){
    for(int i = 0; i<ALPHA; i++){
        strToInt[i] = -1;
    }
    for(int i = 0; i<N; i++){
        intToStr[i] = rule[i]-'a';
        strToInt[intToStr[i]] = i;
    }
}

int makeInteger(char * c){
    int ret = 0;
    int multi = 1;
    int len = strlen(c);
    for(int i = 0; i<len ;i++){
        ret += multi * strToInt[c[len-i-1]-'a'];
        multi *= N;
    }
    return ret;
}

void makeString(int num){
    if(num == 0){
        answer[0] = intToStr[0]+'a';
        return;
    }
    char temp[11] = {0};
    int idx = 0;
    while(num != 0){
        temp[idx] = intToStr[num % N] + 'a';
        num /= N;
        idx++;
    }
    for(int i = 0; i<idx; i++){
        answer[i] = temp[idx-1-i];
    }
}

char* solution(const char* rule, const char* A, const char* B) {
    N = strlen(rule);
    init(rule);
    makeString(makeInteger(A) - makeInteger(B));
    return answer;
}
