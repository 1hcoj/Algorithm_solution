#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int N;
bool toggle = false;
vector<long long> nums;
vector<int> visited;
vector<long long>answers(101);

void solution(int depth) {
	if (depth == N) {
		toggle = true;
		for (int i = 1; i <= N; i++) {
			cout << answers[i] << ' ';
		}
		return;
	}
	auto multi_index = find(nums.begin(), nums.end(),answers[depth] *2);
	// 1. 2배가 존재하는 경우
	if (multi_index != nums.end()) {
		int index = multi_index - nums.begin();
		if (!visited[index]) {
			visited[index] = 1;
			answers[depth + 1] = nums[index];
			solution(depth + 1);
			answers[depth + 1] = 0;
			visited[index] = 0;
		}
	}
	// 2. / 3이 존재하는 경우 
	if (answers[depth] % 3 == 0) {
		auto div_index = find(nums.begin(), nums.end(), answers[depth] / 3);
		if (div_index != nums.end()) {
			int index = div_index - nums.begin();
			if (!visited[index]) {
				visited[index] = 1;
				answers[depth + 1] = nums[index];
				solution(depth + 1);
				answers[depth + 1] = 0;
				visited[index] = 0;
			}
		}
	}
	return;
}

int main() {
	cin >> N;
	nums = vector<long long>(N);
	visited = vector<int>(N);
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}
	for (int i = 0; i < N; i++) {
		visited[i] = 1;
		answers[1] = nums[i];
		solution(1);
		answers[1] = 0;
		visited[i] = 0;
		if (toggle) break;
	}
}
