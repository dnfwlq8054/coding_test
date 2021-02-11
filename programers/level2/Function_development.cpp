// 문제가 개편되었습니다. 이로 인해 함수 구성이나 테스트케이스가 변경되어, 과거의 코드는 동작하지 않을 수 있습니다.
// 새로운 함수 구성을 적용하려면 [코드 초기화] 버튼을 누르세요. 단, [코드 초기화] 버튼을 누르면 작성 중인 코드는 사라집니다.
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer, v;
    int count = 0, max = 0;
    
    for(int i = 0; i < speeds.size(); i++){
        int num = 100 - progresses[i];
        if(num % speeds[i] == 0)
            v.emplace_back(num / speeds[i]);
        else
            v.emplace_back((num / speeds[i]) + 1);
        
        if(max < v[i]){
            answer.emplace_back(count);
            count = 1;
            max = v[i];
        }else{
            count++;
        }
    }
    answer.emplace_back(count);
    answer.erase(answer.begin());
    return answer;
}