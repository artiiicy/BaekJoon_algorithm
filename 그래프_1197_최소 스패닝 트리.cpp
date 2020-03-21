/*
<오답노트>
바보처럼 sorting을 하지않고 구현.. + 노드는 1번부터인데 parent 배열 0번부터 사용하였음
*/

#include <iostream>
#include <algorithm>

using namespace std;

struct graph {
	int v1, v2, cost;
};

int V, E;
int parent[100001];
long long result;
bool chk;
graph g[100001];

bool cmp(const graph& a, const graph& b) {
	return a.cost < b.cost;
}

int find(int v) {
	if (parent[v] == v)
		return v;

	return parent[v] = find(parent[v]);
}

void merge(int v1, int v2) {
	chk = false;

	v1 = find(v1);
	v2 = find(v2);

	if (v1 == v2)
		return;
	else {
		chk = true;
		parent[v1] = v2;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V >> E;

	for (int i = 0; i < E; i++)
		cin >> g[i].v1 >> g[i].v2 >> g[i].cost;

	sort(g, g + E, cmp);

	for (int i = 1; i < V + 1; i++)
		parent[i] = i;

	for (int i = 0; i < E; i++) {
		merge(g[i].v1, g[i].v2);

        if (chk == true)
			result += g[i].cost;
	}

	for (int i = 1; i < V; i++) {
		if (find(i) != find(i + 1)) {
			result = 0;
			break;
		}
	}
	
	cout << result;
}
