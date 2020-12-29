#include <iostream>
#include <string>

int main(){
    std::string s;
    std::cin >> s;
    int arr[26] = {0,};
    for(size_t i = 0; i < s.size(); i++){
        int n = std::tolower(s[i]) - 'a';
        arr[n]++;
    }
    int m = 0, num, index;
    for(int i = 0; i < 26; i++){
        if(m == arr[i]){
            num = m;
        }
        if(m < arr[i]){ 
            m = arr[i];
            index = i;
        }
    }
    if(num == m) printf("?");
    else printf("%c", index + 'A');
}