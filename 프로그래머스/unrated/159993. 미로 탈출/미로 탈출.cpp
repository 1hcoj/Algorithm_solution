#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> ds;

int bfs(vector<string> maps, pair<int, int> node, int distance) {
    ds = vector<int>(maps[0].size() * maps.size(), -1);
    queue<pair<int, int>> q;
    q.push(node);
    ds[node.first * maps[0].size() + node.second] = 0;
    vector<pair<int, int>> moves = { {1,0},{-1,0},{0,-1},{0,1} };
    while (!q.empty()) {
        pair<int, int> n = q.front();
        q.pop();
        for (pair<int, int> m : moves) {
            int i = n.first + m.first;
            int j = n.second + m.second;

            int t2o = i * maps[0].size() + j;
            int d = ds[n.first * maps[0].size() + n.second] + 1;
            if (i >= 0 && i < maps.size() && j >= 0 && j < maps[0].size()) {
                switch (maps[i][j])
                {
                case'S':case 'O': {
                    if (t2o >= 0 && t2o < ds.size() && ds[t2o] == -1) {
                        ds[t2o] = d;
                        q.push({ i,j });
                    }
                    break;
                }
                case 'X': {
                    break;
                }
                case 'E': {
                    if (distance) return d;
                    else {
                        if (t2o >= 0 && t2o < ds.size() && ds[t2o] == -1) {
                            ds[t2o] = d;
                            q.push({ i,j });
                        }
                    }
                    break;
                }
                case 'L': {
                    if (ds[t2o] == -1) {
                        int result = bfs(maps,{i,j},d);
                        if (result == -1) return -1;
                        else return d + result;
                    }
                    break;
                }
                }
            }
        }
    }
    return -1;
}

int solution(vector<string> maps) {
    int answer = 0;
    pair<int, int> node;
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[i].size(); j++) {
            if (maps[i][j] == 'S') {
                node = { i,j };
                break;
            }
        }
    }
    answer = bfs(maps, node, 0);
    return answer;
}