/*
BaekJoon #1012 유기농배추
#BFS #DFS

<Better>
- check 2차원 배열을 따로 만들지 않고 graph에서 방문시 값을 0으로 바꾸면 재방문 하는것을 방지할 수 있다.
- out of array 조건을 if(
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int check[51][51];
vector <vector <vector <int> > > graph;

void bfs(int t, int row, int col, int x, int y)
{
	check[row][col] = 1;

	//right
	if (col + 1 < x && graph[t][row][col + 1] == 1 && check[row][col + 1] == 0)
	{
		bfs(t, row, col + 1, x, y);
	}


	//left
	if (col - 1 >= 0 && graph[t][row][col - 1] == 1 && check[row][col - 1] == 0)
	{
		bfs(t, row, col - 1, x, y);
	}

	//up
	if (row - 1 >= 0 && graph[t][row - 1][col] == 1 && check[row - 1][col] == 0)
	{
		bfs(t, row - 1, col, x, y);
	}

	//down
	if (row + 1 < y && graph[t][row + 1][col] == 1 && check[row + 1][col] == 0)
	{
		bfs(t, row + 1, col, x, y);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int T, X, Y, K, result = 0;
	cin >> T;
	vector <int> arr_result(T, 0);

	for (int i = 0; i < T; i++)	//data 입력
	{
		cin >> X >> Y >> K;
		vector <vector <int> > temp(51, vector<int>(51, 0));

		int start, end;
		for (int i = 0; i < K; i++)
		{
			cin >> start >> end;
			
			temp[start][end] = 1;
		}
		graph.push_back(temp);
	}

	for (int t = 0; t < T; t++)	//각 test case마다 결과값 도출
	{
		for (int i = 0; i < Y; i++)
		{
			for (int j = 0; j < X; j++)
			{
				if (graph[t][i][j] == 1 && check[i][j] == 0)
				{
					bfs(t, i, j, X, Y);
					result += 1;
				}
			}
		}

		arr_result[t] = result;

		for (int i = 0; i < Y; i++)
		{
			for (int j = 0; j < X; j++)
				check[i][j] = 0;
		}

		result = 0;
	}

	for (int i = 0; i < T; i++)	//결과값 출력
		cout << arr_result[i] << endl;
}
