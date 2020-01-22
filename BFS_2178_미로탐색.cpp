/*
BaekJoon #2178 미로탐색
#DFS #BFS

<오답노트>
dfs로 푸려다 보니 예외처리 할 것이 많아져서 bfs로 변경했음.
처음에 pop()을 for문 안에다가 넣어줘서 제대로 된 bfs가 이루어 지지 않았음.

<Better>
x, y좌표로 이루어진 point 구조체 만들고 이 구조체type의 queue를 만들어서 코딩하면 좀 더 괜찮았을 것.
*/

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int graph[102][102];
int check[102][102];
queue <int> arr_x;
queue <int> arr_y;
int idx_x[4] = {1, 0, -1, 0};	//sequnce : down, right, up, left
int idx_y[4] = {0, 1, 0, -1};

void bfs()
{
	while (!arr_x.empty() && !arr_y.empty())
	{
		check[arr_x.front()][arr_y.front()] = 1;

		for (int i = 0; i < 4; i++)
		{
			if (graph[arr_x.front() + idx_x[i]][arr_y.front() + idx_y[i]] == 1 && check[arr_x.front() + idx_x[i]][arr_y.front() + idx_y[i]] == 0)
			{
				graph[arr_x.front() + idx_x[i]][arr_y.front() + idx_y[i]] = graph[arr_x.front()][arr_y.front()] + 1;
				arr_x.push(arr_x.front() + idx_x[i]);
				arr_y.push(arr_y.front() + idx_y[i]);
			}
		}
		
		arr_x.pop();
		arr_y.pop();
	}
}

int main()
{
	int row, col;
	cin >> row >> col;

	for (int i = 1; i < row + 1; i++)
	{
		for (int j = 1; j < col + 1; j++)
		{
			scanf("%1d", &graph[i][j]);
		}
	}

	arr_x.push(1);
	arr_y.push(1);
	bfs();
	cout << graph[row][col];
}
