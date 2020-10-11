#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0, A_idx = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    for(size_t i = 0; i < B.size(); i++){
        if(B[i] > A[A_idx]){
            A_idx++; answer++;
        }
    }
    return answer;
}