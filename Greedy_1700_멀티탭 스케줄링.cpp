/*
<ADT>
처음엔 단순히 앞으로 나올 숫자들의 개수를 파악해 제일 적게 나온것을 교체하려 했으나
1 2 3 4 2 3 2 4 1 1 1 1 1 1 1 과 같은 경우에 1이 빈도가 제일 큼에도 불구하고 교체해주어야
최소가 나온다. 따라서 플러그에 꽂혀있는 것들 중 가장 늦게나오는 것을 교체해주는 방식으로 해결하였다.
*/

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
