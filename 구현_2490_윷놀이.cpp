#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	char result[3];
	int input[4];

	for (int i = 0; i < 3; i++)
	{
		int num = 0;

		for (int j = 0; j < 4; j++)
		{
			cin >> input[j];

			if (input[j] == 1)
				num++;
		}

		if (num == 1)
			result[i] = 'C';

		else if (num == 2)
			result[i] = 'B';

		else if (num == 3)
			result[i] = 'A';

		else if (num == 4)
			result[i] = 'E';

		else
			result[i] = 'D';
	}

	for (int i = 0; i < 3; i++)
	{
		cout << result[i] << endl;
	}
}
