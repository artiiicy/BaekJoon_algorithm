#include <iostream>
#include <algorithm>

using namespace std;

int n, k, cnt, result;
bool plug[101];
bool check[101];
int todo[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	for (int i = 1; i < k + 1; i++) {
		cin >> todo[i];
	}

	for (int i = 1; i < k + 1; i++) {
		if (plug[todo[i]] == true) {	// 이미 꽂혀있는 경우
			continue;
		}
		else {
			if (cnt < n) {	// 안꽂혀있지만 꽂을 수 있는 경우
				plug[todo[i]] = true;
				cnt++;
			}
			else {	// 안꽂혀있고 이미 꽉 찬 경우
				for (int a = 1; a < k + 1; a++)
					check[a] = false;
				int checkCnt = 0;
				int change = 0;

				for (int j = i + 1; j < k + 1; j++) {
					if (plug[todo[j]] == true && check[todo[j]] == false) {
						check[todo[j]] = true;
						checkCnt++;
					}

					if (checkCnt == cnt - 1 || j == k) {	// 꽂혀있는애들 중에서 check 0인 애 추방
						for (int l = 1; l < k + 1; l++) {
							if (plug[l] == true && check[l] == false) {
								plug[l] = false;
								plug[todo[i]] = true;
								result++;
								change = 1;
								break;
							}
						}
						break;
					}
				}

				if (change == 0) {
					for (int l = 1; l < k + 1; l++) {
						if (plug[l] == true) {
							plug[l] = false;
							plug[todo[i]] = true;
							result++;
							change = 1;
							break;
						}
					}
				}
			}
		}
	}

	cout << result;
}
