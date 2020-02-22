/*
BaekJoon #2110 공유기 설치
#이분탐색 #BinarySearch

<ADT>
***구하고자 하는 것 : 공유기의 최대 거리. 따라서 거리 초기설정 해주고 이 거리를 조정해 나갈 필요가 있다.

거리의 초기설정 : min = 1, max = 가장 떨어져 있는 집간의 거리

max부터 시작해서 각 집간의 거리가 max 이상으로 떨어져있으면 공유기를 설치한다.
모두 설치 후 설치된 공유기의 개수와 실제로 설치해야할 공유기 개수를 비교하여
공유기 설치 거리를 조정한다. (설치한 공유기 수가 많으면 거리를 늘리고 적으면 거리를 줄인다.)

이때, 거리 조정하는 방법으로 시간초과가 발생하지 않게 이진탐색(Binary Search)를 사용한다.



<오답노트>
high를 초기화 해주는 과정에서 vector.end() - vector.begin()을 써줬는데 이는 반복자 즉, iterator라서 내가 저장하고자 하는 벡터의 맨 앞의 값, 맨 뒤의 값이 오지 않는다.
따라서 vector.front()와 vector.back()을 써주어야 했다.

추가로 이분탐색에서의 while문 조건을 'low < high'가 아닌 'low <= high'로 해주어야했다.
배열 탐색과정을 손으로 그리면서 직접 따라가보네 < 로 해줬을 경우에 탐색하지 않는 idx가 생겼기 때문이다.

*** 해결법을 알아냈다고 해도 흥분하지말고 한 번 더 검증하는 과정을 거치는 습관을 기르자 ***
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int num_of_house, router;
	cin >> num_of_house >> router;
	vector <int> house(num_of_house);

	for (int i = 0; i < num_of_house; i++)
		cin >> house[i];

	sort(house.begin(), house.end());

	int low = 1, high = house.back() - house.front(), mid, result = 0;

	while (low <= high)
	{
		mid = (low + high) / 2;	//mid에 공유기 간의 거리를 저장할 것임.
		int before = 0;	//공유기를 설치할 집의 직전에 설치했던 집의 idx를 저장할 변수. 처음엔 공유기 설치한 첫번째 집의 idx (= 0)로 초기화.
		int cnt = 1;	//설치된 공유기의 수. 맨 앞의 집에는 공유기가 설치되어 있다고 가정했으므로 1로 초기화.

		for (int i = 1; i < num_of_house; i++)
		{
			if (house[i] - house[before] >= mid)	//가장 최근에 공유기 설치한 집과의 거리가 mid 보다 크거나 같은 모든집에 공유기 설치.
			{
				cnt++; //공유기 설치
				before = i;	//가장 최근에 공유기 설치한 집 최신화.
			}
		}

		if (cnt >= router)
		{
			low = mid + 1;
			if (result < mid)
				result = mid;
		}

		else
		{
			high = mid - 1;
		}
	}

	cout << result;
}
