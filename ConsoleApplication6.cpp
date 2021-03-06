// ConsoleApplication6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include<stdio.h> 
#include<string.h> 
#include<iostream>
#include<vector>



int main()
{
	int n = 0;
	std::cin >> n; 
	if (n <= 2 || n % 1 != 0)
	{
		std::cout << "Invalid!";
		return 0;
	}
	std::vector<std::vector<int>> magicSquare(n, std::vector<int>(n));
	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				magicSquare[i][j] = 0;
			}
		}

	if (n % 2 == 1)
	{


		// 初始化1的位置 （最后一列中间的值）
		int i = n / 2;
		int j = n - 1;


		for (int num = 1; num <= n * n; )
		{
			if (i == -1 && j == n) //防止超越右上限
			{
				j = n - 2;
				i = 0;
			}
			else
			{
				// 防止超越右限 
				if (j == n)
				{
					j = 0;
				}



				if (i < 0)
				{
					i = n - 1;//防止超越上限
				}

			}
			if (magicSquare[i][j]) //如果已经有数
			{
				j -= 2;
				i++;
				continue;
			}
			else
				magicSquare[i][j] = num++; //放置数字

			j++; i--; //下一个数字填在右上方
		}

		
	}
	if (n % 4 == 0)
	{
		int num = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				magicSquare[i][j] = num;
				num++;
			}
		}
		std::vector<std::vector<int>> magicSquare1(n, std::vector<int>(n));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				magicSquare1[i][j] = magicSquare[i][j];
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (((j >= n / 4 && j < n / 4 * 3) && ((i < n / 4) || (i >= n / 4 * 3))) || ((i >= n / 4 && i < n / 4 * 3) && ((j < n / 4) || (j >= n / 4 * 3))))
				{
					magicSquare1[n-1-i][n-1-j] = magicSquare[i][j];
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				magicSquare[i][j] = magicSquare1[i][j];
			}
		}


		
	}
	if (n % 4 == 2)
	{
		int m = n / 2;
		std::vector<std::vector<int>> magicSquare1(m, std::vector<int>(m));
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				magicSquare1[i][j] = 0;
			}
		}

		// 初始化1的位置 （最后一列中间的值）
		int i = m / 2;
		int j = m - 1;


		for (int num = 1; num <= m * m; )
		{
			if (i == -1 && j == m) //防止超越右上限
			{
				j = m - 2;
				i = 0;
			}
			else
			{
				// 防止超越右限 
				if (j == m)
				{
					j = 0;
				}



				if (i < 0)
				{
					i = m - 1;//防止超越上限
				}

			}
			if (magicSquare1[i][j]) //如果已经有数
			{
				j -= 2;
				i++;
				continue;
			}
			else
				magicSquare1[i][j] = num++; //放置数字

			j++; i--; //下一个数字填在右上方
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (((i <= (n - 2) / 4)&&(j!=(m-1)/2))|| ((i == (n - 2) / 4)+1 && (j == (m - 1) / 2)))
				{
					magicSquare[2 * i][2 * j] = magicSquare1[i][j] * 4 - 4 + 4;
					magicSquare[2 * i+1][2 * j] = magicSquare1[i][j] * 4 - 4 + 2;
					magicSquare[2 * i][2 * j+1] = magicSquare1[i][j] * 4 - 4 + 1;
					magicSquare[2 * i+1][2 * j+1] = magicSquare1[i][j] * 4 - 4 + 3;

				}
				if (((i == (n - 2) / 4+1) && (j != (m - 1) / 2))|| ((i == (n - 2) / 4)  && (j == (m - 1) / 2)))
				{
					magicSquare[2 * i][2 * j] = magicSquare1[i][j] * 4 - 4 + 1;
					magicSquare[2 * i + 1][2 * j] = magicSquare1[i][j] * 4 - 4 + 2;
					magicSquare[2 * i][2 * j + 1] = magicSquare1[i][j] * 4 - 4 + 4;
					magicSquare[2 * i + 1][2 * j + 1] = magicSquare1[i][j] * 4 - 4 + 3;

				}
				if (i > (n - 2) / 4)
				{
					magicSquare[2 * i][2 * j] = magicSquare1[i][j] * 4 - 4 + 1;
					magicSquare[2 * i + 1][2 * j] = magicSquare1[i][j] * 4 - 4 + 3;
					magicSquare[2 * i][2 * j + 1] = magicSquare1[i][j] * 4 - 4 + 4;
					magicSquare[2 * i + 1][2 * j + 1] = magicSquare1[i][j] * 4 - 4 + 2;

				}

			}
		}



	}
	// 打印幻方
	printf("The Magic Square for n=%d:\nSum of "
		"each row or column %d:\n\n", n, n*(n*n + 1) / 2);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%3d ", magicSquare[i][j]);
		printf("\n");
	}
	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
