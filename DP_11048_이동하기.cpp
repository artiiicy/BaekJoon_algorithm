#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector <vector<int> > w;	//2차원 벡터 선언 및 초기화
	vector <vector <int> > dp(N, vector <int>(M, 0));

	for (int i = 0; i < N; i++)
	{
		vector <int> sub_w;
		sub_w.resize(M);
		w.push_back(sub_w);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> w[i][j];
	}

	dp[0][0] = w[0][0];

	for (int i = 1; i < N; i++)
		dp[i][0] = dp[i - 1][0] + w[i][0];

	for (int i = 1; i < M; i++)
		dp[0][i] = dp[0][i - 1] + w[0][i];

	for (int i = 1; i < N; i++)
		for (int j = 1; j < M; j++)
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + w[i][j];

	cout << dp[N - 1][M - 1];
}
