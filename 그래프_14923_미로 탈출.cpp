/*
BaekJoon #14923 미로 탈출

<오답 알고리즘 1>
1. BFS로 모든 노드에 최소경로 정보 저장.
2. 벽인 노드에 양쪽 길로 갈 수 있는 최소경로정보의 차를 저장하여 차가 제일 큰 곳에 마법지팡이 사용. (벽을 길로 만든다.)
3. 결과값에서 마법지팡이 사용한 곳의 차 정보 - 2 를 빼주어 출력. (벽을 지나므로 시간이 총 2가 소비되기 때문에 2를 빼준다.)

*** 추가로 시작점 혹은 도착점이 벽으로 막혀있는 경우는 지팡이를 무조건 그 곳에 써주어야 한다.
BFS로 최소경로 지정할 때 도달하지 못하면 살펴보면 된다.

-> 벽이 있으면 무조건 양쪽에 길이 존재할 것이라는 생각이 잘못됨
ex 0 1
   1 0


<오답 알고리즘 2 (메모리초과)>
벽도 1번 방문 가능하며 벽에 가는 최소경로까지 저장해준다는 생각으로 코드 작성.

-> 100만개 배열 3개, 큐 두개 사용하였더니 메모리 초과.

<오답 알고리즘 3 (틀렸습니다)>
path (100만개 배열) 1개 줄였더니 틀렸습니다. 이미 값이 들어있는 배열을 다시 접근하여 최솟값을 넣어주는 과정에서 벽과 길 정보가 부족하여 값이 뒤섞였다.

<ADT>
3차원 배열을 이용하여 magic power을 썼을 때의 최소경로 정보와 쓰지 않았을 때의 최소경로 정보를 BFS를 통하여 한번에 작성한다.
즉, magic 유무에 따라 magic을 썼으면 queue에 길만 넣어주고 안썼으면 벽도 넣어준다.
*/

#include <iostream>
#include <math.h>
#include <queue>

using namespace std;

int maze[1001][1001];
int path[1001][1001][2];
int row_way[4] = { 1, 0, -1, 0 };
int col_way[4] = { 0, 1, 0, -1 };
queue <pair <pair<int, int> , int> > q;
int row_max, col_max;

struct point
{
	int row, col;
} typedef Point;

bool in_max_idx(int row, int col)
{
	if (row >= 0 && row < row_max && col >= 0 && col < col_max)
		return true;
	else
		return false;
}

int main()
{
	int magic = 1;
	Point start, end;

	cin >> row_max >> col_max >> start.row >> start.col >> end.row >> end.col;
	start.row -= 1;
	start.col -= 1;
	end.row -= 1;
	end.col -= 1;

	for (int i = 0; i < row_max; i++)
		for (int j = 0; j < col_max; j++)
			cin >> maze[i][j];

	q.push(make_pair(make_pair(start.row, start.col), magic));
	path[start.row][start.col][magic] = 1;

	while (!q.empty()) {
		if (q.front().first.first == end.row && q.front().first.second == end.col)
		{
			magic = q.front().second;
			break;
		}

		for (int i = 0; i < 4; i++) {
			Point next_idx;
			int temp = q.front().second;
			next_idx.row = q.front().first.first + row_way[i];
			next_idx.col = q.front().first.second + col_way[i];


			if (in_max_idx(next_idx.row, next_idx.col) && path[next_idx.row][next_idx.col][temp] == 0) {
				//마법 사용한 경우 , 안 한 경우 나누기

				if (temp == 1){	//사용 안한 경우
					if (maze[next_idx.row][next_idx.col] == 1)	//벽이면 magic = 0으로 push
					{
						path[next_idx.row][next_idx.col][0] = path[q.front().first.first][q.front().first.second][1] + 1;
						q.push(make_pair(make_pair(next_idx.row, next_idx.col), 0));
					}
					else	//길이면 magic = 1으로 push
					{
						path[next_idx.row][next_idx.col][1] = path[q.front().first.first][q.front().first.second][1] + 1;
						q.push(make_pair(make_pair(next_idx.row, next_idx.col), 1));
					}
				}
				else {	//사용한 경우
					if (maze[next_idx.row][next_idx.col] == 0)
					{
						path[next_idx.row][next_idx.col][0] = path[q.front().first.first][q.front().first.second][0] + 1;
						q.push(make_pair(make_pair(next_idx.row, next_idx.col), 0));
					}
				}
			}
		}

		q.pop();
	}

	if (path[end.row][end.col][magic] == 0)
		cout << -1 << endl;
	else
		cout << path[end.row][end.col][magic] - 1 << endl;
}
