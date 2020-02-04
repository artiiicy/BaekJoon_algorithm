  /*
BaekJoon #9663 N-Queen
#BackTracking #백트래킹

<오답노트>
1. abs함수 : 헤더 <cmath> 필요.
2. N = 1인 경우 결과 값이 0으로 출력되게 코드를 짰다.
*/

#include <iostream>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;
vector <pair<int, int> > nqueen;
int result;

bool promising(int row, int col)
{
	for (int i = 0; i < nqueen.size(); i++)
	{
		if (nqueen[i].second == col || abs(nqueen[i].first - row) == abs(nqueen[i].second - col))
			return false;
	}

	return true;
}

void nQueen(int row, int col, int N)
{
	for (int i = 0; i < N; i++)
	{
		if (promising(row + 1, i))
		{
			if (row + 1 == N - 1)
			{
				result++;
				continue;
			}

			nqueen.push_back(make_pair(row + 1, i));
			nQueen(row + 1, col, N);
			nqueen.pop_back();
		}
	}
}

int main()
{
	int N;
	cin >> N;

	if (N == 1)
		result = 1;

	for (int i = 0; i < N; i++)
	{
		nqueen.push_back(make_pair(0, i));
		nQueen(0, i, N);
		nqueen.clear();
	}

	cout << result;
}
