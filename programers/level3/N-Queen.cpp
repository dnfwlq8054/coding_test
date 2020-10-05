#include <string>
#include <vector>
#include <iostream>

using namespace std;

int len;
int answer;

void simulation (vector<vector<bool>> check, int x, int y, int count){
    if(count == len){
        answer++;
        return;
    }
    if(x == len - 1) return;

    for(int i = 1; i < len - x; i++){
        if(x + i < len && y + i < len)
            check[x + i][y + i] = true;
        if(y - i > -1 && x + i < len)
            check[x + i][y - i] = true;
        check[x + i][y] = true;
    }

    for(size_t i = 0; i < len; i++){
        if(check[x + 1][i] == false)
            simulation(check, x + 1, i, count + 1);
    }
}

int solution(int n) {
    len = n;
    vector<vector<bool>> check(n, vector<bool>(n));

    for(int i = 0; i < len; i++)
        simulation(check, 0, i, 1);

    return answer;
}