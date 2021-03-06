//https://www.acmicpc.net/problem/10825
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct student {
	string name;
	int kor, eng, math;
};

// kor내림차순, eng 오름차순, math 내림차순, name 사전순 정렬
bool compare(const student &A, const student &B)
{
	if (A.kor != B.kor)
	{
		return A.kor > B.kor;
	}
	if (A.eng != B.eng)
	{
		return A.eng < B.eng;
	}
	if (A.math != B.math)
	{
		return A.math > B.math;
	}

	return A.name < B.name;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int N;
	cin >> N;
	vector<student> v(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> v[i].name >> v[i].kor >> v[i].eng >> v[i].math;
	}

	// 정렬
	sort(v.begin(), v.end(), compare);

	// 출력
	for (int i = 0; i < N; ++i)
	{
		cout << v[i].name << '\n';
	}

	return 0;
}