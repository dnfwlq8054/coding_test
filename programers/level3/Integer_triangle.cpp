#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    for(size_t i = 1; i < triangle.size(); i++){
        for(size_t j = 0; j < triangle[i].size(); j++){
            if(j != 0 && j < triangle[i - 1].size())
                triangle[i][j] += max(triangle[i - 1][j], triangle[i - 1][j - 1]);
            else if(j == 0)
                triangle[i][j] += triangle[i - 1][j];
            else
                triangle[i][j] += triangle[i - 1][j - 1];
            
            answer = max(answer, triangle[i][j]);
        }
    }
    return answer;
}