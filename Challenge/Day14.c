#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define ll long long

ll calRet(int times_len, int times[], ll time){
    ll ret = 0;
    for(int i = 0; i<times_len; i++){
        ret += (time/times[i]);
    }
    return ret;
}

ll solution(int n, int times[], size_t times_len) {
    ll answer;
    ll max = times[0];
    ll min = 1;
    for(int i = 0; i<times_len; i++){
        if(times[i] > max)
            max = times[i];
    }
    max *= n;
    answer = max;
    while(min <= max){
        ll mid = (min + max)/2;

        ll cal = calRet(times_len, times, mid);

        if(cal < n){
            min = mid+1;
        }else if(cal >= n){
            answer = answer > mid ? mid : answer;
            max = mid-1;
        }
    }

    return answer;
}
