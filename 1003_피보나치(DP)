#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T;
	cin >> T;

	vector <int> num_N(T, 0);

	for (int i = 0; i < T; i++)
	{
		cin >> num_N[i];
	}

	vector <vector<int> > dp(41, vector<int>(2, -1));

	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[1][0] = 0;
	dp[1][1] = 1;

	for (int i = 0, j = 2; i < T; i++)
	{
		if (dp[num_N[i]][0] == -1 && dp[num_N[i]][1] == -1)	//if the first visit, fill the dp array.
		{
			for (; j < num_N[i]+1; j++)
			{
				dp[j][0] = dp[j - 1][0] + dp[j - 2][0];
				dp[j][1] = dp[j - 1][1] + dp[j - 2][1];
			}
		}
	}

	for (int i = 0; i < T; i++)
	{
		cout << dp[num_N[i]][0] << " " << dp[num_N[i]][1] << endl;
	}

	return 0;
}
