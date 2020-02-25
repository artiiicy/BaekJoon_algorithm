/*
BaekJoon #2912 백설공주와 난쟁이
#이분탐색 #BinarySearch
*/



#include <iostream>
#include <algorithm>

using namespace std;

int dwarf[300001];
int dwarf2[300001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int num_dwarf, hat, picture;

	cin >> num_dwarf >> hat;
	for (int i = 0; i < num_dwarf; i++)
		cin >> dwarf[i];

	cin >> picture;

	int start, end;

	for (int i = 0; i < picture; i++)
	{
		cin >> start >> end;
		int length = end - start + 1;
		int low = 0, high = length / 2 - 1, mid, idx = 0;	//이진탐색을 위한 변수들
		int found = 0;	//찾으면 1로 변경할 변수.

		for (int j = 0; j < length; j++)
			dwarf2[j] = dwarf[j + start - 1];

		sort(dwarf2, dwarf2 + length);

		int temp = dwarf2[length / 2];	//기준이 되는 값.

		if (temp == dwarf2[length - 1])	//기준이 되는 값과 오른쪽 끝 값이 같은 경우
		{
			if (length % 2 == 0)
			{
				if (temp == dwarf2[length / 2 - 1])	//기준이 되는 값 - 1 값도 봐준다. (절반 초과인 경우를 찾아야 하므로)
				{
					cout << "yes " << temp << endl;
					found = 1;
					continue;
				}
			}

			else
			{
				cout << "yes " << temp << endl;
				found = 1;
				continue;
			}
		}

		else if (temp == dwarf2[0])	//기준이 되는 값과 왼쪽 끝 값이 같은 경우
		{
			cout << "yes " << temp << endl;
			found = 1;
			continue;
		}
		/*
		cout << "값 : " << temp << endl;
		for (int j = 0; j < length; j++)
			cout << dwarf2[j] << " ";
		cout << endl;
		*/
		//위 두 경우가 아니라면 temp값의 분포를 찾고 그 분포의 길이가 N/2 초과인지 살펴보아야함 -> Binary Search 사용
		//왼쪽 살펴보기
		while (low <= high)
		{
			mid = (low + high) / 2;

			if (dwarf2[mid] == temp)
			{
				high = mid - 1;
				idx = mid;
				found = 1;
			}

			else if (dwarf2[mid] < temp)
				low = mid + 1;
		}

		if (found == 1 && dwarf[idx + length / 2] == temp)
			cout << "yes " << temp << endl;

		else if(found == 0)
			cout << "no" << endl;

		/*
if (found == 0)
{
	//오른쪽 살펴보기
	low = length / 2, high = length - 1;

	while (low <= high)
	{
		cout << "here";

		mid = (low + high) / 2;

		if (dwarf2[mid] == temp)
		{
			low = mid + 1;
			idx = mid;
		}

		else if (dwarf2[mid] > temp)
			high = mid - 1;
	}
}

cout << "idx : " << idx << endl;
*/
	}
}
