/*
<ADT>
BFS를 통해 불과 상근이가 각 칸에 도달할 수 있는 최소시간을 카운팅하여 불보다 빠르게 도착한다면 카운팅한 값을 반환한다.
(이 때, 출구란 가장 바깥쪽의 칸들을 의미한다.)

<시행착오>
1. DFS로 풀려하니 최소경로 값 지정해주는 것이 불편 -> BFS로 전환
2. 방문한 곳을 따로 체크해주지 않아 무한루프
3. 각 Testcase가 끝난 후 Map을 초기화를 해주지 않아 이전 값이 남아있어 오류 야기
4. 메모리초과를 해결하려 불과 사람 각각의 bfs를 합쳤으나 불이 모두 bfs를 하기전에 사람이 먼저 도착하는 경우를 조건문에 처리해주지 않아서 오답
5. 메모리초과 왜 해결안되는데 ㅡㅡ 아너ㅣ라ㅓㅁㄴ이ㅏ럼닝러민ㅇ러ㅣ

<오답노트>
메모리초과 : euqueue, dequeue를 너무 많이했다. q.pop을 했을 경우 방문했음을 체크해줬었는데 이는 여러지점에서 겹치는 구간을 모두 queue에 넣기 때문에 같은 칸이 큐에 중복되어 들어갈 수 있다.
				따라서 방문할 예정인 곳을 queue에 넣을때 체크해주어야 다른칸에서 겹치는 칸을 enqueue 하지 않는다.
틀렸습니다 : 시작점이 탈출구인 경우를 헤아려 주지 않아서 오답.
*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
#include <string>

using namespace std;
int temp1, temp2;
int rowMax, colMax;
int Map[1000][1000];
bool fireMap[1000][1000];
bool check[1000][1000];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
queue <pair<int, int> >q;
queue <pair<int, int> >fire_q;

int bfs()
{
	int count = 0;
	int currentRow, currentCol;

	while (q.size())
	{
		int numOfFire = fire_q.size();
		int numOfMan = q.size();
		count++;

		while (numOfFire--)
		{
			currentRow = fire_q.front().first;
			currentCol = fire_q.front().second;
			fire_q.pop();

			for (int i = 0; i < 4; i++)
			{
				int nextRow = currentRow + dx[i];
				int nextCol = currentCol + dy[i];

				// 이미 불이 붙어있는 자리이거나 벽, out of range라면 pass
				if (fireMap[nextRow][nextCol] == 1 || Map[nextRow][nextCol] == -1 || nextRow < 0 || nextRow >= rowMax || nextCol < 0 || nextCol >= colMax)
					continue;

				fireMap[nextRow][nextCol] = 1;
				fire_q.push(make_pair(nextRow, nextCol));
			}
		}

		while (numOfMan--)
		{
			currentRow = q.front().first;
			currentCol = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int nextRow = currentRow + dx[i];
				int nextCol = currentCol + dy[i];

				if (nextRow == 0 || nextRow == rowMax - 1 || nextCol == 0 || nextCol == colMax - 1)	// 출구에 도착한 경우 불이 붙지않았거나 벽이 아닌경우 탈출
				{
					if (Map[nextRow][nextCol] != -1 && fireMap[nextRow][nextCol] == 0)
						return count + 1;
				}

				// 이미 방문했던 곳이거나 벽이거나 불이라면 방문하지 않는다
				if (check[nextRow][nextCol] == 1 || Map[nextRow][nextCol] == -1 || fireMap[nextRow][nextCol] == 1 || nextRow < 0 || nextRow >= rowMax || nextCol < 0 || nextCol >= colMax)
					continue;

				check[nextRow][nextCol] = 1;
				q.push(make_pair(nextRow, nextCol));
			}
		}
	}

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int testNum, startRow, startCol;
	cin >> testNum;

	while (testNum)
	{
		int result = -1;
		string input;

		cin >> colMax >> rowMax;

		// initialize maps
		for (int i = 0; i < rowMax; i++)
		{
			cin >> input;

			for (int j = 0; j < input.length(); j++)
			{
				check[i][j] = 0;

				if (input[j] == '#')
					Map[i][j] = -1;

				else
				{
					Map[i][j] = 0;
					fireMap[i][j] = 0;

					if (input[j] == '*')
					{
						fire_q.push(make_pair(i, j));
						fireMap[i][j] = 1;
					}

					else if (input[j] == '@')
					{
						q.push(make_pair(i, j));
						check[i][j] = 1;
					}
				}
			}
		}

		// 시작점이 탈출구인 경우
		if (q.front().first == 0 || q.front().first == rowMax - 1 || q.front().second == 0 || q.front().second == colMax - 1)
			result = 1;
		else
			result = bfs();

		if (result == -1)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << result << endl;

		while (q.size())
			q.pop();

		while (fire_q.size())
			fire_q.pop();

		testNum--;
	}
}
