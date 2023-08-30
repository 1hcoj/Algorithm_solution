#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
map<string, int> ans_map;
vector<int> nums;
vector<int> visited;
void solution(int depth, string ans) {
	if (ans_map.find(ans) != ans_map.end()) return;
	if (depth == M) {
		cout << ans << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			solution(depth + 1, ans + to_string(nums[i]) + ' ');
			visited[i] = 0;
			ans_map[ans + to_string(nums[i]) + ' '] = 1;
		}
	}
}

int main() {
	cin >> N >> M;
	nums = vector<int>(N);
	visited = vector<int>(N);
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());
	solution(0, "");
}