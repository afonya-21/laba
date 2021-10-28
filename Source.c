#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <malloc.h>

int main()
{
	setlocale(LC_ALL, "RUS");
	double min, max, a, b, sum = 0;
	int k, j, N;
	double* arr = NULL;
	int* arr1 = NULL;
	printf("¬ведите количество случайных чисел = ");
	scanf_s("%d", &N);
	printf("¬ведите минимальное значение массива = ");
	scanf_s("%lf", &min);
	printf("¬ведите максимальное значение массива = ");
	scanf_s("%lf", &max);
	if ((min >= max) || (N <= 0)) {
		printf("!!!¬ведите корректные данные!!!");
		return 0;
	}

	arr = ((double*)malloc(N * sizeof(double) + 1));
	arr1 = ((int*)malloc(N * sizeof(double) + 1));
	for (k = 0; k < N; k++)
	{
		arr[k] = (((double)rand()) / RAND_MAX * (max - min) + min);
	/*	printf("arr[%d", k);
		printf("] = %lf\n", arr[k]);*/
		a = modf(arr[k], &b);
		arr1[k] = (int)ceil(a * 1000000);
		sum = sum + arr[k];
	}
	for (k = 0; k < N; k++)
	{
		for (j = 0; j < N; j++)
		{
			if (k == arr1[j])
			{
				sum = sum - 2 * arr[j];
			}
		}
	}
	printf("sum = %lf\n", sum);
	return 0;
}