#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int N, result;
string input;
bool alpha[26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> input;

	int nextIdx = 0;
	for (int i = 0; i < input.length(); i = nextIdx) {
		// 처음부터 끝까지 탐색
		int cnt = 0, temp_max = 0;;

		int k = i + 1;
		nextIdx = i + 1;
		while (k < input.length()) {
			if (input[k] == input[i]) {
				nextIdx = k + 1;
				k++;
			}
			else
				break;
		}

		for (int j = i; j < input.length(); j++) {
			// 현재 위치부터 끝까지 탐색하면서 N과 cnt를 비교해서 진행할 수 있는지 파악

			if (alpha[input[j] - 'a'] == true) {
				temp_max++;
				continue;
			}
			else if (cnt < N && alpha[input[j] - 'a'] == false) {
				alpha[input[j] - 'a'] = true;
				temp_max++;
				cnt++;
			}
			else {
				break;
			}
		}
		result = max(result, temp_max);

		for (int j = 0; j < 26; j++) {
			alpha[j] = false;
		}
	}
	cout << result;
}
