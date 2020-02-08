/*
<오답노트>
고슴도치가 방문한 곳을 다시 방문하지 않는다는 조건문을 작성하지 않아 오답
*/

#include <iostream>
#include <string>
#include <queue>

#define ROWMAX 50
#define COLMAX 50

using namespace std;

char Map[ROWMAX][COLMAX];
bool check[ROWMAX][COLMAX];
queue <pair<int, int> > q;
queue <pair<int, int> > waterQ;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void bfs(int& result)
{
	int count = 0;

	while (!q.empty())
	{
		count++;
		int q_size = q.size();
		int wQ_size = waterQ.size();

		while (wQ_size--)
		{
			int row = waterQ.front().first;
			int col = waterQ.front().second;
			waterQ.pop();

			for (int i = 0; i < 4; i++)
			{
				int nextRow = row + dx[i];
				int nextCol = col + dy[i];

				if (nextRow >= 0 && nextRow < ROWMAX && nextCol >= 0 && nextCol < COLMAX)
				{
					if (Map[nextRow][nextCol] == '.')
					{
						Map[nextRow][nextCol] = '*';
						waterQ.push(make_pair(nextRow, nextCol));
					}
				}
			}
		}

		while (q_size--)
		{
			int row = q.front().first;
			int col = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int nextRow = row + dx[i];
				int nextCol = col + dy[i];

				if (Map[nextRow][nextCol] == 'D')
				{
					result = count;
					return;
				}

				else if (nextRow >= 0 && nextRow < ROWMAX && nextCol >= 0 && nextCol < COLMAX)
				{
					if (Map[nextRow][nextCol] == '.' && check[nextRow][nextCol] == 0)
					{
						check[nextRow][nextCol] = 1;
						q.push(make_pair(nextRow, nextCol));
					}
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int rowNum, colNum, result = 0;
	string input;
	cin >> rowNum >> colNum;

	for (int i = 0; i < rowNum; i++)
	{
		cin >> input;
		for (int j = 0; j < colNum; j++)
		{
			Map[i][j] = input[j];

			if (Map[i][j] == '*')
				waterQ.push(make_pair(i, j));
			else if (Map[i][j] == 'S')
				q.push(make_pair(i, j));
		}
	}

	bfs(result);

	if (result)
		cout << result;
	else
		cout << "KAKTUS";
}
