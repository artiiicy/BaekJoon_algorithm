/*
BaekJoon #14919 분포표 만들기

<ADT>
1. 엔터를 입력받아야 입력이 끝나므로 string으로 입력을 받는다.
2. string에서 실수에 해당하는 정보만 실수화 해준다. ( 0. 이후의 숫자들을 1/10, 1/100 에 곱해주고 이 값들을 더해준다.)
3. sort함수로 오름차순 정렬해준다.
4. 탐색을 통해 각 L에 해당하는 수를 세준다.

<오답노트>
indicator를 초기화해주는 과정에서 indicator = 1 / m; 이라고 명시했더니 int로 형변환이 되었다. 따라서 (double) 1/ m; 이라고 작성해 주어야 한다.

1. 맨 마지막 출력 반복문을 m만큼 출력해주어야 함. j만큼 출력해준다면 5 0 0 0 0 의 경우를 5 만 출력하고 끝낸다.
2. 위의 자질구레한 오답들과 달리 대망의 이유가 있었다. 바로 실수 저장시 나타나는 부정확성에 관한 문제점이다.
	컴퓨터는 실수를 저장할 때 부동소수점 방식으로 저장하기 때문에 정확한 값이 아닌 근삿값이 저장된다. 따라서 이를 없애줘야 한다.
	문제 조건이 소수 6자리수를 최대 1000가지로 쪼개기 때문에 9자리까지 정확해야 한다는데...
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

double input[1000001];
int input2[1000001];
int output[1001];
int ind[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int m;
	double indicator;
	string str;

	cin >> m;
	cin.ignore(256, '\n');
	getline(cin, str);

	//find a real number
	int idx = 0;
	for (int i = 0; i < str.length();)
	{
		if (str[i] == '0' && i + 1 < str.length() && str[i + 1] == '.')
		{
			i = i + 2;	//move the i to point the number after '0.'

			double temp = 0.1;
			while (i < str.length() && str[i] != ' ')
			{
				input[idx] += temp * (str[i] - '0');
				temp *= 0.1;
				i++;
			}
			idx++;
		}

		else
			i++;	//ignore the white space
	}

	sort(input, input + idx);	//sorting all the input real number

	for (int i = 0; i < idx; i++)	//preprocessing the input data from real number to integer
	{
		input[i] += 0.0000000001;
		input2[i] = input[i] * 1000000;
	}

	//count the num of real number that is included on each part.
	indicator = (double)1 / m + 0.0000000001;	//preprocessing the indicator from real number to integer
	for (int i = 0; i < m; i++)
	{
		ind[i] = (i + 1)*indicator * 1000000;
		if (((i + 1) * 1000000) % m != 0) ind[i]++;
	}

	for (int i = 0, j = 0; i < idx && j < 1001;)	//i : iterator of input array, j : iterator of output array
	{
		if (input2[i] < ind[j])
		{
			output[j]++;
			i++;
		}

		else
		{
			j++;
		}
	}

	for (int i = 0; i < m; i++)
		cout << output[i] << " ";
}
