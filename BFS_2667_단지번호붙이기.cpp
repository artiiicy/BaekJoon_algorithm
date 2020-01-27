/*
BackJoon #2667 단지번호붙이기


ADT
1. BFS로 풀자.
2. BFS 탐색 끝날때마다 vill배열에 주택 개수 저장 / 단지 수 += 1

입력값이 공백 혹은 개행으로 구분되어있지 않음 -> cin이 아닌 scanf로 정수 1개씩 받도록 사용.
전역변수 -> 0으로 저절로 초기화 된다.
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int vill[313];	//단지 최대 개수 313개. 단지 내의 집 개수 저장할 배열
int vill_num = 0;
int input[25][25];
int check[25][25];

int bfs(int row, int col, int N, int house_num)
{
	check[row][col] = 1;

	//right
	if (col + 1 < N && input[row][col + 1] == 1 && check[row][col + 1] == 0)
		house_num = bfs(row, col + 1, N, house_num);
	
	//left
	if (col - 1 >= 0 && input[row][col - 1] == 1 && check[row][col-1] == 0)
		house_num = bfs(row, col - 1, N, house_num);

	//up
	if (row - 1 >= 0 && input[row - 1][col] == 1 && check[row - 1][col] == 0)
		house_num = bfs(row - 1, col, N, house_num);

	//down
	if (row + 1 < N && input[row + 1][col] == 1 && check[row + 1][col] == 0)
		house_num = bfs(row + 1, col, N, house_num);

	return house_num + 1;
}

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			scanf("%1d", &input[i][j]);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (input[i][j] == 1 && check[i][j] == 0)
			{
				vill[vill_num] = bfs(i, j, N, 0);
				vill_num += 1;
			}
		}
	}

	sort(vill, vill + vill_num);
	
	cout << vill_num << endl;
	for (int i = 0; i < vill_num; i++)
		cout << vill[i] << endl;
}
