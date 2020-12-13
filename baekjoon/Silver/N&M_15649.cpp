#include <iostream>
#include <algorithm>
#include <vector>

#pragma warning(disable: 4996)

using namespace std;

int n, m;
bool isVisit[10];

void dfs(vector<int>& v, int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < v.size(); i++) {
			if(v[i] != 0)
			cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!isVisit[i])
		{
			isVisit[i] = true;
			v[cnt] = i;
			dfs(v, cnt + 1);
			isVisit[i] = false;
		}
	}
}

int main() {
	int N, a, b, M;
	int answer = 0;
	cin >> n >> m;

	vector<int> v(9);
	dfs(v, 0);

	return 0;
}