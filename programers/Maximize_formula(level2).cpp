#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

void strtok(vector<long long> &v_num, vector<char> &v_op, const char *s){
    string temp = "";
    
    while(*s != '\0'){
        if(*s == '*' || *s == '+' || *s == '-'){
            v_op.emplace_back(*s);
            v_num.emplace_back(stoll(temp));
            temp = "";
        }
        else
            temp += *s;
        s = s + 1;
    }
    v_num.emplace_back(stoll(temp));
}

long long calc(char op, long long num1, long long num2) { 
    switch (op){
        case '*' :
        return num1 * num2;
        
        case '+' :
        return num1 + num2;
            
        case '-' :
        return num1 - num2;
    }
}


long long solution(string expression) {
    long long answer = 0;
    vector<long long> s_num;
    vector<char> s_op;
    strtok(s_num, s_op, expression.c_str());
    
    string op = "+-*";
    sort(op.begin(), op.end());
    
    do{
        vector<long long> v_num = s_num;
        vector<char> v_op = s_op;
        for(size_t i = 0; i < op.size(); i++){
            vector<long long> cp_num;
            vector<char> cp_op;
            cp_num.emplace_back(v_num[0]);
            
            for(size_t j = 0; j < v_op.size(); j++){
                if(v_op[j] == op[i]){
                    long long sum = calc(op[i], cp_num.back(), v_num[j + 1]);
                    cp_num.back() = sum;
                }
                else{
                    cp_num.emplace_back(v_num[j + 1]);
                    cp_op.emplace_back(v_op[j]);
                }
            }
            v_num = move(cp_num);
            v_op = move(cp_op);
        }
        answer = max(answer, abs(v_num[0]));
        
    }while(next_permutation(op.begin(), op.end()));
    
    return answer;
}