#include"Header.h"

int main()
{
	int bookNum, i;
	scanf("%d", &bookNum);
	//각 책마다 0~9개수
	int **pageCount = (int**)malloc(bookNum * sizeof(int*));
	//페이지수
	int *pageNum = (int*)calloc(bookNum, sizeof(int));
	for (i = 0; i < bookNum; i++)
	{
		scanf("%d", &pageNum[i]);
	}
	for (i = 0; i < bookNum; i++)
	{
		pageCount[i] = (int*)calloc(10, sizeof(int));
	}
	int *digit = countDigit(pageNum, bookNum);
	int **coef = countCoef(pageNum, bookNum, digit);
	for (i = 0; i < bookNum; i++)
	{
		countNum(pageCount[i], coef[i], digit[i]);
	}
	printNum(pageCount, bookNum);
	for (i = 0; i < bookNum; i++)
	{
		free(coef[i]);
		free(pageCount[i]);
	}
	free(pageCount);
	free(coef);
	free(digit);
	free(pageNum);
	return 0;
}