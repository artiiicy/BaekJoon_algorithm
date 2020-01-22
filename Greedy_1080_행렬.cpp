/*
BaekJoon #1080 행렬
#Greedy #그리디알고리즘

<ADT>
Matrix A와 B를 비교해서 값이 다르면 3x3 크기 만큼 원소를 뒤집는다.
이를 matrix의 모든 원소들을 탐색하며 실행하여 B로 만든다.
*/

#include <iostream>
#include <cstdio>

using namespace std;

int matrix1[50][50];
int matrix2[50][50];

void reverse(int row, int col)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix1[row + i][col + j] = !matrix1[row + i][col + j];
		}
	}
}

bool check(int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (matrix1[i][j] != matrix2[i][j])
			{
				return false;
			}
		}
	}

	return true;
}

int main()
{

	int row, col, result = 0;
	cin >> row >> col;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			scanf("%1d", &matrix1[i][j]);
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			scanf("%1d", &matrix2[i][j]);
	}

	for (int i = 0; i < row - 2; i++)
	{
		for (int j = 0; j < col - 2; j++)
		{
			if (matrix1[i][j] != matrix2[i][j])
			{
				reverse(i, j);
				result++;
			}
		}
	}

	if (check(row, col) == true)
		cout << result;
	else
		cout << -1;
}
