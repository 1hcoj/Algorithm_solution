#include <iostream>
#include <vector>
#include <string>

using namespace std;

int m;

void dfs(vector<int>nums, int length, int history, string ans) {
	if (length == m) cout << ans << '\n';
	else {
		for (int i = 0; i < nums.size() ; i++) {
			if (nums[i] > history) {
				vector<int> new_nums = vector<int>(nums.begin(), nums.begin() + i);
				if (i != nums.size() - 1) {
					new_nums.insert(new_nums.end(), nums.begin() + i + 1, nums.end());
				}
				dfs(new_nums, length + 1, nums[i], ans + to_string(nums[i]) + ' ');
			}
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
	dfs(nums, 0, 0, "");
}