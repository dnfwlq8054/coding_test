#include <iostream>
#include <map>
#include <string>
#include <cstdio>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	map<string, float> m;
	string str;
	float cnt = 0;

	while (getline(cin, str)) {
		m[str]++;
		cnt++;
	}
	
	for (auto it = m.begin(); it != m.end(); it++) {
		float val = (it->second / cnt) * 100;
		printf("%s %.4f\n", it->first.c_str(), val);
	}

	return 0;
}