#include "Header.h"

int *countDigit(int *pageNum, int bookNum)
{
	int i, j;
	int *digit = (int*)malloc(bookNum * sizeof(int));
	for (i = 0; i < bookNum; i++)
	{
		for (j = 0;; j++)
		{
			if (pageNum[i] < pow(10, j))
			{
				digit[i] = j;
				break;
			}
		}
	}
	return digit;
}
//계수구하기 564->465, 1234->4321
int **countCoef(int *pageNum, int bookNum, int *digit)
{
	int i, j;
	int *pageNumTemp = (int*)malloc(bookNum * sizeof(int));
	int **coefTemp = (int**)malloc(bookNum * sizeof(int*));
	for (i = 0; i < bookNum; i++)
	{
		pageNumTemp[i] = pageNum[i];
	}
	for (i = 0; i < bookNum; i++)
	{
		coefTemp[i] = (int*)malloc(digit[i] * sizeof(int));
		for (j = digit[i]; j > 0; j--)
		{
			coefTemp[i][j - 1] = pageNumTemp[i] / pow(10, j - 1);
			pageNumTemp[i] = pageNumTemp[i] - pow(10, j - 1) * coefTemp[i][j - 1];
		}
	}
	return coefTemp;
}

void printNum(int **pageCount, int bookNum)
{
	int i, j;
	for (i = 0; i < bookNum; i++)
	{
		for (j = 0; j < 10; j++)
		{
			printf("%d ", pageCount[i][j]);
		}
		printf("\n");
	}
}