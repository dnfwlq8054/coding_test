#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <random>
#include <map>
#include <set>

#pragma warning(disable: 4996)

using namespace std;

class tree {
public:
	tree() {}
	tree(int _num) : num(_num) {
		left = NULL;
		right = NULL;
	}

	void insert(int n) {
		if (n < num) {
			if (left == NULL) {
				left = new tree(n);
				return;
			}
			else {
				return left->insert(n);
			}
		}
		else {
			if (right == NULL) {
				right = new tree(n);
				return;
			}
			else {
				return right->insert(n);
			}
		}
	}

	void find() {
		if (left != NULL)
			left->find();
		if (right != NULL)
			right->find();
		cout << num << endl;
	}
private:
	int num;
	tree* left;
	tree* right;
};

int main() {
	int N, a, b, M, c, d, T, K, W;
	int x, y, node_cost;
	int flag = 1;
	int answer = 0;
	
	cin >> N;
	tree t(N);

	while (cin >> N) {
		if (N == EOF) break;
		t.insert(N);
	}

	t.find();
	return 0;
}