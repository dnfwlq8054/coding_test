#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    for(int i = 0; i < numbers.size(); i++){
        if(numbers[i] % 2 == 0) numbers[i] += 1;
        else {
            unsigned long long lastBit = ~numbers[i] & (numbers[i] + 1); 
            numbers[i] = (numbers[i] | lastBit) & ~(lastBit >> 1);
        }
    }
    return numbers;
}