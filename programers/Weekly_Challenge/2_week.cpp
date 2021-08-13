#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";
    
    for(int i = 0; i < scores.size(); i++){
        int myNum = 0, max_score = 0, sum = 0;
        int min_score = 999;
        map<int, int> m;
      
        for(int j = 0; j < scores[i].size(); j++){
            if(i == j) myNum = scores[i][j];
            max_score = max(max_score, scores[j][i]);
            min_score = min(min_score, scores[j][i]);
            sum += scores[j][i];
            m[scores[j][i]]++;
        }

        int score = 0;
        if((max_score == myNum && m[myNum] == 1) || (min_score == myNum && m[myNum] == 1)) {
            sum -= myNum;
            score = sum / (scores.size() - 1);
        } else score = sum / scores.size();

        if(score >= 90) answer += 'A';
        else if(score >= 80) answer += 'B';
        else if(score >= 70) answer += 'C';
        else if(score >= 50) answer += 'D';
        else answer += 'F';
    }
    
    return answer;
}