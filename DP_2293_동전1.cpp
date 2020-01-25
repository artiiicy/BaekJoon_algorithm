/*
BackJoon #2293 동전1
#DP #다이나믹 프로그래밍

살짝 고난이도의 메모아이제이션을 요구한 문제.
메모리 제한이 4MB이므로 int형 배열 약 백만개를 할당 받을 수 있으므로 메모리가 초과되지 않게 하는 것이 관건인 문제.

*** 오답노트
벡터 컨테이너의 시작과 끝 : v.begin(), v.end()로 나타낼 수 있음.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	vector <int> input(n);
	vector <int> dp(k + 1, 0);

	for (int i = 0; i < n; i++)
		cin >> input[i];

	sort(input.begin(), input.end());


	for (int i = 0; i < n; i++)
	{
		for (int j = input[i]; j < k + 1; j++)
		{
			if (j == input[i])
				dp[j] += 1;

			else
				dp[j] += dp[j - input[i]];
		}
	}

	cout << dp[k];
}
