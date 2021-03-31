#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Balloon{
    int num;
    int idx;
};

int solution(vector<int> a) {
    int answer = 0;
    vector<Balloon> v(a.size());

    for(int i = 0; i < a.size(); i++){
        v[i].idx = i;
        v[i].num = a[i];
    }

    sort(v.begin(), v.end(), [](auto a, auto b){
       return a.num < b.num; 
    });

    int fmin_idx = min(v[0].idx, v[1].idx);
    int tmin_idx = max(v[0].idx, v[1].idx);

    for(int i = 2; i < v.size(); i++){

        int current_idx = v[i].idx;
        if(fmin_idx < current_idx && current_idx < tmin_idx) continue;

        answer++;
        fmin_idx = min(fmin_idx, current_idx);
        tmin_idx = max(tmin_idx, current_idx);
    }
    return answer + 2;
}