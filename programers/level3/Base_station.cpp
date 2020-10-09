#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> stations, int W)
{
    int answer = 0;
    int start = 1;

    for(size_t i = 0; i < stations.size(); i++){
        int end = stations[i] - W;
        if(start >= end){
            start = stations[i] + W + 1;
            continue;
        }

        int quo = (end - start) / ((W * 2) + 1);
        int rem = (end - start) % ((W * 2) + 1);
        if(rem != 0) quo++;

        answer += quo;
        start = stations[i] + W + 1;
    }

    if(start < n + 1){
        int quo = ((n + 1) - start) / ((W * 2) + 1);
        int rem = ((n + 1) - start) % ((W * 2) + 1);
        if(rem != 0) quo++;
        answer += quo;
    }
    
    return answer;
}