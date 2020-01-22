/*
BaekJoon #1697 숨바꼭질
2019.7.4
#BFS

<ADT>
도착지에 가는 방법이 도착지가 짝수라면 순간이동으로 바로 도착가능하고 도착지가 홀수라면 도착지 +,-1의 짝수까지(이를 짝수화 라고 하겠음)
순간이동으로 이동한 후에 한번 걸어서 도착 가능하다는 것을 파악.
따라서 도착지를 짝수화시켜서 이를 2로 계속 나눈값(=a)과 출발지와의 관계를 살펴보다가 a가 출발지보다 작아지는 시점에 2로 몇번 나누었는지를 세아리면 됨을 인지.
(단, 이 때 홀수를 나누게되면 한번 걷고 순간이동을 하는 것을 의미하므로 총 2초걸린다고 한다.)

안풀려서 알아보니 BFS라네..

<오답노트>
그리디 방법으로 풀릴 줄 알았으나 실패. 아래는 그리디 방법으로 풀려고 했을때의 ADT와 코드
*/
/*
<ADT>
1. 가는 방법 : 3가지 (1. 그냥 가는거, 2. 순간이동, 3. +,-1 이동 후 순간이동)
2. 가는 방법들 중에서 가장 목적지와의 거리가 짧아지는 방법을 택하여 이동 -> Greedy 방식

거리 비교하는 함수 필요(반환 : 가는 방법들을 수치화 해서 목적지와의 거리가 가장 짧아지는 방법에 해당하는 수치 반환)

#include <iostream>
#include <algorithm>

using namespace std;
int result;

void distance(int &start, const int end)
{
	int walk, warp, walk_warp;

	walk = abs(end - start);

	warp = abs(end - (start * 2));

	walk_warp = min(abs(end - (start + 1) * 2), abs(end - (start - 1) * 2)) + 1;

	if (walk <= warp)	//case : walk
	{
		result += end - start;
		start = end;
		cout << "걷는다..";
	}

	else if (warp < walk_warp)	// case : warp
	{
		result += 1;
		start = 2 * start;
		cout << "순간이동..";
	}

	else	// case : walk & warp
	{
		result += 2;
		if (abs(end - (start + 1) * 2) < abs(end - (start - 1) * 2))
			start = (start + 1) * 2;
		else
			start = (start - 1) * 2;
		cout << "걷고 순간이동..";
	}

	cout << "현재 위치 : " << start << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int start, end;
	cin >> start >> end;
	
	cout << "현재 위치 : " << start << endl;

	while (start != end)
	{
		distance(start, end);
	}

	cout << result;
}
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int path[100001] = { 0 };

void bfs(int start, int end)
{
	queue <int> q;

	q.push(start);
	path[start] = 1;

	while (!q.empty())
	{
		int temp = q.front();
		q.pop();

		if (temp == end)
		{
			path[temp] = path[temp] - 1;
			return;
		}

		if (temp - 1 >= 0 && path[temp - 1] == 0)
		{
			path[temp - 1] = path[temp] + 1;
			q.push(temp - 1);
		}

		if (temp + 1 <= 100000 && path[temp + 1] == 0)
		{
			path[temp + 1] = path[temp] + 1;
			q.push(temp + 1);
		}

		if (temp * 2 <= 100000 && path[temp * 2] == 0)
		{
			path[temp * 2] = path[temp] + 1;
			q.push(temp * 2);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int start, end;
	cin >> start >> end;

	bfs(start, end);

	cout << path[end];
}
