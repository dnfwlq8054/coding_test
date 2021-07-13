#include <string>
#include <vector>

using namespace std;

vector<pair<int, int>> v = {
    {3, 1}, {0, 0}, {0, 1}, {0, 2},
    {1, 0}, {1, 1}, {1, 2},
    {2, 0}, {2, 1}, {2, 2},
    {3, 0}, {3, 2}
};

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left = 10;
    int right = 11;
    
    for( auto& n : numbers ) {
        if( n == 1 || n == 4 || n == 7 ) {
            answer += 'L';
            left = n;
        } else if( n == 3 || n == 6 || n == 9 ) {
            answer += 'R';
            right = n;
        } else {
            int left_locate = 
                abs(v[n].first - v[left].first) + abs(v[n].second - v[left].second);
            int right_locate = 
                abs(v[n].first - v[right].first) + abs(v[n].second - v[right].second);
            
            if( left_locate == right_locate ) {
                if( hand == "left" ) {
                    answer += 'L';
                    left = n;
                } else {
                    answer += 'R';
                    right = n;
                }
            } else if( left_locate < right_locate ) {
                answer += 'L';
                left = n;
            } else {
                answer += 'R';
                right = n;
            }
        }
    }
    
    return answer;
}