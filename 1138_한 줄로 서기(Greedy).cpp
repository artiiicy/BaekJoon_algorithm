#include <iostream>

using namespace std;

int input[11];
int output[11];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> input[i];
	}

	for (int i = 0; i < N; i++)
	{
		int cnt = input[i];

		for (int j = 0; j < N; j++)
		{
			if (cnt == 0 && output[j] == 0)
			{
				output[j] = i + 1;
				break;
			}

			else if(output[j] > i + 1 || output[j] == 0)
			{
				cnt--;
			}
		}
	}

	for (int i = 0; i < N; i++)
		cout << output[i] << " ";
}
