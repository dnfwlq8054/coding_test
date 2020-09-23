#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int find_union(int n, vector<int>& cycle){
    if(cycle[n] == n)
        return n;
    else
        return cycle[n] = find_union(cycle[n], cycle);
}

int kruskal(int _x, int _y, vector<int>& cycle){
    int x = find_union(_x, cycle);
    int y = find_union(_y, cycle);

    if(x != y){
        cycle[x] = y;
        return true;
    }
    return false;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<int> cycle(n);
    
    for(size_t i = 0; i < cycle.size(); i++)
        cycle[i] = i;
    
    sort(costs.begin(), costs.end(), [](auto a, auto b){
        if(a[2] > b[2]) return false;
        else return true;
    });
    
    for(auto& v : costs){
        for(auto n : v)
            cout << n << " ";
        cout << endl;
    }

    for(auto& v : costs){
        if(kruskal(v[0], v[1], cycle))
            answer += v[2];
    }
    
    return answer;
}