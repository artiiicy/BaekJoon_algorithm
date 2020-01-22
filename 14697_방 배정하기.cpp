#include <iostream>

using namespace std;

int room[400];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c, num_students;
	cin >> a >> b >> c >> num_students;

	room[a]++;
	room[b]++;
	room[c]++;

	for (int i = 1; i <= num_students; i++) {
		if (room[i] != 0) {
			room[i + a]++;
			room[i + b]++;
			room[i + c]++;
		}
	}

	if (room[num_students] == 0)
		cout << "0";
	else
		cout << "1";
}
