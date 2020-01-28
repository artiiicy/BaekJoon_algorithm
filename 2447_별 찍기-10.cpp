/*
<ADT>
전역변수를 사용하여 0으로 초기화된 배열에 뚫릴 부분만 1로 체크해준 후
출력할 때 0이면 *을, 1이면 공백을 출력한다.
*/

#include <iostream>

using namespace std;

int arr[2187][2187];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int input;
	cin >> N;
	input = N;

	while (N / 3)
	{
		int idx = N / 3;

		for (int idx_row = idx; idx_row < input; idx_row += (idx * 3))
			for (int idx_col = idx; idx_col < input; idx_col += (idx * 3))
				for (int i = idx_row; i < idx_row + idx; i++)
					for (int j = idx_col; j < idx_col + idx; j++)
						arr[i][j] = 1;

		N /= 3;
	}

	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < input; j++)
		{
			if (arr[i][j] == 0)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
}
