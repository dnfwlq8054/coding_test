#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> s;
    
    for(size_t i = 0; i < numbers.size(); i++){
        for(int j = i + 1; j < numbers.size(); j++){
            s.emplace(numbers[i] + numbers[j]);
        }
    }
    for(auto n : s)
        answer.emplace_back(n);
    return answer;
}