#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, input;
	cin >> N;

	while (N) {
		bool chk = false;
		int cnt = 2;
		cin >> input;

		while (cnt < 1000000000 && cnt <= input) {
			if (cnt == input) {
				chk = true;
				break;
			}
			cnt *= 2;
		}

		if (chk == true)
			cout << "GoHanGang" << endl;
		else
			cout << "Gazua" << endl;
		N--;
	}
}
