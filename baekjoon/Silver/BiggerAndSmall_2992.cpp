#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <iostream>
#include <stack>
#include <string>

#pragma warning(disable: 4996)

using namespace std;

int main(){

    string s;
    string temp;
    int answer = 99999999;
    cin >> s;
    temp = s;

    
    sort(s.begin(), s.end());
    do {
        if (temp < s) 
            answer = min(answer, stoi(s));
    } while (next_permutation(s.begin(), s.end()));

    if (answer == 99999999)
        cout << "0" << endl;
    else
        cout << answer << endl;
   
    return 0;
}