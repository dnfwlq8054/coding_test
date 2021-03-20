#include <iostream>

using namespace std;

int main()
{
	int N, cow, locate;
	int check[101];
	int count = 0;

	for (int i = 0; i < 101; i++) {
		check[i] = 99;
	}

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cow; cin >> locate;
		if (check[cow] != 99) {
			if (check[cow] != locate)
				count++;
			check[cow] = locate;
		}
		else
			check[cow] = locate;
	}

	cout << count << endl;

	return 0;
}