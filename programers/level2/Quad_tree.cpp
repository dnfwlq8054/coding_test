#include <string>
#include <vector>

using namespace std;

vector<int> answer(2);

int dfs(vector<vector<int>>& v, int x, int y, int h){
    if(h == 1)
        return v[x][y];

    int num = 0;
    num += dfs(v, x, y, h / 2);
    num += dfs(v, x + h / 2, y, h / 2);
    num += dfs(v, x, y + h / 2, h / 2);z
    num += dfs(v, x + h / 2, y + h / 2, h / 2);

    if(num == 4){
        answer[1] -= 3;
        return 1;
    }

    if(num == 0){
        answer[0] -= 3;
        return 0;
    }

    if(num != 4 && num != 0)
        num = 10000;

    return num;
}

vector<int> solution(vector<vector<int>> arr) {
    for(auto& v : arr){
        for(auto n : v){
            if(n == 0) answer[0]++;
            else answer[1]++;
        }
    }

    dfs(arr, 0, 0, arr.size());
    return answer;
}