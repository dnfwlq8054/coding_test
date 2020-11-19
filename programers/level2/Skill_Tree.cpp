#include <string>
#include <vector>
#include <algorithm>

#define ARPABAT 26
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int arpabat[ARPABAT];

    for(int i = 0; i < ARPABAT; i++)
        arpabat[i] = -1;

    for(int i = 0; i < skill.size(); i++){
        int index = skill[i] - 'A';
        arpabat[index] = i;
    }

    for_each(skill_trees.begin(), skill_trees.end(), [&](string s) {
        int rank = 0;

        for(int i = 0; i < s.size(); i++) {
            int index = s[i] - 'A';
            if(arpabat[index] != -1){
                if(arpabat[index] == rank)
                    rank++;
                else
                    return;

            }
        }
        answer++;
    });

    return answer;
}