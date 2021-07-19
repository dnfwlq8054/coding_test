#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int find_char(vector<char>& v, char c){
    for(int i = 0; i < v.size(); i++)
        if(c == v[i]) return i;
    
    return -1;
}

bool func1(int a, int b, int num){
    return abs(a - b) == num ? true : false;
}

bool func2(int a, int b, int num){
    return abs(a - b) < num ? true : false;
}

bool func3(int a, int b, int num){
    return abs(a - b) > num ? true : false;
}

int solution(int n, vector<string> data) {
    vector<char> v = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    int answer = 0;
    
    do {
        bool flag = true;
        
        for(auto& s : data) {
            int a = find_char(v, s[0]);
            int b = find_char(v, s[2]);
            int num = (s[4] - '0') + 1;

            if(s[3] == '=') flag = func1(a, b, num);
            else if(s[3] == '<') flag = func2(a, b, num);
            else flag = func3(a, b, num);
            
            if(!flag) break;
        }

        if(flag) answer++;

    } while (next_permutation(v.begin(), v.end()));

    return answer;
}