/*
BaekJoon #6603 로또
#BackTracking #백트래킹 #DFS


<ADT>
-DFS(재귀)방식으로 모든 원소 순회.
-백트래킹 : 남은 노드 수를 모두 채워도 6이 안되면 pruning

*/
#include <iostream>
#include <vector>

using namespace std;
int input[12];
int output[6];
int num;

void dfs(int idx, int cnt)
{
	if (cnt == 6)
	{
		for (int i = 0; i < 6; i++)
			cout << output[i] << " ";
		cout << endl;

		return;
	}

	for(int i=idx; i<num; i++)
	{
		output[cnt] = input[i];

		if(num - i - 1 >= 6 - cnt - 1)
			dfs(i + 1, cnt + 1);
	}
}

int main()
{
	while (cin >> num && num)
	{
		for (int i = 0; i < num; i++)
			cin >> input[i];

		dfs(0, 0);
		cout << endl;
	}
}
