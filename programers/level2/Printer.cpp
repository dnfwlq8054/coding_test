#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <iostream>

using namespace std;

int check(queue<int>& q, int locate, int count, multiset<int, greater<int>>::iterator itr){
    for(int i = 0; i < q.size(); i++){
        if(q.front() == *itr){ 
            count++; 
            q.pop(); 
            break; 
        }
        else{ 
            q.emplace(q.front()); 
            q.pop(); 
            locate--; 
            
            if(locate == -1) 
                locate = q.size() - 1; 
        }
    }
    if(locate == 0) return count;
    return check(q, locate - 1, count, ++itr);
}

int solution(vector<int> priorities, int location) {
    queue<int> q; 
    multiset<int, greater<int>> s;
    int answer = 0;
    
    for(int i = 0; i < priorities.size(); i++) { 
        q.emplace(priorities[i]); 
        s.emplace(priorities[i]); 
    }

    answer = check(q, location, 0, s.begin());
    
    return answer;
}