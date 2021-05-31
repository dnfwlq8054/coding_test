#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int mini_num = 999999;
int x = 0;
int y = 0;

void moveing(int next_x, int next_y, int idx, int idy, vector<vector<int>>& v, int flag){
    if(flag == 1){
        for(int i = 0; i < idx; i++){
            v[x][y] ^= v[x + next_x][y + next_y] ^= v[x][y] ^= v[x + next_x][y + next_y];
            x += next_x;
            y += next_y;
            mini_num = min(mini_num, min(v[x][y], v[x - next_x][y - next_y]));
        }
    }else {
        for(int i = 0; i < idy; i++){
            v[x][y] ^= v[x + next_x][y + next_y] ^= v[x][y] ^= v[x + next_x][y + next_y];
            x += next_x;
            y += next_y;
            mini_num = min(mini_num, min(v[x][y], v[x - next_x][y - next_y]));
        }    
    }
    mini_num = min(mini_num, min(v[x][y], v[x - next_x][y - next_y]));
    
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> v(rows, vector<int>(columns));
    int n = 1;
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            v[i][j] = n++;
        }
    }
    
    for(int i = 0; i < queries.size(); i++){
        int start_x = x = queries[i][0] - 1;
        int start_y = y = queries[i][1] - 1;
        int end_x = queries[i][2] - 1;
        int end_y = queries[i][3] - 1;
        mini_num = v[start_x][start_y];
        int flag = 1;
        
        for(int j = 0; j < 4; j++){
            moveing(dx[j], dy[j], end_x - start_x, end_y - start_y, v, flag % 2);
            flag++;
        }
        v[x][y] ^= v[x][y + 1] ^= v[x][y] ^= v[x][y + 1];
        answer.emplace_back(mini_num);
    }
    return answer;
}