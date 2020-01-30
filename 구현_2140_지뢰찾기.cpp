/*
2020.01.29

<ADT>
시계방향으로 돌면서 가장자리의 지뢰만 체크하면 된다.
답 : 가장자리의 지뢰수 + 가운데 정사각형의 크기
*/

#include <iostream>
#include <cmath>

using namespace std;

char mineMap[101][101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int row, col, result = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> mineMap[i][j];

	// topLeft -> topRight
	row = 0;
	col = 0;

	if (mineMap[row++][col++] == '1')
	{
		mineMap[row][col] = '*';
		result++;
	}

	for (; col < N - 2; col++)
	{
		if (mineMap[row - 1][col] == '1')
		{
			if(mineMap[row][col - 1] != '*' && mineMap[row][col] != '*')
			{
				mineMap[row][col + 1] = '*';
				result++;
			}
		}
		else if (mineMap[row - 1][col] == '2')
		{
			if ((mineMap[row][col - 1] != '*' && mineMap[row][col] == '*') || (mineMap[row][col - 1] == '*' && mineMap[row][col] != '*'))
			{
				mineMap[row][col + 1] = '*';
				result++;
			}
		}
		else
		{
			if (mineMap[row][col - 1] == '*' && mineMap[row][col] == '*')
			{
				mineMap[row][col + 1] = '*';
				result++;
			}
		}
	}

	// topRight -> bottomRight
	row = 1;
	col = N - 2;

	for (; row < N - 2; row++)
	{
		if (mineMap[row][col + 1] == '1')
		{
			if (mineMap[row - 1][col] != '*' && mineMap[row][col] != '*')
			{
				mineMap[row + 1][col] = '*';
				result++;
			}
		}
		else if (mineMap[row][col + 1] == '2')
		{
			if ((mineMap[row - 1][col] != '*' && mineMap[row][col] == '*') || (mineMap[row - 1][col] == '*' && mineMap[row][col] != '*'))
			{
				mineMap[row + 1][col] = '*';
				result++;
			}
		}
		else
		{
			if (mineMap[row - 1][col] == '*' && mineMap[row][col] == '*')
			{
				mineMap[row + 1][col] = '*';
				result++;
			}
		}
	}

	// bottomRight -> bottomLeft
	row = N - 2;
	col = N - 2;

	for (; col > 1; col--)
	{
		if (mineMap[row + 1][col] == '1')
		{
			if (mineMap[row][col + 1] != '*' && mineMap[row][col] != '*')
			{
				mineMap[row][col - 1] = '*';
				result++;
			}
		}
		else if (mineMap[row + 1][col] == '2')
		{
			if ((mineMap[row][col + 1] != '*' && mineMap[row][col] == '*') || (mineMap[row][col + 1] == '*' && mineMap[row][col] != '*'))
			{
				mineMap[row][col - 1] = '*';
				result++;
			}
		}
		else
		{
			if (mineMap[row][col + 1] == '*' && mineMap[row][col] == '*')
			{
				mineMap[row][col - 1] = '*';
				result++;
			}
		}
	}
	
	// bottomLeft -> topLeft
	row = N - 2;
	col = 1;

	for (; row > 2; row--)
	{
		if (mineMap[row][col - 1] == '1')
		{
			if (mineMap[row + 1][col] != '*' && mineMap[row][col] != '*')
			{
				mineMap[row - 1][col] = '*';
				result++;
			}
		}
		else if (mineMap[row][col - 1] == '2')
		{
			if ((mineMap[row + 1][col] != '*' && mineMap[row][col] == '*') || (mineMap[row + 1][col] == '*' && mineMap[row][col] != '*'))
			{
				mineMap[row - 1][col] = '*';
				result++;
			}
		}
		else
		{
			if (mineMap[row + 1][col] == '*' && mineMap[row][col] == '*')
			{
				mineMap[row - 1][col] = '*';
				result++;
			}
		}
	}

	if (N > 4)
		cout << result + pow(N - 4, 2);
	else
		cout << result;
}
