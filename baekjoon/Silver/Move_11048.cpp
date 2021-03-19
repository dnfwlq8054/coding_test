#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N, M;
    int answer = 0;
    
    cin >> N >> M;
    vector<vector<int>> v(N + 1, vector<int>(M + 1));
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> v[i + 1][j + 1];
        }
    }
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            v[i][j] = max(v[i - 1][j], max(v[i - 1][j - 1], v[i][j - 1])) + v[i][j];
            answer = max(answer, v[i][j]);
        }
    }
    
    cout << answer << endl;
    
    return 0;
}