#include <string>
#include <vector>

using namespace std;
int answer = 0;
int len, t;
void dfs (vector<int>& v, int sum, int n){
    if(n == len){
        if(t == sum){
            answer++;
            return;
        }
        else
            return;
    }
    dfs(v, sum + v[n], n + 1);
    dfs(v, sum - v[n], n + 1);
}


int solution(vector<int> numbers, int target) {
    len = numbers.size();
    t = target;
    dfs(numbers, 0, 0);
    return answer;
}