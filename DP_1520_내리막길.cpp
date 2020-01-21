//#1520 내리막길	#DP #다이나믹프로그래밍
/*
dynamic programming 문제.

재귀, memoization 사용하여 top-down 방식으로 해결.
처음에는 top-down으로 인접배열 중 값이 작기만하면(내리막이기만하면) 1로 dp배열에 저장해주었으나
결과에 도달한 배열만 1로 저장해줘야함을 깨닫고 재귀함수 사용하였음.

또한 결과에 도달하지 못하는 경우(막다른 길 등) 길을 계속 탐색하기 때문에
방문한 dp 배열값을 방문하지 않은 배열값과 차이를 둠으로 이를 해결함.



+a) 일반적인 재귀 함수 구성
-탈출 조건문(값 리턴)
-기타 조건문
-재귀함수 호출 부

+a) 배열 idx 참조시 할당되지 않은 idx참조를 막기위해 조건문 작성할 때
'&&' 연산자는 앞이 False이면 뒤의 조건과 무방하게 바로 조건문 탈출하므로 (idx참조 조건)&&(조건) 식으로 작성하면 용이함.
*/

#include <iostream>
#include <vector>

using namespace std;

vector <vector<int> > arr(500, vector<int>(500, 0));
vector <vector<int> > dp(500, vector<int>(500, -1));	//why M(N)+2? 할당되지 않은 메모리 참조하는 것을 방지하기 위하여 배열 주변에 테두리 생성하기 위함
int M, N;

int downhill(int x, int y)
{
	if ((x == M - 1) && (y == N - 1))	//arrive at the end
	{
		return 1;
	}

	if (dp[x][y] != -1)	//이미 방문했다면 해당 dp에 저장돼있는값 반환 (momiozation)
	{
		return dp[x][y];
	}

	dp[x][y] = 0;	//방문 했었음을 표시.

	//내리막길 찾아서 이동
	if (x - 1 >= 0 && arr[x][y] > arr[x - 1][y])	//go up
	{
		dp[x][y] += downhill(x - 1, y);
	}

	if (y + 1 <= N - 1 && arr[x][y] > arr[x][y + 1])	//go right
	{
		dp[x][y] += downhill(x, y + 1);
	}

	if (x + 1 <= M - 1 && arr[x][y] > arr[x + 1][y])	//go down
	{
		dp[x][y] += downhill(x + 1, y);
	}

	if (y - 1 >= 0 && arr[x][y] > arr[x][y - 1])	//go left
	{
		dp[x][y] += downhill(x, y - 1);
	}

	return dp[x][y];
}

int main()
{
	cin >> M >> N;

	for (int i = 0; i < M; i++)	//input the arr
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	downhill(0, 0);

	cout << dp[0][0];

	return 0;
}
