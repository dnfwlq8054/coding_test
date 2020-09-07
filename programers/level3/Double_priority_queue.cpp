#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2);
    multiset<int> q;
    
    for(auto s : operations)
        if(s[0] == 'I')
            q.emplace(stoi(s.c_str() + 2));
        else
            if(q.size() > 0)
                if(stoi(s.c_str() + 2) > 0) q.erase(--(q.end()));
                else q.erase(q.begin());
    
    if(q.size() < 2) return answer;
    
    answer[0] = *(--(q.end()));
    answer[1] = *q.begin();
    
    return answer;
}