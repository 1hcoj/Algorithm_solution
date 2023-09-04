#include <iostream>
#include <vector>

using namespace std;
long long min_value = -1;
int N,start_node;
vector<vector<int>> graph;
vector<int> visited;
void solution(int depth,int node,long long weight) {
	if (depth == N && graph[node][start_node]){
        if (min_value == -1) min_value = weight + graph[node][start_node];
        else min_value = min(min_value, weight + graph[node][start_node]);
	}
	for (int i = 0; i < N; i++) {
		if (!visited[i] && graph[node][i]) {
			visited[i] = 1;
			solution(depth + 1, i, weight + graph[node][i]);
			visited[i] = 0;
		}
	}
}

int main() {
	cin >> N;
	graph = vector<vector<int>>(N, vector<int>(N));
	visited = vector<int>(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		start_node = i;
		visited[i] = 1;
		solution(1, i, 0);
		visited[i] = 0;
	}
	cout << min_value;
}