#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    vector<string> week = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    vector<int> month = {31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 365};
    int idx = a != 1 ? (month[a - 2] + (b - 1)) % 7 : (b - 1) % 7;
    return week[idx];
}