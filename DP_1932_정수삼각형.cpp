#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b) { return a > b ? a : b; }

int main()
{
	int n, result;
	cin >> n;	//size of triangle

	vector <vector <int> > w(n, vector<int>(n, 0));
	vector <vector <int> > dp(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
	{
		for(int j = 0; j < i + 1; j++)
			cin >> w[i][j];
	}

	dp[0][0] = w[0][0];

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			if (j == 0)
				dp[i][j] = dp[i - 1][j] + w[i][j];

			else if (j == i)
				dp[i][j] = dp[i - 1][j - 1] + w[i][j];

			else
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + w[i][j];
		}
	}

	result = dp[n - 1][0];

	for (int i = 1; i < n; i++)
		result = max(result, dp[n - 1][i]);

	cout << result;
}
