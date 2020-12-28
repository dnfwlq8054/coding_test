#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>|
#include <random>
#pragma warning(disable: 4996)

using namespace std;
int answer = 1;

class Trie {
private:
	Trie * number[10];

public:
	Trie() {
		for (int i = 0; i < 10; i++) {
			number[i] = NULL;
		}
	}

	~Trie() {
		for (int i = 0; i < 10; i++) {
			if(number[i] != NULL)
				delete number[i];
		}
	}

	void insert(const char * c) {
		if (*c == '\0') return;

		int n = *c - '0';

		if (number[n] == NULL) {
			number[n] = new Trie();
			number[n]->insert(c + 1);
		}
		else {
			number[n]->insert(c + 1);
		}
	}

	bool find(const char* c) {
		if (*c == '\0') {
			for (int i = 0; i < 10; i++) {
				if (number[i] != NULL)
					return false;
			}
			return true;
		}
		int n = *c - '0';

		return number[n]->find(c + 1);
	}
};



int main() {
	int N, a, b, M;
	int MAX = 1;
	string s;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> M;
		vector<string> v(M);
		Trie *trie = new Trie();

		for (int j = 0; j < M; j++) {
			cin >> v[j];
			trie->insert(v[j].c_str());
		}

		bool flag = true;
		for (int j = 0; j < M; j++) {
			if (!trie->find(v[j].c_str())) {
				flag = false;
				break;
			}
		}

		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

		delete trie;
	}


	return 0;
}