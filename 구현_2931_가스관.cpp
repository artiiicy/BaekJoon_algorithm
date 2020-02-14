/*
<ADT>
전체 Map을 탐색하다가 빈칸을 나타내는 . 의 사방 중 하나라도 구멍이 뚫린 곳이 있다면 그곳이 파이프가 들어갈 위치.
위치를 파악한 후에는 해당 위치의 사방 중 구멍이 있는 곳들을 파악하여 해당 구멍 위치 및 개수에 맞는 파이프를 넣는다

- 주의할 점
1.  M, Z에 파이프가 연결되어 있다면 이를 벽으로 취급하고 파이프가 연결되어 있지 않다면 사방으로 뚫려있다고 가정한다
2. 구멍이 뚫린 곳이 한개라면 (M, Z일 가능성이 큼) 무시한다. 무조건 두개 이상이 연결되어 있어야 파이프를 넣을 위치이다

<오답노트>
3을 출력해야 하는 부분에서 바보같이 4를 출력해서 오답
*/

#include <iostream>
#define ROW_MAX 25
#define COL_MAX 25

using namespace std;

int row, col, cnt;
char Map[ROW_MAX + 2][COL_MAX + 2];
bool hole[4];
int dx[4]= { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool FindPipe(int row, int col, int direct) {
	// 아래로 뚫린 파이프면 true
	if (direct == 0) {
		if (Map[row][col] == '1' || Map[row][col] == '+' || Map[row][col] == '|' || Map[row][col] == '4' || Map[row][col] == 'S') {
			hole[direct] = 1;
			cnt++;
			return true;
		}
	}
	// 왼쪽으로 뚫린 파이프면 true
	else if (direct == 1)	{
		if (Map[row][col] == '-' || Map[row][col] == '+' || Map[row][col] == '3' || Map[row][col] == '4' || Map[row][col] == 'S') {
			hole[direct] = 1;
			cnt++;
			return true;
		}
	}
	// 위로 뚫린 파이프면 true
	else if (direct == 2)	{
		if (Map[row][col] == '|' || Map[row][col] == '+' || Map[row][col] == '3' || Map[row][col] == '2' || Map[row][col] == 'S') {
			hole[direct] = 1;
			cnt++;
			return true;
		}
	}
	// 오른쪽으로 뚫린 파이프면 true
	else {
		if (Map[row][col] == '-' || Map[row][col] == '+' || Map[row][col] == '1' || Map[row][col] == '2' || Map[row][col] == 'S') {
			hole[direct] = 1;
			cnt++;
			return true;
		}
	}
	return false;
}

// M, Z의 사방에 파이프가 하나라도 있으면 벽(0)으로, 없으면 'S'로 저장
void initialize(int row, int col)
{
	Map[row][col] = 'S';

	for (int i = 0; i < 4; i++) {
		// 파이프가 하나라도 연결되어 있는 경우 벽 취급
		if (FindPipe(row + dx[i], col + dy[i], i)) {
			Map[row][col] = 0;
			return;
		}
	}

	cnt = 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int m_row, m_col, z_row, z_col;
	cin >> row >> col;

	for (int i = 1; i < row + 1; i++)
		for (int j = 1; j < col + 1; j++) {
			cin >> Map[i][j];
			
			if (Map[i][j] == 'M') {
				m_row = i;
				m_col = j;
			}

			else if (Map[i][j] == 'Z') {
				z_row = i;
				z_col = j;
			}
		}

	initialize(m_row, m_col);
	initialize(z_row, z_col);

	for (int i = 0; i < 4; i++)
		hole[i] = false;
	cnt = 0;
	
	// Map 전체 탐색하면서 파이프가 들어갈 곳 찾기
	for (int i = 1; i < row + 1; i++) {
		for (int j = 1; j < col + 1; j++) {
			if (Map[i][j] == '.')
			{
				for (int k = 0; k < 4; k++) {
					FindPipe(i + dx[k], j + dy[k], k);
				}

				if (cnt > 1)
				{
					cout << i << " " << j << " ";
					
					switch (cnt)
					{
					case 2:
						if (hole[0])
						{
							if (hole[1])
								cout << 2;
							else if (hole[2])
								cout << '|';
							else
								cout << 3;
						}
						else if (hole[3])
						{
							if (hole[1])
								cout << '-';
							else
								cout << 4;
						}
						else
							cout << 1;
						break;
					case 4:
						cout << '+';
						break;
					}
					return 0;
				}

				for (int i = 0; i < 4; i++)
					hole[i] = false;
				cnt = 0;
			}
		}
	}
}
