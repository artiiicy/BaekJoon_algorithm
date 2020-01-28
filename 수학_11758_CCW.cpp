/*
2020.01.20

<ADT>
- 일직선인 경우를 맨 처음에 예외처리 해준 후 방향을 살펴 결과 도출.
- 방향을 살피는 것은 p3가 p1, p2로 이루어진 직선의 위에 있는지 아래에 있는지 살핌으로써 해결할 수 있다.

<오답노트>
- 런타임에러 : 0으로 나누는 경우를 예외처리하지 않아서 런타임 에러 발생.

- 오답원인 : 정밀도 문제로 인하여 오답. 한 직선에 존재하는 경우를 기울기 뿐만 아니라 y절편도 비교했었는데 이 과정에서
double이 포용하는 정밀도를 넘어가는 y절편끼리 비교하는 과정에서 정밀도 miss가 발생해 오답이 발생했다.
그런데 y절편을 비교하는 과정은 불필요했다. 왜냐하면 p2 점이 겹치며 기울기가 같다면 y절편이 같지 않아도 이미 같은 직선이기 때문이다.
따라서 y절편에 해당하는 코드를 지우고 완성하였다.
*/

#include <iostream>

using namespace std;

#define clock -1
#define rev_clock 1
#define line 0

double incline1, incline2;
double y_intercept1, y_intercept2;

struct Point {
	double x;
	double y;
};

bool isLine(struct Point P1, struct Point P2, struct Point P3)
{
	if (P1.x == P2.x)
	{
		if (P3.x == P1.x)
			return true;
		else
			return false;
	}
	else
	{
		incline1 = (P1.y - P2.y) / (P1.x - P2.x);
	}

	if (P2.x == P3.x)
	{
		if (P1.x == P2.x)
			return true;
		else
			return false;
	}
	else
	{
		incline2 = (P2.y - P3.y) / (P2.x - P3.x);
	}

	y_intercept1 = P1.y - (incline1 * P1.x);
	y_intercept2 = P2.y - (incline2 * P2.x);

	if (incline1 == incline2)
		return true;
	else
		return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (1)
	{
		struct Point P1, P2, P3;

		cin >> P1.x >> P1.y >> P2.x >> P2.y >> P3.x >> P3.y;

		if (isLine(P1, P2, P3))	// 일직선상인 경우
		{
			cout << line;
			return 0;
		}
		else if (P1.x == P2.x)	// 일직선상이 아니고 p1의 x좌표가 p2의 x좌표와 같은 경우
		{
			if (P1.y > P2.y)
			{
				if (P3.x > P1.x)
				{
					cout << rev_clock;
					return 0;
				}

				else
				{
					cout << clock;
					return 0;
				}
			}
			else
			{
				if (P3.x > P1.x)
				{
					cout << clock;
					return 0;
				}

				else
				{
					cout << rev_clock;
					return 0;
				}
			}
		}
		else if (P1.x < P2.x)	// p1가 p2보다 왼쪽에 위치한 경우
		{
			if (P3.y > ((incline1 * P3.x) + y_intercept1))	// p3가 p1, p2로 이루어진 직선의 위에 있는 경우
			{
				cout << rev_clock;
				return 0;
			}
			else	// p3가 p1, p2로 이루어진 직선의 아래에 있는 경우
			{
				cout << clock;
				return 0;
			}
		}
		else	// p1가 p2보다 오른쪽에 위치한 경우
		{
			if (P3.y > ((incline1 * P3.x) + y_intercept1))	// p3가 p1, p2로 이루어진 직선의 위에 있는 경우
			{
				cout << clock;
				return 0;
			}
			else	// p3가 p1, p2로 이루어진 직선의 아래에 있는 경우
			{
				cout << rev_clock;
				return 0;
			}
		}
	}
}
