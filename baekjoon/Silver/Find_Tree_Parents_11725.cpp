#include <iostream>
#include <vector>
#include <algorithm>

#pragma warning(disable: 4996)

using namespace std;

int arr[100001];
bool isVisit[100001];
vector<vector<int>> v(100001);

void dfs(int num) {
    isVisit[num] = true;

    for (int i = 0; i < v[num].size(); i++) {
        if(!isVisit[v[num][i]]){
            arr[v[num][i]] = num;
            dfs(v[num][i]);
        }
    }
}

int main() {
    int N, a, b;
    
    scanf("%d", &N);

    for (int i = 0; i < N - 1; i++) {
        scanf("%d %d", &a, &b);
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }

    dfs(1);

    for (int i = 2; i <= N; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}