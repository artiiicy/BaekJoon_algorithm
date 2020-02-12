#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int abs_max(int a, int b) //finds maximum and abs
{
	if (a < 0) a *= -1;
	if (b < 0) b *= -1;
	return a > b ? a : b;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int r1, r2, c1, c2;
	cin >> r1 >> c1 >> r2 >> c2;


	int ver = r2 - r1 + 1; //new array size
	int hor = c2 - c1 + 1; //new array size

	int** arr = new int*[ver]; //allocating process
	for (int i = 0; i < ver; i++)
	{
		arr[i] = new int[hor];
		for (int j = 0; j < hor; j++)
			arr[i][j] = 0;
	}

	int x, y, count, side;
	x = y = 0;
	count = 1;
	side = 2;
	
	c1 = abs(c1);
	c2 = abs(c2);
	r1 = abs(r1);
	r2 = abs(r2);
	
	if (0 >= y + r1 && y + r2 >= 0 && 0 >= x + c1 && x + c2 >= 0) //if #1 is in the Array
		arr[y + abs(r1)][x + abs(c1)] = count;
	

	count++;
	x++;

	//compute n^2 with max(r1,c1,r2,c2) to make complete tonado array
	int max = -1;
	max = abs_max(max, r1);
	max = abs_max(max, r2);
	max = abs_max(max, c1);
	max = abs_max(max, c2);

	max *= 2;
	max += 1;

	while (side < max)
	{
		//go-up
		for (int i = 1; i <= side; i++)
		{
			if (r1 <= y && y <= r2 && c1 <= x && x <= c2)
				arr[y - r1][x - c1] = count;

			if (i != side)
			{
				y--;
				count++;
			}
		}

		//go-left
		for (int i = 1; i <= side; i++, count++)
		{
			if (r1 <= y && y <= r2 && c1 <= x && x <= c2)
				arr[y - r1][x - c1] = count;

			if (i != side) x--;
		}

		side++;
		x--;

		//go-down
		for (int i = 1; i <= side; i++)
		{
			if (r1 <= y && y <= r2 && c1 <= x && x <= c2)
				arr[y - r1][x - c1] = count;

			if (i != side)
			{
				y++;
				count++;
			}
		}

		//go-right
		for (int i = 1; i <= side; i++, count++)
		{
			if (r1 <= y && y <= r2 && c1 <= x && x <= c2)
				arr[y - r1][x - c1] = count;

			if (i != side) x++;
		}

		side++;
		x++;
	}

	//compute the maximum length in arr numbers
	int digit_max = abs_max(arr[0][0], arr[ver-1][hor-1]);
	digit_max = abs_max(arr[0][hor-1], digit_max);
	digit_max = abs_max(arr[ver-1][0], digit_max);

	int max_len = 0;

	for (; digit_max > 0; digit_max /= 10, max_len++);
	
	//print the output
	for (int i = 0; i < ver; i++)
	{
		for (int j = 0; j < hor; j++)
		{
			int num = arr[i][j];
			int num_len = 0;

			for (int k = 0; k < max_len; k++)
			{
				if (num > 0)
					num /= 10;

				else
					cout << " ";
			}
			
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}
