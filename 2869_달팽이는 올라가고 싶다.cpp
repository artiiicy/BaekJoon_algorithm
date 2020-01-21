#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int up, down, height, result;

	cin >> up >> down >> height;



	height -= up;

	result = height / (up - down);
	
	if (height % (up - down) != 0)
		result += 1;

	cout << result + 1;
}
