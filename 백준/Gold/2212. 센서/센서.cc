#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int n, k;
	cin >> n >> k;
	vector<int> sensers(n);
	for (int i = 0; i < n; i++) {
		cin >> sensers[i];
	}
	vector<int> diffs;
	sort(sensers.begin(), sensers.end());
	long long distance = sensers[n-1] - sensers[0];
	for (int i = 0; i < n - 1; i++) {
		int diff = sensers[i + 1] - sensers[i];
		diffs.push_back(diff);
	}
	if (k >= n) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < k-1; i++) {
		distance -= *max_element(diffs.begin(), diffs.end());
		diffs.erase(max_element(diffs.begin(), diffs.end()));
	}
	cout << distance;
}