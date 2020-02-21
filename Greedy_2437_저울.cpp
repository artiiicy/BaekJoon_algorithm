#include <iostream>
#include <algorithm>

using namespace std;

int scale[1000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int num, ans = 1;
	cin >> num;

	for (int i = 0; i < num; i++)
		cin >> scale[i];

	sort(scale, scale + num);

	for (int i = 0; i < num; i++)
	{
		if (ans < scale[i])
			break;
		ans += scale[i];
	}
	cout << ans;
}
