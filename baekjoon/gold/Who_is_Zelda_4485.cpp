#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int N, i = 1;
	int arr[126][126];
	
	cin >> N;
	while (N != 0) {
		fill(arr[0], arr[126], 999999);
		vector<vector<int>> v(N, vector<int>(N));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				cin >> v[i][j];
		}
		arr[0][0] = v[0][0];

		queue<pair<int, int>> q;
		q.emplace(0, 0);

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			int num = arr[x][y];

			if (x + 1 < N) {
				if (num + v[x + 1][y] < arr[x + 1][y]) {
					arr[x + 1][y] = num + v[x + 1][y];
					q.emplace(x + 1, y);
				}
			}
			if (x - 1 > -1) {
				if (num + v[x - 1][y] < arr[x - 1][y]) {
					arr[x - 1][y] = num + v[x - 1][y];
					q.emplace(x - 1, y);
				}
			}
			if(y + 1 < N) {
				if (num + v[x][y + 1] < arr[x][y + 1]) {
					arr[x][y + 1] = num + v[x][y + 1];
					q.emplace(x, y + 1);
				}
			}
			if (y - 1 > -1) {
				if (num + v[x][y - 1] < arr[x][y - 1]) {
					arr[x][y - 1] = num + v[x][y - 1];
					q.emplace(x, y - 1);
				}
			}
		}
        printf("Problem %d: %d\n", i++, arr[N - 1][N - 1]);
		vector<vector<int>>().swap(v);
		cin >> N;
	}
	
	return 0;
}