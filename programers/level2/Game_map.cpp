#include <vector>
#include <queue>

using namespace std;

bool visit[101][101];
int dx[4] = { -1, +1, 0, 0 };    //위, 아래, 왼쪽, 오른쪽
int dy[4] = { 0, 0, -1, +1 };
int max_x, max_y;
int answer = -1;

void bfs(vector<vector<int>>& maps, queue<pair<int, int>>& q, queue<int>& count_q) {
    if(q.empty()) return;
    
    int x = q.front().first;
    int y = q.front().second;
    int count = count_q.front();
    count_q.pop();
    q.pop();
    
    if (max_x - 1 == x && max_y - 1 == y) {
        answer = count;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if (next_x > -1 && next_x < max_x && next_y > -1 && next_y < max_y)
        {
            if(maps[next_x][next_y] == 1 && !visit[next_x][next_y]){
                visit[next_x][next_y] = true;
                q.emplace(next_x, next_y);
                count_q.emplace(count + 1);
            }
        }
    }
    bfs(maps, q, count_q);
}

int solution(vector<vector<int> > maps)
{
    max_x = maps.size();
    max_y = maps[0].size();
    queue<pair<int, int>> q;
    queue<int> count_q;
    
    visit[0][0] = true;
    q.emplace(0, 0);
    count_q.emplace(1);
    
    bfs(maps, q, count_q);
    
    return answer;
}