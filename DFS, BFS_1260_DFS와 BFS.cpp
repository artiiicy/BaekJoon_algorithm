/*
BackJoon #1260 DFS와BFS
#BFS #DFS


<Better>
-check 배열을 dfs방문하고 bfs방문하기 전에 0으로 모두 초기화 할 필요 없이 dfs가 끝나면 check배열이 모두 1로 돼있으므로 bfs에서는 방문 후에 0으로 바꿔주도록 코딩할 수 있다.
-bfs에서 굳이 재귀를 쓰지 않고 queue를 이용하여 graph[q.front()][i] + q.pop() 으로 모든 노드 탐색 가능
*/

#include <iostream>
#include <queue>

using namespace std;

int graph[1001][1001];
int check[1001];
queue<int>q;

void dfs(int row, int N)
{
	q.push(row + 1);
	check[row] = 1;

	for (int i = 0; i < N; i++)
	{
		if (graph[row][i] == 1 && check[i] == 0)
			dfs(i, N);
	}
}

void bfs(int row, int N)
{
	//queue 사용
	check[row] = 1;

	for (int i = 0; i < N; i++)
	{
		if (graph[row][i] == 1 && check[i] == 0)
			q.push(i);
	}

	if (!q.empty())
		cout << q.front() + 1 << " ";
	
	while(!q.empty() && check[q.front()] == 1)
		q.pop();

	if (!q.empty())
		bfs(q.front(), N);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, V;
	cin >> N >> M >> V;

	int start, end;
	for (int i = 0; i < M; i++)	//인접배열 초기화
	{
		cin >> start >> end;
		graph[start - 1][end - 1] = 1;
		graph[end - 1][start - 1] = 1;
	}

	dfs(V - 1, N);

	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;

	for (int i = 0; i < N; i++)
		check[i] = 0;

	q.push(V - 1);
	bfs(V - 1, N);
}
