#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> v(n + 1, vector<int>(m + 1));
    
    for(auto& e : puddles)
        v[e[1]][e[0]] = -1;
    
    v[1][0] = 1;
    for(size_t i = 1; i < v.size(); i++){
        for(size_t j = 1; j < v[i].size(); j++){
            if(v[i][j] == -1)
                v[i][j] = 0;
            else
                v[i][j] = (v[i][j - 1] + v[i - 1][j]) % 1000000007;
        }
    }

    answer = v[n][m];
    return answer;
}