#include <string>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> v;
    string temp = "";
    unordered_map<char, int> m;
    m['S'] = 1; m['D'] = 2; m['T'] = 3;
    
    for(int i = 0; i < dartResult.size(); i++){
        if(dartResult[i] == '*'){
            if(v.size() == 1)
                v[0] *= 2;
            else{
                v[v.size() - 1] *= 2;
                v[v.size() - 2] *= 2;
            }
        }else if(dartResult[i] == '#')
            v[v.size() - 1] *= -1;
        else if(dartResult[i] >= '0' && dartResult[i] <= '9')
            temp += dartResult[i];
        else{
            v.emplace_back(pow(atoi(temp.c_str()), m[dartResult[i]]));
            temp = "";
        }
    }
    for(int i = 0; i < v.size(); i++)
        answer += v[i];
    return answer;
}