#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int Min = 999999999;
int Max = -999999999;

string solution(string s) {
    stringstream ss(s);
    string line;

    while(getline(ss, line, ' ')){
        int num = stoi(line);
        if(num > Max) Max = num;
        if(num < Min) Min = num;
    }

    string answer = to_string(Min) + ' ' + to_string(Max);
    return answer;
}
