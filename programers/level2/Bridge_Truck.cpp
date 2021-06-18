#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> trucks) {
    queue<pair<int, int>> weightAndTime;
    int accumWeight = 0, time = 0, count = 0;
    int truckCount = trucks.size();
    
    while(true){
        if(time - weightAndTime.front().second == bridge_length){
	        accumWeight -= weightAndTime.front().first;
            weightAndTime.pop();
        }
        
        if(count < truckCount && accumWeight + trucks[count] <= weight){
            weightAndTime.emplace(trucks[count], time);
            accumWeight += trucks[count];
            count++;
        }
        
        time++;
        if(count == truckCount && weightAndTime.empty()){
            break;
        }
    }
    
    return time;
}