#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<int, vector<int>> m;

int make_key(int x, int y){
    return x + (y * 11);
}

bool check(int key1, int key2){
    if(m[key2].size() == 0){
        m[key2].emplace_back(key1);
        m[key1].emplace_back(key2);
        return true;
    }
    
    if(find(m[key2].begin(), m[key2].end(), key1) == m[key2].end()){
        m[key2].emplace_back(key1);
        m[key1].emplace_back(key2);
        return true;
    }
    else
        return false;
}

int solution(string dirs) {
    int answer = 0;
    int x = 5, y = 5;
    
    for(auto& c : dirs){
        int key1 = make_key(x, y);
        if(c == 'L' && x - 1 > -1) x--;
        else if(c == 'R' && x + 1 < 11) x++;
        else if(c == 'U' && y - 1 > -1) y--;
        else if(c == 'D' && y + 1 < 11) y++;
        else continue;

        int key2 = make_key(x, y);
        
        if(check(key1, key2))
            answer++;
    }
    return answer;
}