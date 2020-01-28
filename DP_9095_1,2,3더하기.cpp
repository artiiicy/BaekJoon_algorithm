/*
BackJoon #9095 1,2,3더하기
#DP #다이나믹 프로그래밍

전형적인 Bottom-Up문제.
작은 크기의 문제를 해결하여 큰 문제를 해결하는 방법으로 메모아이제이션을 함께 써서 푼다.
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin >> T;
	vector <int> input(T, 0);

	for (int i = 0; i < T; i++)
		cin >> input[i];

	vector <int> dp(11, 0);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i < 11; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

	for(int i=0; i<T; i++)
		cout << dp[input[i]] << endl;
}
