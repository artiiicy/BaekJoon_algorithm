/*
<수학>
이항계수 정의 + 페르마의 소정리 사용
*/

#include <iostream>
#include <algorithm>

#define P 1000000007
#define size 4000000

using namespace std;

long long fac[size + 1];
long long invFac[size + 1];

long long power(long long x, long long y) {
	long long result = 1;
	while (y > 0) {
		if (y % 2) {
			result *= x;
			result %= P;
		}
		x *= x;
		x %= P;
		y /= 2;
	}
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long N, K;
	long long result;
	cin >> N >> K;

	if (N == K || !K)
	{
		cout << 1;
		return 0;
	}

	// initialize fac array
	fac[1] = 1;
	for (int i = 2; i < 4000000 + 1; i++)
	{
		fac[i] = (fac[i - 1] * i) % P;
	}

	// initialize invFac array using [  1 / N! = (N + 1) / (N + 1)!  ]
	invFac[4000000] = power(fac[4000000], P - 2);

	for (int i = 4000000 - 1; i > 0; i--)
	{
		invFac[i] = ((i + 1) * invFac[i + 1]) % P;
	}

	result = (fac[N] * invFac[N - K]) % P;
	result = (result * invFac[K]) % P;
	
	cout << result;
}
