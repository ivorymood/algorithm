//https://www.acmicpc.net/problem/16940
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 입력으로 주어진 BFS 방문순서가 올바른지 검사
bool bfs(vector<vector<int>>& graph, queue<int>& test)
{
	// 문제에서 시작 노드는 1로 고정된다.
	if (test.front() != 1)
	{
		return false;
	}

	vector<bool> visit(graph.size());
	queue<int> q;
	q.push(1);
	test.pop();

	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		visit[now] = true;

		// 자식 노드 중에서 아직 방문하지 않은 노드의 개수를 카운팅
		int next_cnt = graph[now].size();
		for (int next : graph[now])
		{
			if (visit[next])
			{
				--next_cnt;
			}
		}

		// 아직 방문하지 않은 자식 노드를 모두 큐에 넣을 때까지 반복문
		while (next_cnt)
		{
			// 입력순서 test큐의 front를 현재 노드의 자식 노드 중에서 찾을 수 있으면 
			// bfs큐에 push. test큐 pop
			auto it_next = find(graph[now].begin(), graph[now].end(), test.front());
			if (it_next != graph[now].end())
			{
				q.push(*it_next);
				test.pop();
				--next_cnt;
			}
			// 아니면 false 반환 및 종료
			else
			{
				return false;
			}
		}
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 입력
	int N;
	cin >> N;
	vector<vector<int>> graph(N + 1, vector<int>());
	for (int i = 0; i < N - 1; ++i)
	{
		int first, second;
		cin >> first >> second;
		graph[first].push_back(second);
		graph[second].push_back(first);
	}

	// 주어진 입력 순서를 큐로 만든다.
	queue<int> test;
	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;
		test.push(num);
	}

	// 입력으로 주어진 BFS 방문순서가 올바르면 1, 아니면 0 출력
	cout << bfs(graph, test);

	return 0;
}