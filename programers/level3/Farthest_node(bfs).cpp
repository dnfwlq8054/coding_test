#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

bool check[20001];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int MAX = 0;
    vector<vector<int>> v(n + 1);
    queue<pair<int, int>> q;
    
    for(size_t i = 0; i < edge.size(); i++){
        int n1 = edge[i][0]; int n2 = edge[i][1];
        v[n1].emplace_back(n2);
        v[n2].emplace_back(n1);
    }
    
    q.emplace(1, 1);
    check[1] = true;
    
    while(!q.empty()){
        int num = q.front().first;
        int count = q.front().second;
        q.pop();

        for(size_t i = 0; i < v[num].size(); i++){
            if(check[v[num][i]] == false){
                check[v[num][i]] = true;
                q.emplace(v[num][i], count + 1);
                cout << v[num][i] << " " << count + 1 << endl;;
                if(MAX < count + 1){
                    answer = 1;
                    MAX = count + 1;
                }else if(MAX == count + 1) answer++;
            }
        }
    }
    return answer;
}