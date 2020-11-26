#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    if(cacheSize == 0)
        return cities.size() * 5;
    
    int answer = 0;
    list<string> li;
    
    for_each(cities.begin(), cities.end(), [](string& s){
        for(int i = 0; i < s.size(); i++)
            s[i] = tolower(s[i]);
    });
    
    for(int i = 0; i < cities.size(); i++){
        list<string>::iterator itr = li.begin();
        bool flag = true;
        for(;itr != li.end(); itr++){
            if(*itr == cities[i]){
                li.erase(itr);
                li.emplace_back(*itr);
                flag = false;
                answer++;
                break;
            }
        }
        if(flag){
            if(cacheSize == li.size()){
                li.pop_front();
                li.emplace_back(cities[i]);
            }
            else
                li.emplace_back(cities[i]);
            
            answer += 5;
        }
    }
    
    return answer;
}