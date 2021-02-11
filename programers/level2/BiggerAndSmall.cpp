#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> v;
    v.push_back(stoi(s));
    for(int i=1;i<s.length();i++){
        if(s[i] == ' '){
            v.push_back(stoi(s.substr(i+1,i+3)));
            cout << v.back() << endl;
        }
    }
    sort(v.begin(),v.end());
    return answer += to_string(v[0]) + " " + to_string(v[v.size()-1]);
}