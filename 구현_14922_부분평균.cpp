/*
BaekJoon #14922 부분평균

<ADT>
반복문 2개로 P < K < Q 일 때, P~K, K+1~Q까지의 평균을 비교하여 최솟값을 찾으려했으나
배열이 아무리 길어도 최솟값은 4개 이상의 값들의 평균에서는 나오지 않음을 깨닫고 2, 3개의 인접 배열에서 구하는 것으로 변경.

또한, 평균이므로 long long이 아니라 double을 사용하기로 함.
*/

#include <iostream>
#include <algorithm>

using namespace std;

double input[1000001];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, result, result_idx;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> input[i];

	result = (input[0] + input[1]) / 2;
	result_idx = 0;

	//2개 짜리
	for (int i = 1; i < n - 1; i++)
	{
		double temp = (input[i] + input[i + 1]) / 2;

		if (result > temp)
		{
			result = temp;
			result_idx = i;
		}
	}

	//3개 짜리
	for (int i = 0; i < n - 2; i++)
	{
		double temp = (input[i] + input[i + 1] + input[i + 2]) / 3;

		if (result > temp)
		{
			result = temp;
			result_idx = i;
		}
	}

	cout << result_idx;
}
