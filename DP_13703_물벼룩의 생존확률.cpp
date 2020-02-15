/*
BaekJoon #13703 물벼룩의 생존확률
#DP #다이나믹프로그래밍

<ADT>
물벼룩의 위치(under)가 0 이하가 되면 잡아먹힌다. 따라서 under가 1 이상인 값들의 합을 구해야한다.

bfs/dfs 방식으로 풀수도 있겠지만 이미 이러한 방식을 통하여 메모리 초과를 맛 본 지인의 조언으로 바로 메모아이제이션을 사용하기로 결정.

1. 전체 배열 2개 만들기.
2. under번째 idx값 1로 초기화
3. 다음에 갈 수 있는 곳(idx - 1, idx + 1)값을 idx값으로 초기화.
4. 이를 배열의 값이 있는 곳에 대하여 모두 진행하면 배열에 각 idx에 방문할 수 있는 경우의 수가 저장된다.

단, 이 때 입력의 수가 2^63까지 이므로 int가 아닌 long long자료형을 사용한다.
*/
#include <iostream>
#include <vector>


using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int under, second, token = 0;
	long long result = 0;

	cin >> under >> second;

	vector <long long> arr1(under + second + 1, 0);
	vector <long long> arr2(under + second + 1, 0);


	arr1[under] = 1;
	
	for (int i = 0; i < second; i++)
	{
		if (token == 0)
		{
			for (int j = 1; j < under + second + 1; j++)
				arr2[j] = 0;

			for (int j = 1; j < under + second + 1; j++)
			{
				if (arr1[j] != 0)
				{
					arr2[j - 1] += arr1[j];

					if (j + 1 != under + second + 1)
						arr2[j + 1] += arr1[j];
				}
			}

			token = 1;
		}

		else
		{
			for (int j = 1; j < under + second + 1; j++)
				arr1[j] = 0;

			for (int j = 1; j < under + second + 1; j++)
			{
				if (arr2[j] != 0)
				{
					arr1[j - 1] += arr2[j];

					if (j + 1 != under + second + 1)
						arr1[j + 1] += arr2[j];
				}
			}

			token = 0;
		}

	}

	if (token == 0)
	{
		for (int i = 1; i < under + second + 1; i++)
		{
			result += arr1[i];
		}
	}

	else
		for (int i = 1; i < under + second + 1; i++)
		{
			result += arr2[i];
		}

	cout << result;
}
