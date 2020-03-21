#include <iostream>

using namespace std;

struct graph{
	int v1, v2, cost;
};

int N, M, K;
bool check;
int parent[1001];
struct graph g[600000];

int find(int vertex) {
	// 부모노드를 찾으면 반환
	if (vertex == parent[vertex])
		return vertex;

	// 찾지못했으면 현재 노드의 부모노드를 따라 이동
	return parent[vertex] = find(parent[vertex]);
}

void merge(int v1, int v2) {
	check = false;

	v1 = find(v1);
	v2 = find(v2);

	// 루트노드가 같으면(싸이클을 형성하면) check : false
	if (v1 == v2)
		return;
	// 싸이클을 형성하지 않으면 합병, check : true
	else if (v1 > v2)
		parent[v1] = v2;
	else
		parent[v2] = v1;

	check = true;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int start = 1;
	cin >> N >> M >> K;

	// 그래프 입력받기
	for (int i = 1; i < M + 1; i++) {
		cin >> g[i].v1 >> g[i].v2;
		g[i].cost = i;
	}


	while (K) {
		int cnt = 1;
		int result = 0;

		// 각 노드의 부모노드 초기화
		for (int i = 1; i < N + 1; i++)
			parent[i] = i;

		// MST
		for (int i = start; i < M + 1; i++) {
			merge(g[i].v1, g[i].v2);

			if (check == true)
				result += g[i].cost;
		}

		for (int i = 1; i < N; i++) {
			if (find(i) != find(i + 1)) {
				result = 0;
				break;
			}
		}

		// 결과 출력
		if (result == 0) {
			while (K) {
				cout << 0 << " ";
				K--;
			}
			return 0;
		}
		else
			cout << result << " ";
		K--;
		start++;
	}
}
