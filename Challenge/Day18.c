#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int static compare (const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

// rocks_len은 배열 rocks의 길이입니다.
int solution(int distance, int rocks[], size_t rocks_len, int n) {
    int answer = 0;

    qsort(rocks, rocks_len, sizeof(int), compare);

    int left = 1;
    int right = distance;
    while(left <= right){
        int mid = (right + left) / 2;
        int min = right;
        int before = -1;
        int count = 0;
        for(int i = 0; i<rocks_len; i++){
            if(count > n)
                break;
            int temp = 0;
            if(before == -1){
                if(rocks[i] < mid){
                    count++;
                    continue;
                }
                temp = rocks[i];
            }
            else if(rocks[i] - rocks[before] < mid){
                count++;
                continue;
            }
            else
                temp = rocks[i] - rocks[before];
            min = min < temp ? min : temp;
            before = i;
            continue;
        }

        if(count > n){
            right = mid-1;
            continue;
        }

        answer = answer < mid ? mid : answer;
        left = mid+1;
    }

    return answer;
}
