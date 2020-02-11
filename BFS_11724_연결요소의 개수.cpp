#include <iostream>
#include <queue>

using namespace std;

int graph[1001][1001];
int check[1001];
int num_of_connected;
queue<int> q;

void bfs(int row, int N)
{
	check[row] = 1;

	for (int i = 0; i < N; i++)
	{
		if (graph[row][i] == 1 && check[i] == 0)
			q.push(i);
	}

	while (!q.empty() && check[q.front()] == 1)
		q.pop();

	if (!q.empty())
		bfs(q.front(), N);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	int start, end;

	for (int i = 0; i < M; i++)
	{
		cin >> start >> end;
		graph[start - 1][end - 1] = 1;
		graph[end - 1][start - 1] = 1;
	}

	for (int i = 0; i < N; i++)
	{
		if (check[i] == 0)
		{
			bfs(i, N);
			num_of_connected += 1;
		}
	}

	cout << num_of_connected;
}
