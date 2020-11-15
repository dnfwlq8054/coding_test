#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

void bit_calc(string& s, const int& bit, int num, const int& m, const int& p, int& count){
    string temp = "";
    
    if(bit == 2){
        while(num != 0){
            int res = num % bit;
            num /= bit;
            temp += to_string(res);
        }
    }else{
        while(num != 0){
            int res = num % bit;
            num /= bit;
            if(res == 10) temp += 'A';
            else if(res == 11) temp += 'B';
            else if(res == 12) temp += 'C';
            else if(res == 13) temp += 'D';
            else if(res == 14) temp += 'E';
            else if(res == 15) temp += 'F';
            else temp += to_string(res);
        }
    }

    for_each(temp.rbegin(), temp.rend(), [&](char c){
        if(count % m == p){
            s += c; 
        }
        count++;
    });
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    int count = 1;
    
    if(p == 1)
        answer += '0'; 
    p--;
    
    for(int i = 1; i < 200000000; i++){
        bit_calc(answer, n, i, m, p, count);
        
        if(answer.size() == t)
            break;
        else if(answer.size() > t){
            int len = answer.size() - t;
            for(int j = 0; j < len; j++)
                answer.pop_back();
            break;
        }
    }
    
    return answer;
}