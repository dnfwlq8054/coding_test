#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> money) {
	int answer = 0;
    int dp1[1000010] = { 0, };
    int dp2[1000010] = { 0, };
    
    dp1[0] = dp1[1] = money[0];
    dp2[0] = 0; dp2[1] = money[1];
    
    for(size_t i = 2; i < money.size(); i++){
        if(i != money.size() - 1){
            dp1[i] = max(dp1[i - 1], dp1[i - 2] + money[i]);
            answer = dp1[i];
        }
        dp2[i] = max(dp2[i - 1], dp2[i - 2] + money[i]);
    }

    
    return max(answer, dp2[money.size() - 1]);
}