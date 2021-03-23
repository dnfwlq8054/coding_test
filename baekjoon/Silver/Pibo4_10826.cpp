#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

string sum_string(string a, string b) {
	int cnt = 0;
	int len = abs((int)a.size() - (int)b.size());
	string temp = "";

	for (int i = 0; i < len; i++)
		temp += "0";

	if (a.size() > b.size())
		b = temp + b;
	else
		a = temp + a;

	temp = "";
	for (int i = a.size() - 1; i > -1; i--) {
		int num1 = a[i] - '0';
		int num2 = b[i] - '0';
		int sum = num1 + num2 + cnt;
		
		cnt = 0;

		if (sum < 10) {
			//temp.push_back(sum + '0');
			temp += to_string(sum);
		}
		else {
			cnt = 1;
			//temp.push_back((sum % 10) + '0');
			temp += to_string(sum % 10);
		}
	}

	if (cnt == 1)
		temp += "1";

	reverse(temp.begin(), temp.end());

	return temp;
}

int main() {
	int N;
	cin >> N;
	if (N == 0) {
		cout << 0 << endl;
		return 0;
	}

	string dp[10010];
	dp[0] = "0";
	dp[1] = "1";


	for (int i = 2; i <= N; i++) {
		dp[i] = sum_string(dp[i - 1], dp[i - 2]);
	}

	cout << dp[N] << endl;

	return 0;
}