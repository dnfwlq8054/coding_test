#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string s) {
    string result = "", temp = "";
    map<string, char> m;
    m["zero"] = '0'; m["one"] = '1'; m["two"] = '2'; m["three"] = '3'; m["four"] = '4';
    m["five"] = '5'; m["six"] = '6'; m["seven"] = '7'; m["eight"] = '8'; m["nine"] = '9';

    for(auto& c : s){
        if(c >= '0' && c <= '9') result += c;
        else temp += c;
        
        if(m[temp] >= '0'){
            result += m[temp];
            temp = "";
        }
    }

    return stoi(result);
}