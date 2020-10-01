#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(string s) {
    int j = 0;
    string c = "";
    map<int, vector<int>> m;
    vector<int> answer;
    vector<vector<int>> v;
    v.reserve(1000000);

    for(int i = 2; i < s.size() - 1; i++){
        if(s[i] - '0' >= 0 && s[i] - '0' < 10)
            c += s[i];
        else if(s[i] == ',' && c != ""){
            v[j].emplace_back(atoi(c.c_str()));
            c = "";
        }

        if(s[i] == '}'){
            v[j].emplace_back(atoi(c.c_str()));
            c = "";
            int n = v[j].size();
            for(int z = 0; z < n; z++)
                m[n].emplace_back(v[j][z]);

            j++;
        }
    }
    answer.emplace_back(0);
    for(int i = 1; i <= m.size(); i++){
        int num = 0;
        for(int j = 0; j < m[i].size(); j++){
            answer[i - 1] ^= m[i][j];
            num ^= m[i][j];
        }
        answer.emplace_back(num);
    }
    answer.pop_back();
    return answer;
}