#include "Header.h"

int *countNum(int *arr, int *coef, int digit)
{
	int i, j, k, digitTemp, sub;
	digitTemp = digit - 1;
	while (digitTemp >= 0)
	{
		sub = digit - digitTemp;
		if (sub == 1)
		{
			for (i = 1; i < coef[digitTemp]; i++)
			{
				arr[i] = pow(10, (digitTemp));
			}
			for (j = 0; j < digitTemp; j++)
			{
				arr[i] = arr[i] + coef[j] * pow(10, j);
			}
			arr[i]++;//00인 경우 고려
		}
		else
		{
			for (i = 0; i < 10; i++)
			{
				switch (coef[digitTemp] > i ? 1 : coef[digitTemp] == i ? 0 : -1)
				{
				case 1:
					for (j = 0; j < sub - 1; j++)
					{
						arr[i] = arr[i] + coef[digit - 1 - j] * pow(10, (digit - 2 - digitTemp - j)) * pow(10, digitTemp);
					}
					arr[i] += pow(10, digitTemp);
					break;
				case 0:
					for (j = 0; j < sub - 1; j++)
					{
						arr[i] = arr[i] + coef[digit - 1 - j] * pow(10, (digit - 2 - digitTemp - j)) * pow(10, digitTemp);
					}
					for (k = 0; k < digitTemp; k++)
					{
						arr[i] = arr[i] + coef[k] * pow(10, k);
					}
					arr[i]++;
					break;
				case -1:
					for (j = 0; j < sub - 1; j++)
					{
						arr[i] = arr[i] + coef[digit - 1 - j] * pow(10, (digit - 2 - digitTemp - j)) * pow(10, digitTemp);
					}
				}
			}
		}
		if (sub != 1) arr[0] = arr[0] - pow(10, digitTemp);
		digitTemp--;
	}
	return arr;
}