/*
오답노트
1. 자음, 모음 조건 적용하지 않아서 오답
2. 백트래킹 돌릴 때, 첫 문자를 주어진 문자 전체에서 돌리지 않고 앞의 일부만 돌려서 뒤의 정답들이 짤려서 오답
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int pw_length, num_ch, count_vowel, count_con;

bool is_vowel(char input)
{
	if (input == 'a' || input == 'e' || input == 'i' || input == 'o' || input == 'u')
	{
		return 1;
	}

	else
		return 0;
}

void make_pw(vector <char> input,  vector <char> output, int input_idx, int output_idx)
{
	if (output_idx == pw_length)
		return;

	for (int i = input_idx; i < num_ch; i++)
	{
		if (is_vowel(input[i]))
			count_vowel++;
		else
			count_con++;

		output[output_idx] = input[i];

		if (output_idx == pw_length - 1)
		{
			if (count_vowel >= 1 && count_con >= 2)
			{
				for (int j = 0; j < pw_length; j++)
				{
					cout << output[j];
				}
				cout << endl;

				if (is_vowel(input[i]))
					count_vowel--;
				else
					count_con--;

				continue;
			}
			
			else
			{
				if (is_vowel(input[i]))
					count_vowel--;
				else
					count_con--;

				continue;
			}
		}

		else
		{
			make_pw(input, output, i + 1, output_idx + 1);

			if (is_vowel(input[i]))
				count_vowel--;
			else
				count_con--;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> pw_length >> num_ch;
	vector <char> input(num_ch);
	vector <char> output(pw_length);
	count_vowel = 0;
	count_con = 0;

	for (int i = 0; i < num_ch; i++)
	{
		cin >> input[i];
		if (is_vowel(input[i]))
			count_vowel++;

		else
			count_con++;
	}

	// 자음, 모음 부족하면 종료.
	if (count_vowel < 1 || count_con < 2)
		return 0;

	sort(input.begin(), input.end());

	for (int i = 0; i < num_ch - pw_length + 1; i++)
	{
		count_vowel = 0;
		count_con = 0;

		if (is_vowel(input[i]))
			count_vowel++;
		else
			count_con++;

		output[0] = input[i];
		make_pw(input, output, i+1, 1);
	}
}
