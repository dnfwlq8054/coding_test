#include <string>
#include <vector>

using namespace std;

bool decimal[1000001];

int solution(int n) {
    int answer = 0;
    
    for(int i = 2; i <= n; i++){
        for(int j = i + i; j <= n; j = j + i){
            decimal[j] = true;
        }
    }
    
    for(int i = 2; i <= n; i++)
        if(!decimal[i]) answer++;
    
    return answer;
}