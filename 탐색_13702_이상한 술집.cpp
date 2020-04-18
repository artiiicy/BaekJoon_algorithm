/*
BaekJoon #13702 이상한 술집

<오답노트>
1. 정답값을 전체 술 / 사람수 로 초기 설정한 후 이 값에서 1씩 뺴가며 조건에 부합하는지 확인하여 부합 시 정답으로 출력. -> 시간초과
2. 1을 발전시켜봄. 정답추정값으로 각 주전자의 값들을 나눈 나머지가 가장 큰 주전자를, 마시는 사람들의 수를 1 증가 시킨 후 이로 나눈 값을 정답값 수정 -> 시간초과
3. 다른 아이디어가 생각나지 않아 구글링 -> 이분탐색..
*/

/*
#include <iostream>
#include <algorithm>

using namespace std;
int input[1000001];

void equal(int & result, int kettle, int people)
{
	int temp_p = 0, temp_i, temp_k = 0;

	while (1)
	{
		for (int i = 0; i < kettle; i++)
		{
			temp_p += input[i] / result;
	
			if (temp_k < input[i] % result)
			{
				temp_k = input[i] % result;
				temp_i = i;
			}
		}

		if (temp_p == people)
			return;

		else
		{
			
			result = input[temp_i] / ((input[temp_i] / result) + 1);
			temp_p = 0;
			temp_k = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int kettle, people, result = 0;

	cin >> kettle >> people;

	for (int i = 0; i < kettle; i++)
	{
		cin >> input[i];
		result += input[i];
	}

	result /= people;

	equal(result, kettle, people);
	cout << result;
}*/

#include <iostream>
#include <algorithm>

using namespace std;
int input[1000001];

void binary(int low, int high, int people, int kettle)
{
	int cnt = 0;	//cnt : 마실 수 있는 사람의 수
	int mid = (low + high) / 2;

	while (low <= high)
	{
		for (int i = 0; i < kettle; i++)
		{
			cnt += input[i] / mid;
		}

		if (cnt < people)
			high = mid - 1;

		else	//cnt가 people과 동일하더라도 하한값 올려서 최대의 값 구한다.
			low = mid + 1;


		mid = (low + high) / 2;
		cnt = 0;

	}

	cout << mid;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int kettle, people, result = 0;
	int low = 0, high = 0;

	cin >> kettle >> people;

	for (int i = 0; i < kettle; i++)
	{
		cin >> input[i];
		high = max(high, input[i]);
	}

	binary(low, high, people, kettle);
}
