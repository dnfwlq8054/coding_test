#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = 2;
    
    while(true){
        int count = 0;
        for(auto n : arr){
            int rem = answer % n;
            if(rem == 0) count++;
            else break;
        }
        if(count == arr.size()) break;
        answer++;
    }
    return answer;
}