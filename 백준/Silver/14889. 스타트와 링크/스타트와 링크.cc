#include <iostream>
#include <vector>

using namespace std;

int N;
int min_value = INT16_MAX;

vector<int> team;
vector<vector<int>> power;

void solution(int depth,int node) {
	if (depth == N / 2) {
		int start_total = 0, link_total = 0;
		for (int i = 0; i < N - 1; i++) {
			if (team[i]) {
				for (int j = i + 1; j < N; j++) {
					if (team[j]) {
						start_total += power[i][j];
						start_total += power[j][i];
					}
				}
			}
			else {
				for (int j = i + 1; j < N; j++) {
					if (!team[j]) {
						link_total += power[i][j];
						link_total += power[j][i];
					}
				}
			}
		}

		int value = abs(start_total - link_total);
		min_value = (min_value < value) ? min_value : value;
		return;
	}
	for (int i = node; i < N; i++) {
		team[i] = 1;
		solution(depth + 1, i + 1);
		team[i] = 0;
	}
}

int main() {
	cin >> N;
	power = vector<vector<int>>(N, vector<int>(N));
	team = vector<int>(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> power[i][j];
		}
	}
	solution(0, 0);
	cout << min_value;
}