#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    vector<long long> v;
    long long rem = 1234567;
    v.emplace_back(1);
    v.emplace_back(1);
    
    for(int i = 0; i < n - 1; i++)
        v.emplace_back((v[i] + v[i + 1]) % rem);
    
    return v.back();
}

/* dfs */
#include <string>
#include <vector>

using namespace std;

long long answer = 0;

void dfs(int len, int sum){
    if(sum > len) return;
    
    if(sum == len){
        answer++;
        return;
    }
    
    dfs(len, sum + 1);
    dfs(len, sum + 2);
}

long long solution(int n) {
    long long rem = 1234567;
    dfs(n, 0);
    return answer % rem;
}