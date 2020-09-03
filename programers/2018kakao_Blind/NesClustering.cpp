#include <string>
#include <unordered_map>
#include <set>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int solution(string str1, string str2) {
    int answer = 0, len = 0;
    unordered_map<string, int> m1;
    unordered_map<string, int> m2;
    multiset<string> s;
    set<string> check;
    vector<string> v;
    
    if(str1.size() > str2.size()){
        len = str1.size();
        v.emplace_back(str1);
        v.emplace_back(str2);
    }else{
        len = str2.size();
        v.emplace_back(str2);
        v.emplace_back(str1);
    }
    
    for(int i = 1; i < len; i++){
        string temp_1 = "";
        string temp_2 = "";
        char c1 = tolower(v[0][i - 1]);
        char c2 = tolower(v[0][i]);
        if(c1 >= 'a' && c1 <= 'z' && c2 >= 'a' && c2 <= 'z'){
            temp_1 += c1;
            temp_1 += c2;
            m1[temp_1]++;
            s.emplace(temp_1);
            check.emplace(temp_1);
        }
 
        if(v[1].size() > i){
            c1 = tolower(v[1][i - 1]);
            c2 = tolower(v[1][i]);
            if(c1 >= 'a' && c1 <= 'z' && c2 >= 'a' && c2 <= 'z'){
                temp_2 += c1;
                temp_2 += c2;
                m2[temp_2]++;
                s.emplace(temp_2);
                check.emplace(temp_2);
            }
        }
    }
    
    double count = 0;
    for_each(check.begin(), check.end(), [&](string str){
        if(m1[str] > 0 && m2[str] > 0){
            if(m1[str] > m2[str])
                count += m2[str];
            else
                count += m1[str];
        }
    });
 
    if(count == 0 && s.size() == 0)
        return 65536;
    
    double sec = s.size() - count;
    answer = 65536 * (count / sec);    
    return answer;
}