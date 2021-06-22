#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0, count = 0;
    int arr[31] = { 0, };
    
    for(int i = 0; i < lost.size(); i++)
        arr[lost[i]] = 1;
    

    for(int i = 0; i < reserve.size(); i++){
        if(arr[reserve[i]] == 1){
            arr[reserve[i]] = 0;
            reserve[i] = -2;
            count++;
        }
    }
    
    for(int i = 0; i < reserve.size(); i++){
        if(reserve[i] == -2)
            continue;
        
        int right = reserve[i] - 1, left = reserve[i] + 1;
        if(arr[right] == 1){
            count++;
            arr[right]--;
        }else if(arr[left] == 1){
            count++;
            arr[left]--;
        }
    }
  
    answer = n - (lost.size() - count);
    return answer;
}