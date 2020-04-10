/*
BaekJoon #13701 중복제거

<ADT>
int 형 = 32bit이므로 32로 나누어 몫을 int형 배열의 idx로, 그 idx에서 (나머지에 해당하는 값의 int의 bit)를 1로, 저장해주어 반복되게 입력되지 않게 한다.

<오답노트>
while문 안에 조건문을 " input != NULL " 로 해서 1차 시간초과.
" input != EOF " 로 해서 2차 시간초과.
" ~scanf( ... ) " 로 해서 정답..

~scanf 의 의미는 더 이상 입력이 없으면 조건문 탈출, input != EOF 의 의미는 EOF가 입력으로 들어와야 조건문 탈출.
*/

#include <iostream>
#include <cstdio>

using namespace std;

int arr[1100000];

int main()
{
	int input;
	int quotient, remainder;

	while (~scanf("%d", &input))
	{
		quotient = input / 32;
		remainder = input % 32;

		if (!(arr[quotient] & (1 << remainder)))
		{
			arr[quotient] |= (1 << remainder);
			cout << input << " ";
		}
	}
}
