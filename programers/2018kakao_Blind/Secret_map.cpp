#include <string>
#include <vector>
#include <bitset>
#include <iostream>
 
using namespace std;
 
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    int len = 16 - n;
    
    for(int i = 0; i < n; i++){
        bitset<16> bit(arr1[i] | arr2[i]);
        string temp = bit.to_string();
        string cp = "";
        for(int j = len; j < temp.size(); j++)
            if(temp[j] == '1')
                cp += '#';
            else
                cp += ' ';
        
        answer.emplace_back(cp);
    }
    
    return answer;
}
