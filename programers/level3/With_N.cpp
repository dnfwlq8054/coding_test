#include <string>
#include <vector>
#include <cmath>

using namespace std;

int answer = 9;
int num = 0;

void dfs(int n, int idx, int sum){
    if(idx > 8) return;
    
    if(sum == num) answer = min(answer, idx);
    
    int temp = 0;
    for(int i = 0; i < 8; i++){
        temp = 10 * temp + n;
        dfs(n, idx + i + 1, temp + sum);
        dfs(n, idx + i + 1, temp * sum);
        dfs(n, idx + i + 1, temp - sum);
        dfs(n, idx + i + 1, sum / temp);
    }
}

int solution(int N, int number) {
    num = number;
    
    dfs(N, 0, 0);
    if(answer > 8) answer = -1;
    return answer;
}