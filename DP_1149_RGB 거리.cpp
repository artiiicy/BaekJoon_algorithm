#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b) { return a > b ? b : a; }

int main()
{
	int N;	//num of house
	cin >> N;

	vector <vector <int> > w(N, vector<int>(3));
	vector <vector <int> > dp(3, vector<int>(N));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++)
			cin >> w[i][j];

	for (int i = 0; i < 3; i++)
		dp[i][0] = w[0][i];

	for (int i = 1; i < N; i++)
	{
		dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + w[i][0];
		dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + w[i][1];
		dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]) + w[i][2];
	}

	int result = min(dp[0][N - 1], dp[1][N - 1]);
	result = min(result, dp[2][N - 1]);

	cout << result << endl;
}
