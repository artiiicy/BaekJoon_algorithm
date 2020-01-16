#include <iostream>
#include <vector>
#include <string>

#define ALPHABET_NUM 26

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector <int> alphabet(ALPHABET_NUM, -1);	// 결과물 저장할 벡터 (각 index는 순서대로 알파벳 의미)
	string input;								// input word 저장할 변수

	// 단어 입력받기
	cin >> input;

	// 단어 앞에서부터 참조하면서 hash function이용하여 해당하는 알파벳 벡터의 값 수정
	for (int i = 0; i < input.length(); i++)
	{
		int hashResult = (int)input[i] % 97;

		// 처음 만난 알파벳이면 현재의 index값 alphabet 벡터에 저장
		if (alphabet[hashResult] == -1)
			alphabet[hashResult] = i;

		// 처음 만난 알파벳이 아니면 continue
		else
			continue;
	}


	// 결과(alphabet 벡터) 출력
	for (int i = 0; i < ALPHABET_NUM; i++)
	{
		cout << alphabet[i] << " ";
	}
}
