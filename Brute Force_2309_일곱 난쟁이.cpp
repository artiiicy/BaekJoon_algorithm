/*
BaekJoon #2309  일곱 난쟁이
#브루트포스 #BruteForce

<오답노트>
되는 경우 찾으면 끝내야하는데 되는 경우 모두 출력해서 틀림.

*/

#include <iostream>
#include <algorithm>

#define MAX 9
using namespace std;

int dwarf[9];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < MAX; i++)
		cin >> dwarf[i];

	sort(dwarf, dwarf + 9);

	for (int i = 0; i < MAX; i++)
	{
		int temp1 = dwarf[i];
		dwarf[i] = 0;

		for (int j = i + 1; j < MAX; j++)
		{
			int temp2 = dwarf[j];
			dwarf[j] = 0;

			int sum = 0;

			for (int k = 0; k < MAX; k++)
				sum += dwarf[k];

			if (sum == 100)
			{
				for (int k = 0; k < MAX; k++)
				{
					if (dwarf[k] != 0)
						cout << dwarf[k] << endl;
				}
				return 0;
			}
			dwarf[j] = temp2;
		}

		dwarf[i] = temp1;
	}
}
