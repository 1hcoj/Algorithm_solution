#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <math.h>
using namespace std;

int main() {
	int n = 1;
	while (true) {
		cin >> n; if (!n) break;
		vector<int> vc(n);
		for (int i = 0; i < n; i++) {
			cin >> vc[i];
		}
		stack<int> s;
		sort(vc.begin(), vc.end());
		for (int num : vc) {
			if (!num) s.push(num);
			else break;
		}
		int num1 = vc[s.size()];
		int num2 = vc[s.size() + 1];
		num1 = num1 * pow(10, s.size() / 2 + s.size() % 2);
		num2 = num2 * pow(10, s.size() / 2);
		for (int i = 0 + s.size() + 2; i < vc.size(); i++) {
			if (i % 2 == 0) num1 = num1 * 10 + vc[i];
			else num2 = num2 * 10 + vc[i];
		}
		cout << num1 + num2 << '\n';
	}
}