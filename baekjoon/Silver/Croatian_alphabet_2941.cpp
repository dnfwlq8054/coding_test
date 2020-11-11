#include <iostream>
#include <vector>
#include <queue>
#include <map>

#pragma warning(disable: 4996)

using namespace std;

int main() {
    int T;
    int N, M, K, H;
    int X, Y;
    int answer = 0;
    int cost = 0;
    string s;
    map<string, int> m;
    m["c="] = 1;
    m["c-"] = 1;
    m["dz="] = 1;
    m["d-"] = 1;
    m["lj"] = 1;
    m["nj"] = 1;
    m["s="] = 1;
    m["z="] = 1;

    cin >> s;


    for (int i = 0; i < s.size(); i++) {
        string temp = "";
        if (s[i] == 'd') {
            temp = s.substr(i, 3);

            if (m.find(temp) != m.end()) 
                i += 2;
            
            temp = s.substr(i, 2);
            if (m.find(temp) != m.end())
                i += 1;
            answer++;
        }
        else {

            temp = s.substr(i, 2);
            if (m.find(temp) != m.end()) {
                i += 1;
            }
            answer++;
        }
    }
  
    cout << answer << endl;
    return 0;
}