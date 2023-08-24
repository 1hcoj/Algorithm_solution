#include <iostream>
#include <vector>

using namespace std;

int N;
int num = 0;
vector<int> visited;

bool is_promising(int i) {
	for (int k = 0; k < i; k++) {
		if (visited[k] == visited[i] || i - k == abs(visited[i] - visited[k])) {
			return false;
		}
	}
	return true;
}

int n_queen(int i) {
	int result = 0;
	if (i == N) {
		return 1;
	}
	for (int j = 0; j < N; j++) {
		visited[i] = j;
		if (is_promising(i)) {
			result +=  n_queen(i + 1);
		}
	}
	return result;
}
int main() {
	cin >> N;
	visited = vector<int>(15);
	cout << n_queen(0);
	
}