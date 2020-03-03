#include <iostream>
#include <algorithm>

using namespace std;

struct com {
	int v1, v2, cost;
};

bool cmp(const com& c1, const com& c2) {
	return c1.cost < c2.cost;
}

int n, m, cnt = 1;
long long result;
com c[100001];
int check[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
		cin >> c[i].v1 >> c[i].v2 >> c[i].cost;

	sort(c, c + m, cmp);

	for (int i = 0; i < m; i++) {
		if (c[i].v1 == c[i].v2)
			continue;
		else if (check[c[i].v1] == 0 && check[c[i].v2] == 0) {
			check[c[i].v1] = cnt;
			check[c[i].v2] = cnt;
			cnt++;
		}
		else if (check[c[i].v1] == 0 || check[c[i].v2] == 0) {
			if (check[c[i].v1])
				check[c[i].v2] = check[c[i].v1];	
			else
				check[c[i].v1] = check[c[i].v2];
		}
		else {
			if (check[c[i].v1] == check[c[i].v2])
				continue;
			else {
				int temp = check[c[i].v1];
				for (int j = 1; j < n + 1; j++) {
					if (check[j] == temp)
						check[j] = check[c[i].v2];
				}
			}
		}
		result += c[i].cost;
	}
	
	cout << result;
}
