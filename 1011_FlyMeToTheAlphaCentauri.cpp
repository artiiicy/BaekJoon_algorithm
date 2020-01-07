/*
FeedBack

1. 규칙을 먼저 찾자. 찾았으면 사람처럼 생각하지말고 컴퓨터가 어떤식으로 계산해야할지 고민하면서 코드 짤 것.
2. 입력의 최댓값이 2^31-1. 즉, int의 최대허용 정수값이나 컴파일러마다 다르므로 long long을 사용해야만 했다.
*/



#include <iostream>

using namespace std;

int main()
{
	int T;	//num of TestCase
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		long long x, y;
		cin >> x >> y;

		int result = 0;
		long long dist = y - x;

		if (dist < 2)
			result = 1;

		else
		{
			for (long long a = 1; ; a++)	//46341 : 2^31의 제곱근
			{
				if (a*a < dist && dist <= (a + 1)*(a + 1))
				{
					if (dist <= (a + 1)*(a + 1) - (a + 1))
						result = 2 * a;

					else
						result = 2 * a + 1;

					break;
				}
			}
		}

		cout << result << endl;
	}
}
