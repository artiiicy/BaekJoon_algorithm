#include <iostream>

using namespace std;

char input[1000001];

int main()
{
	int valid = 0, count = 0;

	cin.getline(input, 1000001);

	for (int i = 0; input[i] != 0; i++)
	{
		if (isalpha(input[i]) && valid == 0)
		{
			valid = 1;
		}

		else if (input[i] == ' ' && valid == 1)
		{
			count++;
			valid = 0;
		}
	}

	if (valid == 1)
		count++;

	cout << count;
}
