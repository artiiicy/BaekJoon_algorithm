/*
BaekJoon #2839 설탕 배달

배열의 모든 원소를 특정값으로 초기화 하는 방법 : fill_n 함수를 사용한다.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int sugar[5002];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	fill_n(sugar, 5002, -1);

	int N;
	cin >> N;

	sugar[3] = 1;
	sugar[5] = 1;

	for (int i = 3; i <= N; i++)
	{
		if (sugar[i] != -1)
		{
			if (i + 3 <= N)
			{
				if (sugar[i + 3] == -1)
					sugar[i + 3] = sugar[i] + 1;
				else
					sugar[i + 3] = min(sugar[i + 3], sugar[i] + 1);
			}

			if(i + 5 <= N)
			{
				if (sugar[i + 5] == -1)
					sugar[i + 5] = sugar[i] + 1;
				else
					sugar[i + 5] = min(sugar[i + 5], sugar[i] + 1);
			}
		}
	}

	cout << sugar[N];
}
