#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> weights, vector<string> head2head) {
    vector<int> answer;
    map<double, vector<pair<int, int>>, greater<double>> m;
    int idx = 0;
    
    for(auto& s : head2head){
        double count_W = 0;
        double count_L = 0;
        int big_Win = 0;
        int i = 0;
        for(auto& c : s){
            if(c == 'W') {
                count_W++;
                if(weights[idx] < weights[i]) big_Win++;
            }
            else if (c == 'L') count_L++;
            i++;
        }
        
        double ratio = count_W ? count_W / (count_W + count_L) : 0;
        m[ratio].emplace_back(idx, big_Win);
        idx++;
    }
    
    for(auto itr = m.begin(); itr != m.end(); itr++){
        sort(itr->second.begin(), itr->second.end(), [](auto a, auto b){
            return a.second > b.second;
        });
        
        sort(itr->second.begin(), itr->second.end(), [&](auto a, auto b){
            int aWeight = weights[a.first];
            int bWeight = weights[b.first];
            if(a.second == b.second) return aWeight > bWeight;
            else return false;
        });
        
        sort(itr->second.begin(), itr->second.end(), [&](auto a, auto b){
            int aWeight = weights[a.first];
            int bWeight = weights[b.first];
            if(a.second == b.second && aWeight == bWeight) return a.first < b.first;
            else return false;
        });        
    }
    
    for(auto itr = m.begin(); itr != m.end(); itr++){
        for(auto& n : itr->second){
            answer.emplace_back(n.first + 1);
        }
    }
    return answer;
}