/*
BackJoon #11043 경로찾기
#DFS #BFS

DFS, BFS 기초 문제.

***오답노트
이미 방문했던 노드 재방문 하려하면 다음 단계 실행하면 되는데 반복문을 아예 끝내버려서 한 번 틀림.
Cycle인 경우에 재방문 하지 않도록 하지 않아서 시간 초과.
동적할당으로 배열을 받아서 시간 초과.
*/

#include <iostream>

using namespace std;

int graph[101][101];
int path[101][101];

void findpath(int node, int pass, const int num)
{
	for (int i = 0; i < num; i++)
	{
		if (graph[pass][i] == 1)
		{
			if (path[node][i] != 1)	//방문한 적 없다면 방문
			{
				path[node][i] = 1;

				if (node == i)	//cycle인 경우 방문 X
					continue;

				findpath(node, i, num);
			}
		}
	}
}

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> graph[i][j];

	for (int i = 0; i < N; i++)
	{
		findpath(i, i, N);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << path[i][j] << " ";
		}
		cout << endl;
	}
}
