#include <iostream>

using namespace std;

int N, M;
int arr[200][200];
int parent[200];
int path[1000];
bool check;

int find(int v) {
	if (v == parent[v])
		return v;

	return parent[v] = find(parent[v]);
}

void merge(int v1, int v2) {
	check = false;

	v1 = find(v1);
	v2 = find(v2);

	if (v1 == v2)
		return;
	else
		parent[v1] = v2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		parent[i] = i;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				merge(i, j);
			}
		}

	for (int i = 0; i < M; i++)
		cin >> path[i];

	for (int i = 0; i < M - 1; i++) {
		if (find(path[i] - 1) != find(path[i + 1] - 1)) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}
