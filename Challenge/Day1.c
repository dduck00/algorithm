#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char max[1000000] = {0};
char tempAns[1000000] = {0};
int cutPosition[1000000] = {0};
int maxDepth;
int targetDepth;

int diff()
{
    for (int idx = 0; idx < maxDepth - targetDepth; idx++)
    {
        if (max[idx] == tempAns[idx])
            continue;
        return max[idx] < tempAns[idx];
    }
}

void makeTempAns(const char *num)
{
    int count = 0;
    for (int idx = 0; idx < maxDepth - targetDepth; idx++)
    {
        if (cutPosition[count] == 0)
        {
            tempAns[idx] = num[count];
            count++;
        }
        else
        {
            count++;
            idx--;
        }
    }
}

void dept(const char *num, int start, int rank)
{
    if (rank == targetDepth)
    {
        makeTempAns(num);
        if (diff())
        {
            strcpy(max, tempAns);
        }

        return;
    }

    for (int idx = start; idx < maxDepth; idx++)
    {
        cutPosition[idx] = 1;
        dept(num, idx + 1, rank + 1);
        cutPosition[idx] = 0;
    }
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char *solution(const char *number, int k)
{
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    maxDepth = strlen(number);
    targetDepth = k;

    dept(number, 0, 0);

    return max;
}
