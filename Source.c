#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#include <math.h>
#define M_PI 3.14159265359
#define N 1000

double* full_elements(double* ptr_array, int n);
int put_elements(double* ptr_array, int n);
double* calc_elements(double* ptr_array, int n);
double sum_elements(double* ptr_array, int begin, int end);
int find_element(double* ptr_array, int n, double element);
double func(double x);
int function(double* ptr_array, int n, int z);
int func22(double* ptr_array, int n, int z, int a);

int main()
{
	double array[N];
	int size, i = 0, a = 0, b = 0, z = 0, A = 0;
	float c = 0;

	setlocale(LC_ALL, "rus");
	printf("Введите размер массива > ");
	scanf("%d", &size);
	full_elements(array, size);
	put_elements(array, size);
	calc_elements(array, size);
	put_elements(array, size);
	printf("Введите начальный индекс для суммирования элеметов массива\n");
	scanf("%d", &a);
	printf("Введите конечный индекс для суммирования элеметов массива\n");
	scanf("%d", &b);
	printf("%f \n", sum_elements(array, a, b));
	printf("Введите значние элемента массива для поиска его индекса\n");
	scanf("%f", &c);
	printf("%d \n", find_element(array, size, c));
	printf("Введите 2 для поиска максимального значения на четных позициях или введите 1 для поиска максимального значения на нечетных позициях\n");
	scanf("%d", &z);
	printf("%d \n", function(array, size, z));
	printf("Введите A \n");
	scanf("%d", &A);
	printf("Введите 2 для поиска суммы чисел меньших А на четных позициях или введите 1 для поиска поиска суммы чисел меньших А на нечетных позициях\n");
	scanf("%d", &z);
	printf("%d \n", func22(array, size, z, A));
}

double* full_elements(double* ptr_array, int n)
{
	double x = 0.1;
	for (int i = 0; i < n; i++)
	{
		x += 0.01;
		ptr_array[i] = func(x);
	}
	return ptr_array;
}

int put_elements(double* ptr_array, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%lf ", ptr_array[i]);
	}
	return printf("\n");
}

double* calc_elements(double* ptr_array, int n)
{
	for (int i = 0; i < n; i++)
	{
		ptr_array[i] = ceil(ptr_array[i]);
	}
	return ptr_array;
}

double func(double x)
{
	double y;
	y = (x * x) + (2. * M_PI) * (cos(M_PI * x));
	return y;
}

double sum_elements(double* ptr_array, int begin, int end)
{
	double sum = 0;
	for (; begin < end; begin++)
	{
		sum += ptr_array[begin];
	}
	return sum;
}

int find_element(double* ptr_array, int n, double element)
{
	for (int i = 0; i < n; i++)
	{
		if (ptr_array[i] == element)
		{
			return i;
		}
	}
	return -1;
}

int function(double* ptr_array, int n, int z)
{
	int mx1 = -1000;
	int mx2 = -1000;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0 && z == 2) mx1 = fmax(ptr_array[i], mx1);
		else mx2 = fmax(ptr_array[i], mx2);
	}
	if (z == 2) return mx1;
	else return mx2;
}

int func22(double* ptr_array, int n, int z, int a)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0 && z == 2 && ptr_array[i] < a) sum += ptr_array[i];
		else if (i % 2 == 1 && z == 1 && ptr_array[i] < a) sum += ptr_array[i];
		
	}
	return sum;
}