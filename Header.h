#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printNum(int **pageCount, int bookNum);
int *countNum(int *arr, int *coef, int digit);
int *countDigit(int *pageNum, int bookNum);
int **countCoef(int *pageNum, int bookNum, int *digit);
