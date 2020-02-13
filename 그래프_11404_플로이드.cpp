#include <iostream>
#include <algorithm>

#define CITY_MAX 100
#define INF  1000000

using namespace std;

int cityArr[CITY_MAX + 1][CITY_MAX + 1];
int cityNum, busNum;
int cost, s, e;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> cityNum >> busNum;

	for (int i = 0; i < busNum; i++)
	{
		cin >> s >> e >> cost;

		if (cityArr[s][e] == 0)
			cityArr[s][e] = cost;
		else
			cityArr[s][e] = min(cityArr[s][e], cost);
	}

	for (int i = 1; i < cityNum + 1; i++)
	{
		for (int j = 1; j < cityNum + 1; j++)
		{
			if (cityArr[i][j] == 0)
				cityArr[i][j] = INF;
		}
	}

	for (int cnt = 1; cnt < cityNum; cnt++)
	{
		for (int i = 1; i < cityNum + 1; i++)
		{
			for (int j = 1; j < cityNum + 1; j++)
			{
				if (i == j)
					cityArr[i][j] = 0;
				else
					for (int k = 1; k < cityNum + 1; k++)
						cityArr[i][j] = min(cityArr[i][j], cityArr[i][k] + cityArr[k][j]);
			}
		}
	}
	

	for (int i = 1; i < cityNum + 1; i++)
	{
		for (int j = 1; j < cityNum + 1; j++)
		{
			if (cityArr[i][j] == INF)
				cout << "0 ";
			else
				cout << cityArr[i][j] << " ";
		}
		cout << endl;
	}
}
