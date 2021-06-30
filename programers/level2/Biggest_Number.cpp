#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string &a, string &b) {
    return (a + b < b + a) ?  true : false;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> s;
    s.reserve(numbers.size() + 1);

    for (int i = 0; i < numbers.size(); i++) 
        s.emplace_back(to_string(numbers[i])); 

    sort(s.begin(), s.end(), cmp);

    for_each(s.rbegin(), s.rend(), [&](string s){
        answer += s; 
    });

    if (answer[0] == '0')
        return "0";

    return answer;
}