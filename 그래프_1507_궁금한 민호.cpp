#include <iostream>
#include <algorithm>

using namespace std;

int city[20][20];
int result[20][20];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, sum = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> city[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				continue;
			int temp = 100000;

			for (int k = 0; k < n; k++) {
				if (k == j || !city[i][k])
					continue;

				temp = min(city[i][k] + city[k][j], temp);
			}

			if (temp > city[i][j])
				result[i][j] = city[i][j];
			else if (temp < city[i][j]) {
				cout << "-1";
				return 0;
			}
		}
	}


	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			sum += result[i][j];

	cout << sum / 2;
}
