#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    for(int i = 0; i < arr1.size(); i++){
        answer.emplace_back(vector<int>());
        for(int j = 0; j < arr2[0].size(); j++){
            int sum = 0;
            for(int z = 0; z < arr1[0].size(); z++){
                sum += arr1[i][z] * arr2[z][j];
            }
            answer.back().emplace_back(sum);
        }
    }    

    return answer;
}