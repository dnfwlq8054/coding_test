#include <string>
#include <vector>
#include <stack>

using namespace std;

bool check[20001];
int node[20001];

void dfs(vector<vector<int>>& v, int idx, int count){

    for(size_t i = 0; i < v[idx].size(); i++){
        if(node[v[idx][i]] > count && check[v[idx][i]] == false){
            node[v[idx][i]] = count;
            check[v[idx][i]] = true;
            dfs(v, v[idx][i], count + 1);
            check[v[idx][i]] = false;
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> v(n + 1);
    int answer = 0;

    for(size_t i = 0; i < edge.size(); i++){
        int n1 = edge[i][0], n2 = edge[i][1];
        v[n1].emplace_back(n2);
        v[n2].emplace_back(n1);
    }
    for(int i = 1; i <= n; i++)
        node[i] = 99999;

    check[1] = true;
    dfs(v, 1, 1);

    int MAX = 0;
    for(int i = 2; i <= n; i++){
        if(MAX < node[i]){
            answer = 1;
            MAX = node[i];
        }else if(MAX == node[i]) answer++;
    }
    return answer;
}
