#include <iostream>
#include <algorithm>

using namespace std;

int n, m, c, cnt = 1, result;

struct graph {
	int v1, v2, cost;
};

bool cmp(const graph & g1, const graph & g2) {
	return g1.cost < g2.cost;
}

graph g[30000];
int check[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> c;

	for (int i = 0; i < m; i++)
		cin >> g[i].v1 >> g[i].v2 >> g[i].cost;

	sort(g, g + m, cmp);

	for (int i = 0; i < m; i++) {

		if (check[g[i].v1] == 0 && check[g[i].v2] == 0) {
			check[g[i].v1] = cnt;
			check[g[i].v2] = cnt;
			cnt++;
		}
		else if(check[g[i].v1] == 0 || check[g[i].v2] == 0) {
			if (check[g[i].v1])
				check[g[i].v2] = check[g[i].v1];
			else
				check[g[i].v1] = check[g[i].v2];
		}
		else {
			if (check[g[i].v1] == check[g[i].v2])
				continue;
			else {
				// 트리 합치기
				int temp = check[g[i].v1];
				for (int j = 1; j < n + 1; j++)
					if (check[j] == temp)
						check[j] = check[g[i].v2];
			}
		}
		result += g[i].cost;
	}
	
	cout << result + c * ((n-1) * (n-2) / 2);
}
