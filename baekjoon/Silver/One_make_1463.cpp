#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

queue<pair<int, int>> q;
bool check[1000001];

int dfs(queue<pair<int, int>>& q) {
    int n = 0, num = 0;
    n = q.front().first;
    num = q.front().second;
    q.pop();

    if (n == 1) return num;
    
    if (n % 3 == 0 && !check[n / 3]) 
        q.emplace(n / 3, num + 1);
    
    
    if (n % 2 == 0 && !check[n / 2]) 
        q.emplace(n / 2, num + 1);
    

    if (n - 1 > 0 && !check[n - 1]) 
         q.emplace(n - 1, num + 1);
     

    check[n] = true;
    return dfs(q);
}
int main() {
    int n;
    cin >> n;
    q.emplace(n, 0);
    printf("%d ", dfs(q));
    return 0;
}