#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <random>
#include <map>
#include <stack>

#pragma warning(disable: 4996)

using namespace std;

struct spanning {
	int point;
	int next;
	int weight;
public:
	spanning(int p, int n, int w) : point(p), next(n), weight(w) {}
};

int find_union(int n, vector<int>& cycle) {
	if (cycle[n] == n)
		return n;
	else
		return cycle[n] = find_union(cycle[n], cycle);
}

int kruskal(int _x, int _y, vector<int>& cycle) {
	int x = find_union(_x, cycle);
	int y = find_union(_y, cycle);

	if (x != y) {
		cycle[x] = y;
		return true;
	}
	return false;
}

int main() {
	int N, a, b, M;
	int answer = 0;
	int sum = 0;
	int MAX;
	cin >> N >> M;

	vector<spanning> v;
	vector<int> cycle(N + 1);

	for (size_t i = 0; i < cycle.size(); i++)
		cycle[i] = i;

	int x, y, w;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> w;
		v.emplace_back(x, y, w);
	}

	sort(v.begin(), v.end(), [](const spanning& a, const spanning& b) {
		return a.weight < b.weight;
		});

	for (auto& e : v) {
		if (kruskal(e.point, e.next, cycle))
			answer += e.weight;
	}

	cout << answer << endl;
	return 0;
}