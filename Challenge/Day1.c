#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char maxNum[1000000] = { 0 };
char compNum[1000000] = { 0 };
char* numberPointer;

int cutPosition[1000000] = { 0 };
int maxDepth;
int targetDepth;
int ansLength;

int isTempAnsBig()
{
	for (int idx = 0; idx < ansLength; idx++)
	{
		if (maxNum[idx] == compNum[idx])
			continue;
		return maxNum[idx] < compNum[idx];
	}
}

void makeTempAns(const char* num)
{
	int count = 0;
	int realIdx = 0;
	for (int idx = 0; idx < ansLength; idx++)
	{
		if (count >= maxDepth)
			break;

		if (cutPosition[count] != idx+count)
		{
			compNum[idx] = num[idx+count];
		}
		else
		{
			count++;
			idx--;
		}
	}
}

void dept(int index, int rank, int position)
{
	if (rank == 0)
	{
		makeTempAns(numberPointer);
		if (isTempAnsBig())
		{
			strcpy(maxNum, compNum);
		}
		return;
	}
	else if (position == maxDepth)
		return;

	cutPosition[index] = position;
	dept(index+1, rank - 1, position +1);
	dept(index, rank, position + 1);
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* number, int k)
{
	// return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
	maxDepth = strlen(number);
	ansLength = maxDepth - targetDepth;
	numberPointer = number;
	targetDepth = k;

	dept(0, k, 0);

	return maxNum;
}
