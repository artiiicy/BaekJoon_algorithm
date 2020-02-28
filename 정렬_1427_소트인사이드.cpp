#include <iostream>
#include <algorithm>

using namespace std;

int arr[10];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int input;

	cin >> input;

	int i = 0;
	for (; i < 10; i++)
	{
		if (input <= 0)
			break;

		arr[i] = input % 10;
		input /= 10;
	}

	sort(arr, arr + i, greater<int>());

	for (int j = 0; j < i; j++)
		cout << arr[j];
}
