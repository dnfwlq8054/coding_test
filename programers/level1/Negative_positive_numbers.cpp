#include <string>
#include <vector>

using namespace std;

int solution(vector<int> v, vector<bool> signs) {
    int answer = 0;
    
    for(size_t i = 0; i < signs.size(); i++){
        if(signs[i])
            answer += v[i];
        else
            answer -= v[i];
    }
    
    return answer;
}
