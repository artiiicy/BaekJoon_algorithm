#include <iostream>
#include <algorithm>

using namespace std;

int dp[50001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	dp[1] = 1;

	for (int i = 2; i < n + 1; i++) {
		int temp, m = 50000;
		for (int j = 1; j * j <= i; j++) {
			temp = i - (j * j);
			m = min(dp[temp] + 1, m);
		}
		dp[i] = m;
	}

	cout << dp[n];
}
