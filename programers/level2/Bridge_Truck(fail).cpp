#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> v) {
    int answer = 0;
    int idx = 0;
    int num = 0;
    v.emplace_back(0);
    for(int i = 0; i < v.size(); i++){
        if(num <= bridge_length) {
            num += v[i];   
            answer++;
        }
        else {
            num -= v[idx++];
            answer += bridge_length;
        }
    }
    
    answer += bridge_length;
    return answer - 1;
}