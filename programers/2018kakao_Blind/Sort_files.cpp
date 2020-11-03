#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
vector<string> solution(vector<string> files) {
    vector<string> answer;
    map<string, map<int, vector<string>>> m;
    int index = 0;
    for(int i = 0; i < files.size(); i++){
        string head = "";
        string s_num = "";
        int num = 0;
        bool flag = true;
        for(int j = 0; j < files[i].size(); j++){
            if(flag == true){   //head
                if(files[i][j] != ' ' || files[i][j] != '.' || files[i][j] != '-'){
                    if(files[i][j] >= '0' && files[i][j] <= '9'){
                        flag = false;
                        j--;
                    }else
                        head += tolower(files[i][j]);
                }
            }else if(files[i][j] >= '0' && files[i][j] <= '9'){
                if(files[i][j] == '0')  //num
                    continue;
                else{
                    while(true){
                        if(files[i][j] >= '0' && files[i][j] <= '9')
                            s_num += files[i][j];
                        else{
                            num = atoi(s_num.c_str());
                            break;
                        }
                        j++;
                    }
                }          
            }else
                break;
        }
        m[head][num].emplace_back(files[i]);
    }
    for_each(m.begin(), m.end(), [&](pair<string, map<int, vector<string>>> itr){
            for_each(itr.second.begin(), itr.second.end(), [&](pair<int, vector<string>> itr2){
                for(int i = 0; i < itr2.second.size(); i++)
                    answer.emplace_back(itr2.second[i]);
            });
    });    
    return answer;
}