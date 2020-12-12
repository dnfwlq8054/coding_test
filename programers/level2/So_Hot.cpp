#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> q(scoville.begin(), scoville.end());
    int answer = 0;
    
    while(q.top() < K){
        int f = q.top(); q.pop();
        if(q.empty()) return -1;
        int b = q.top(); q.pop();
        q.emplace(f + b * 2);
        answer++;
    }
    return answer;
}