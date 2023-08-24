#include <iostream>
#include <vector>
#include <string>

using namespace std;

int m;
void dfs(vector<int> nums, int k, string answer) {
	if (k == m) cout << answer << '\n';

	else {
		for (int i = 0; i < nums.size(); i++) {
			vector<int> new_nums = vector<int>(nums.begin(), nums.begin() + i);
			if (i != nums.size() - 1) {
				new_nums.insert(new_nums.end(), nums.begin() + i + 1, nums.end());
			}
			dfs(new_nums, k + 1, answer + to_string(nums[i]) + ' ');
		}
	}
}

int main() {
	int n;
	cin >> n >> m;
	vector<int> nums;
	for (int i = 1; i <= n; i++) {
		nums.push_back(i);
	}
	dfs(nums, 0, "");
}