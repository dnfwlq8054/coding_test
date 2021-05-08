#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    set<int> s;
    for(size_t i = 0; i < nums.size(); i++) s.emplace(nums[i]);
    
    if(nums.size() / 2 >= s.size()) return s.size();
    else return nums.size() / 2;
 
}