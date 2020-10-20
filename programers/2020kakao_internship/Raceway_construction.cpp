#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int cost[26][26];
int dx[4] = { -1, 0, 1, 0};
int dy[4] = { 0, -1, 0, 1};

struct Car{
    int x = 0;
    int y = 0;
    int cost = 0;
    bool updown = false;
    
    Car(){}
    Car(int _x, int _y, int _cost, bool _updown) : x(_x), y(_y), cost(_cost), updown(_updown) {}
};

int solution(vector<vector<int>> board) {
    int N = board.size() - 1;
    queue<Car *> q;
    
    for(int i = 0; i < 26; i++)
        for(int j = 0; j < 26; j++)
            cost[i][j] = 99999999;
    
    cost[0][0] = 0;
    if(board[0][1] != 1){
        q.emplace(new Car(0, 1, 100, false));
        cost[0][1] = 100;
    }
    if(board[1][0] != 1){
        q.emplace(new Car(1, 0, 100, true));
        cost[1][0] = 100;
    }
    
    while(!q.empty()){
        Car* car = q.front();
        q.pop();
        int cp_x = car->x; int cp_y = car->y;
        int now_cost = car->cost;
        if(cost[cp_x][cp_y] != now_cost)
            continue;
        
        for(int i = 0; i < 4; i++){
            int x = car->x + dx[i]; int y = car->y + dy[i];
            if(x >= 0 && x < board.size() && y >= 0 && y < board.size() && board[x][y] != 1){
                if(car->updown){
                    if(cp_x == x){
                        q.emplace(new Car(x, y, now_cost + 600, false));
                        if(cost[x][y] > now_cost + 600)
                            cost[x][y] = now_cost + 600;
                    }
                    else{
                        q.emplace(new Car(x, y, now_cost + 100, true));
                        if(cost[x][y] > now_cost + 100)
                            cost[x][y] = now_cost + 100;
                    }
                }
                else{
                    if(cp_y == y){
                        q.emplace(new Car(x, y, now_cost + 600, true));
                        if(cost[x][y] > now_cost + 600)
                            cost[x][y] = now_cost + 600;
                    }
                    else{
                        q.emplace(new Car(x, y, now_cost + 100, false));
                        if(cost[x][y] > now_cost + 100)
                            cost[x][y] = now_cost + 100;                            
                    }
                }
            }
        }
    }

    return cost[N][N];
}