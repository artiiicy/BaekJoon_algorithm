#include <iostream>

using namespace std;

int graph[101][101];
int check[101];
int result;

void dfs(int row, int node_num)
{
	check[row] = 1;
	result += 1;

	for (int i = 0; i < node_num; i++)
	{
		if (graph[row][i] == 1 && check[i] == 0)
			dfs(i, node_num);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int node, edge;
	cin >> node >> edge;


	int start, end;
	for (int i = 0; i < edge; i++)
	{
		cin >> start >> end;
		graph[start - 1][end - 1] = 1;
		graph[end - 1][start - 1] = 1;
	}

	dfs(0, node);

	cout << result - 1;
}
