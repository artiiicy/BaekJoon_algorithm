#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T, N, M;
	cin >> T;
	vector <int> result(T, 0);

	for(int i=0; i<T; i++)
	{
		cin >> N >> M;

		int start, end;
		for (int i = 0; i < M; i++)
			cin >> start >> end;

		result[i] = N - 1;
	}

	for (int i = 0; i < T; i++)
		cout << result[i] << endl;
}
