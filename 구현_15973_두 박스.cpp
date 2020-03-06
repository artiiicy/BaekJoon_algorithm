#include <iostream>

using namespace std;

struct point
{
	int x;
	int y;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	point rect1[2];
	point rect2[2];

	for (int i = 0; i < 2; i++)
	{
		cin >> rect1[i].x;
		cin >> rect1[i].y;
	}

	for (int i = 0; i < 2; i++)
	{
		cin >> rect2[i].x;
		cin >> rect2[i].y;
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (rect1[i].x == rect2[j].x)	//세로 변이 겹칠 때
			{
				if (i == j)	//같은 쪽 세로 변이 겹칠 때
				{
					if ((rect1[1].y > rect2[0].y && rect1[1].y <= rect2[1].y) || (rect2[1].y > rect1[0].y && rect2[1].y <= rect1[1].y)) {
						cout << "FACE";
						return 0;
					}

					else if (rect1[1].y < rect2[0].y || rect1[0].y > rect2[1].y)
					{
						cout << "NULL";
						return 0;
					}
				}
				
				else	//다른 쪽 세로 변이 겹칠 때
				{
					if ((rect1[1].y > rect2[0].y && rect1[1].y <= rect2[1].y) || (rect2[1].y > rect1[0].y && rect2[1].y <= rect1[1].y)) {
						cout << "LINE";
						return 0;

					}

					else if (rect1[1].y < rect2[0].y || rect1[0].y > rect2[1].y)
					{
						cout << "NULL";
						return 0;
					}

					else if (rect1[1].y == rect2[0].y || rect1[0].y == rect2[1].y)
					{
						cout << "POINT";
						return 0;
					}
				}
			}

			else if (rect1[i].y == rect2[j].y)	//가로 변이 겹칠 때
			{
				if (i == j)	//같은 쪽 가로 변이 겹칠 때
				{
					if ((rect1[1].x > rect2[0].x && rect1[1].x <= rect2[1].x) || (rect2[1].x > rect1[0].x && rect2[1].x <= rect1[1].x)) {
						cout << "FACE";
						return 0;
					}

					else if (rect1[1].x < rect2[0].x || rect1[0].x > rect2[1].x)
					{
						cout << "NULL";
						return 0;
					}
				}

				else	//다른 쪽 가로 변이 겹칠 때
				{
					if ((rect1[1].x > rect2[0].x && rect1[1].x <= rect2[1].x) || (rect2[1].x > rect1[0].x && rect2[1].x <= rect1[1].x)) {
						cout << "LINE";
						return 0;
					}

					else if (rect1[1].x < rect2[0].x || rect1[0].x > rect2[1].x)
					{
						cout << "NULL";
						return 0;
					}
					
					else if (rect1[1].x == rect2[0].x || rect1[0].x == rect2[1].x)
					{
						cout << "POINT";
						return 0;
					}
				}
			}
		}
	}


	if (rect1[0].x < rect2[1].x && rect1[0].x > rect2[0].x)
	{
		if ((rect1[0].y < rect2[1].y && rect1[0].y > rect2[0].y) || (rect1[1].y < rect2[1].y && rect1[1].y > rect2[0].y) || (rect1[1].y > rect2[0].y && rect1[0].y < rect2[1].y))
		{
			cout << "FACE";
			return 0;
		}
	}

	if (rect1[1].x > rect2[0].x && rect1[1].x < rect2[1].x)
	{
		if ((rect1[0].y < rect2[1].y && rect1[0].y > rect2[0].y) || (rect1[1].y < rect2[1].y && rect1[1].y > rect2[0].y) || (rect1[1].y > rect2[0].y && rect1[0].y < rect2[1].y))
		{
			cout << "FACE";
			return 0;
		}
	}

	if (rect2[0].x < rect1[1].x && rect2[0].x > rect1[0].x)
	{
		if ((rect2[0].y < rect1[1].y && rect2[0].y > rect1[0].y) || (rect2[1].y < rect1[1].y && rect2[1].y > rect1[0].y) || (rect2[1].y > rect1[0].y && rect2[0].y < rect1[1].y))
		{
			cout << "FACE";
			return 0;
		}
	}

	if (rect2[1].x > rect1[0].x && rect2[1].x < rect1[1].x)
	{
		if ((rect2[0].y < rect1[1].y && rect2[0].y > rect1[0].y) || (rect2[1].y < rect1[1].y && rect2[1].y > rect1[0].y) || (rect2[1].y > rect1[0].y && rect2[0].y < rect1[1].y))
		{
			cout << "FACE";
			return 0;
		}
	}

	cout << "NULL";
}
