#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int idx = 0;
    int len = number.size() - k;
    char c = '0';
    
    for(int i = 0; i < len; i++){
        for(int j = idx; j < k + i + 1; j++){
            if(c < number[j]){
                c = number[j];
                idx = j + 1;
            }
        }
        
        answer += c;
        c = '0';
    }
    return answer;
}