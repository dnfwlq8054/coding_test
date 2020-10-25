#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    if(board.size() == 1)
        return 1;
    
    for(int i = 1; i < board.size(); i++){
        for(int j = 1; j < board[i].size(); j++){
            if(board[i][j] != 0){
                board[i][j] = min(board[i - 1][j], min(board[i][j - 1], board[i - 1][j - 1])) + 1;
                answer = max(board[i][j], answer);
            }
        }
    }

    return answer * answer;
}