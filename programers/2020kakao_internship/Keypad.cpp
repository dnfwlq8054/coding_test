#include <string>
#include <vector>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vector<vector<int>> v = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
    {10, 11, 12}
};

int dfs(int x, int y, int deep, int num, vector<vector<bool>>& isVisit){
    for(int i = 0; i < 4; i++){
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        
        if(next_x >= 0 && next_x < 4 && next_y >= 0 && next_y < 3 &&
          !isVisit[next_x][next_y]){
            isVisit[next_x][next_y] = true;
            if(v[next_x][next_y] == num) return deep;
            else return dfs(next_x, next_y, deep + 1);
        }
    }
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left = 10;
    int right = 12;
    
    for( auto& n : numbers ) {
        if( n == 1 || n == 4 || n == 7 ) {
            answer += 'L';
            left = n;
        } else if( n == 3 || n == 6 || n == 9 ) {
            answer += 'R';
            right = n;
        } else {
            if( n == 0 ) n = 11;
            
        }
    }
    
    return answer;
}