/*
<오답노트>
시간초과가 뜰거란 것을 예상했으나 pruning을 잘하면 될 거라는 기대를 품고 Back Tracking으로 풀었다가 오답.
+a) 반복문에서 dpArr의 col을 넘어가도록 설정하면 컴파일에러(out of range)가 뜨는 것이 아닌 틀렸습니다가 뜬다.

<ADT>
Cost별로 최대로 사용할 수 있는 Byte를 뽑아내자는 생각을 얼핏 했으나 이를 DP로 이끌어 내기까진 못해 결국 구글링...

접근은 좋았으나 DP의 핵심을 도출해 내지 못했는데 Key는 각 어플을 끄고 키는 두 가지 경우에 따라 DP를 구현하는 것.

*/

#include <iostream>
#include <algorithm>

using namespace std;

struct apps {
	int byte;
	int cost;
};

int numOfApp, needByte;
struct apps app[100];
int dpArr[100][10001];	// row : n번째 어플을 의미, col : cost를 의미, value : row번까지의 어플들을 이용했을 때 col만큼의 cost에서의 최대 Byte.

bool compare(const struct apps& a, const struct apps& b)
{
	return a.cost < b.cost;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int result = 100000;
	cin >> numOfApp >> needByte;
	for (int i = 0; i < numOfApp; i++)
		cin >> app[i].byte;

	for (int i = 0; i < numOfApp; i++)
		cin >> app[i].cost;

	sort(app, app + numOfApp, compare);

	dpArr[0][app[0].cost] = app[0].byte;
	
	for (int i = 1; i < numOfApp; i++)
	{
		for (int j = 0; j < 10001; j++)
		{
			if (j >= app[i].cost)	// 해당 어플을 꺼서 취득할 수 있는 cost라면 어플을 껐을 경우를 계산한다
				dpArr[i][j] = dpArr[i - 1][j - app[i].cost] + app[i].byte;

			dpArr[i][j] = max(dpArr[i][j], dpArr[i - 1][j]);	// 해당 어플을 계속 켜놨을 때의 byte와 비교한다

			if (dpArr[i][j] >= needByte)
				result = min(result, j);
		}
	}

	cout << result;
}
