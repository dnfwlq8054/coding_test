#include <iostream>

using namespace std;

int main(){
    int N;
    int dp_max[3], dp_min[3]; int input[3];
    int temp_0, temp_2;
    cin >> N;
    scanf("%d %d %d", &dp_max[0], &dp_max[1], &dp_max[2]);
    dp_min[0] = dp_max[0]; dp_min[1] = dp_max[1]; dp_min[2] = dp_max[2];
    
    for(int i = 1; i < N; i++){
        scanf("%d %d %d", &input[0], &input[1], &input[2]);
        temp_0 = dp_max[0]; temp_2 = dp_max[2];
        
        dp_max[0] = max(dp_max[0], dp_max[1]) + input[0];
        dp_max[2] = max(dp_max[2], dp_max[1]) + input[2];
        dp_max[1] = max(dp_max[1], max(temp_0, temp_2)) + input[1];
        
        temp_0 = dp_min[0]; temp_2 = dp_min[2];
        
        dp_min[0] = min(dp_min[0], dp_min[1]) + input[0];
        dp_min[2] = min(dp_min[2], dp_min[1]) + input[2];
        dp_min[1] = min(dp_min[1], min(temp_0, temp_2)) + input[1];
    }
    
    cout << max(dp_max[0], max(dp_max[1], dp_max[2])) << " ";
    cout << min(dp_min[0], min(dp_min[1], dp_min[2])) << endl;
    return 0;
}