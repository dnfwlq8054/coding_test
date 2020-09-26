#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, map<int, set<int>, greater<int>>> list_map;
    map<string, int> max;
    map<int, string, greater<int>> sort_max;
    int i = 0;
    
    for_each(genres.begin(), genres.end(), [&](string& s){  //데이터 분류 작업
        if(list_map.find(s) == list_map.end()){
            map<int, set<int>, greater<int>> m;   
            set<int> index;

            index.insert(i);
            max.emplace(s, plays[i]);
            m.emplace(plays[i], index);
            list_map.emplace(s, m);
        }else{
            map<int, set<int>, greater<int>>::iterator itr;
            if((itr = list_map[s].find(plays[i])) == list_map[s].end()){
                set<int> index;
                index.insert(i);
                list_map[s].emplace(plays[i], index);
                max[s] += plays[i]; 
            }else{
                itr->second.insert(i);
                max[s] += plays[i]; 
            }
        }
        i++;
    }); 

    for_each(max.begin(), max.end(), [&](pair<string, int> itr){    //max값 찾기
        sort_max.emplace(itr.second, itr.first);     
    });

    for_each(sort_max.begin(), sort_max.end(), [&](pair<int, string> s){    //검색
         map<int, set<int>, greater<int>>::iterator m = list_map[s.second].begin();
         set<int>::iterator itr = m->second.begin();;
         
         if(list_map[s.second].size() == 1){
            answer.push_back(*itr);
            return;
         }
         
         for(int i = 0; i < 2; i++){
            if(m->second.size() > 1 && i == 0){
                answer.push_back(*(itr++));
                answer.push_back(*(itr++));
                return;
            }
            answer.push_back(*itr);
            itr = (++m)->second.begin();
         }
    });
    return answer;
}