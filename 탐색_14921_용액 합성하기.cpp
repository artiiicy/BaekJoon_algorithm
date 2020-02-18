/*
BaekJoon #14921 용액 합성하기

<ADT>
오름차순으로 정렬되어 data가 들어오기 때문에 음수 부분과 양수 부분으로 나누어 한쪽을 기준 삼아 반대쪽을 이분탐색을 통하여 기준값과 더했을 때 가장 0에 가까운 값,
즉, 기준값의 절댓값과 반대쪽값의 절댓값이 가장 비슷한 값을 찾는다.

단, 데이터가 모두 양수이거나 음수이면 따로 예외처리를 해준다.

1. 음수와 양수 분단점을 찾는다.
2. 모두 음수 혹은 모두 양수라면 예외처리를 해준다 (모두 음수 -> 인덱스 가장 큰 2개, 모두 양수 -> 인덱스 가장 작은 2개)
3. 음수부와 양수부 중 더 작은 부분을 기준점으로 삼고 반대쪽을 이분탐색으로 탐색한다.
4. 제일 큰 음수 2개와 제일 작은 양수 2개를 각각 더한 값들이 정답일 경우가 있으므로 이를 예외처리 해준다.
*/


#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int input[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, zero=0, low, high, mid, result;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> input[i];

	if (input[0] < 0 && input[n - 1] < 0)
	{
		cout << input[n - 1] + input[n - 2];
		return 0;
	}

	else if (input[0] >= 0 && input[n - 1] >= 0)
	{
		cout << input[0] + input[1];
		return 0;
	}


	//음수, 양수 경계지점 idx찾기
	low = 0, high = n - 1;

	while (low <= high)
	{
		mid = (low + high) / 2;

		if (input[mid] >= 0)
		{
			if (input[mid - 1] >= 0)
				high = mid - 1;

			else
			{
				zero = mid;
				break;
			}

		}

		else
		{
			if (input[mid + 1] < 0)
				low = mid + 1;

			else
			{
				zero = mid + 1;
				break;
			}
		}
	}

	result = input[0] + input[n - 1];

	if (zero - 1 < n - zero)	//음수가 더 적을때
	{
		for (int i = 0; i < zero; i++)
		{
			int low = zero, high = n - 1;
			while (low <= high)
			{
				int mid = (low + high) / 2;

				if (input[mid] <= -input[i])
				{
					low = mid + 1;
					result = abs(result) < abs(input[mid] + input[i]) ? result : input[mid] + input[i];
				}

				else
				{
					high = mid - 1;
					result = abs(result) < abs(input[mid] + input[i]) ? result : input[mid] + input[i];
				}
			}
		}
	}
	
	else	//양수가 더 적을때
	{
		for (int i = zero; i < n; i++)
		{
			int low = 0, high = zero - 1;
			while (low <= high)
			{
				int mid = (low + high) / 2;

				if (input[mid] <= -input[i])
				{
					low = mid + 1;
					result = abs(result) < abs(input[mid] + input[i]) ? result : input[mid] + input[i];
				}

				else
				{
					high = mid - 1;
					result = abs(result) < abs(input[mid] + input[i]) ? result : input[mid] + input[i];
				}
			}
		}
	}

	//양수 혹은 음수 값들로만 이루어진 정답이 있을 경우
	if (zero + 1 < n && abs(result) > abs(input[zero] + input[zero + 1]))
		result = input[zero] + input[zero + 1];

	else if (zero - 2 >= 0 && abs(result) > abs(input[zero - 1] + input[zero - 2]))
		result = input[zero - 1] + input[zero - 2];

	cout << result;
}
