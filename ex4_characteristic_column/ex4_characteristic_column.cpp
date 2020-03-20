#include "pch.h"
#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	const int n = 5;
	int array[n][n];
	int sum[n], count, temp, buf;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			array[i][j] = rand() % 20 - 10;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << "[" << i << "]" << "[" << j << "] = " << array[i][j] << "\t";
		}
		cout << "\n";
	}
	for (int j = 0; j < n; ++j)
	{
		count = 0;
		for (int i = 0; i < n; ++i)
		{
			if (array[i][j] % 2 != 0)
			{
				count += abs(array[i][j]);
			}
		}
		sum[j] = count;
		cout << sum[j] << "\t\t";
	}
	cout << "\n";
	for (int j = 1; j < n; ++j)
	{
		for (int i = 0; i < n - j; ++i)
		{
			if (sum[i] > sum[i + 1])
			{
				buf = sum[i];
				sum[i] = sum[i + 1];
				sum[i + 1] = buf;
				for (int p = i; p < i + 1; ++p)
				{
					for (int k = 0; k < n; ++k)
					{
						temp = array[k][p];
						array[k][p] = array[k][p+1];
						array[k][p+1] = temp;
					}
				}
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << "[" << i << "]" << "[" << j << "] = " << array[i][j] << "\t";
		}
		cout << "\n";
	}
	for (int i = 0; i < n; ++i)
	{
		cout << sum[i] << "\t\t";
	}
	cout << "\n";
	system("pause");
	return 0;
}
