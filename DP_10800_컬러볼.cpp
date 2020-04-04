#include <iostream>
#include <algorithm>

using namespace std;

struct Ball {
	int id, color, size, result;
};

// ball structure를 size 순으로 정렬해주는 함수
bool cmpSize(struct Ball &a, struct Ball &b)
{
	return a.size < b.size;
}

// ball structure를 id 순으로 정렬해주는 함수
bool cmpId(struct Ball& a, struct Ball& b)
{
	return a.id < b.id;
}

// main 내부에 지역변수로 선언할 경우 stack overflow. 따라서 Heap에 배정한다. (= 전역변수 혹은 static변수로 선언해준다.)
struct Ball ballArr[200001];
int totalSumOfBallSize[200001];
int currentSumOfBallSize[200001][2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int numOfBall;
	int totalSum = 0;
	int currentSum = 0;
	int beforeSize = 0;

	cin >> numOfBall;

	for (int i = 0; i < numOfBall; i++)
	{
		ballArr[i].id = i;
		cin >> ballArr[i].color >> ballArr[i].size;
	}

	// ball의 size크기로 오름차순 정렬
	sort(ballArr, ballArr + numOfBall, cmpSize);

	beforeSize = ballArr[0].size;

	for (int i = 0; i < numOfBall; i++)
	{
		// 해당 ball Size를 같은 색의 ball 배열에 합산
		totalSumOfBallSize[ballArr[i].color - 1] += ballArr[i].size;
		
		// 총 ball Size 합산
		totalSum += ballArr[i].size;

		// 현재 Size Level과 다르다면 합산이 아닌 대입
		if (beforeSize != ballArr[i].size)
		{
			currentSum = ballArr[i].size;
		}
		else // 현재 Size Level이라면 합산
		{
			currentSum += ballArr[i].size;
		}

		// 현재 Size Level과 다르다면 합산이 아닌 대입
		if (currentSumOfBallSize[ballArr[i].color - 1][1] != ballArr[i].size)
		{
			currentSumOfBallSize[ballArr[i].color - 1][0] = ballArr[i].size;
			currentSumOfBallSize[ballArr[i].color - 1][1] = ballArr[i].size;
		}
		else // 현재 Size Level이라면 합산
		{	
			currentSumOfBallSize[ballArr[i].color - 1][0] += ballArr[i].size;
		}

		ballArr[i].result = totalSum - currentSum - (totalSumOfBallSize[ballArr[i].color - 1] - currentSumOfBallSize[ballArr[i].color - 1][0]);

		beforeSize = ballArr[i].size;
	}

	sort(ballArr, ballArr + numOfBall, cmpId);

	for (int i = 0; i < numOfBall; i++)
	{
		cout << ballArr[i].result << " ";
	}
}
