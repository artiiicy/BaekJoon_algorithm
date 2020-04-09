#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int tower, pawn, home, gofront, goback, police, result;
vector <int> town;
queue <int> q;

bool bfs(int start, int end)
{
	q.push(start);
	town[start] = 1;
	
	while (!q.empty() && q.front() != end)
	{
		if (q.front() + gofront < town.size() && town[q.front() + gofront] == 0)
		{
			q.push(q.front() + gofront);
			town[q.front() + gofront] = town[q.front()] + 1;
		}

		if (q.front() - goback >= 0 && town[q.front() - goback] == 0)
		{
			q.push(q.front() - goback);
			town[q.front() - goback] = town[q.front()] + 1;
		}
		
		q.pop();
	}
	if (town[end] != 0)
		return true;

	else
		return false;
}

int main()
{
	cin >> tower >> pawn >> home >> gofront >> goback >> police;

	town.resize(tower);

	for (int i = 0; i < police; i++)
	{
		int temp;
		cin >> temp;
		town[temp - 1] = -1;
	}

	if (bfs(pawn - 1, home - 1) == true)
		cout << town[home - 1] - 1;
	else
		cout << "BUG FOUND";
}
