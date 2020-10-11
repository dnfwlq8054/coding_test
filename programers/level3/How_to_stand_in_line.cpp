#include <string>
#include <vector>

using namespace std;

long long fact_n(long long n){
    if(n == 1) return n;
    return n * fact_n(n - 1);
}

void fnc(vector<int>& answer, vector<int>& number, long long k, long long n_1, int n){
    if(number.size() == 1) return;
    int quo = k / n_1;  //2
    long long rem = k % n_1;  //rem = k
    n_1 /= n;   //n_1 = n_1, n = n - 1;
    answer.emplace_back(number[quo]);
    number.erase(number.begin() + quo);
    fnc(answer, number, rem, n_1, n - 1);
}

vector<int> solution(int n, long long k) {
    vector<int> answer, number;
    long long n_1 = fact_n(n - 1);
    for(int i = 0; i < n; i++) number.emplace_back(i + 1);
    fnc(answer, number, k - 1, n_1, n - 1);
    answer.emplace_back(number[0]);
    return answer;
}