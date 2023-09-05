#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

string order;
vector<int> course_all;
vector<map<string, int>> menu_list;
void solution(int depth, int node, string menu) {
    if (depth > course_all[course_all.size() - 1]) return;
    for (int i = 0; i < course_all.size();i++) {
        int c = course_all[i];
        if (depth == c) {
            menu_list[i][menu]++;
            break;
        }
    }
    for (int i = node; i < order.size(); i++) {
        solution(depth + 1, i + 1, menu + order[i]);
    }

}

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    course_all = course;
    menu_list = vector<map<string, int>>(course.size(), map<string, int>());
    for (string o : orders) {
        sort(o.begin(),o.end());
        order = o;
        solution(0, 0, "");
    }
    for (int i = 0; i < menu_list.size(); i++) {
        vector<pair<string, int>> temp(menu_list[i].begin(), menu_list[i].end());
        sort(temp.begin(), temp.end(), cmp);
        int max_value = temp[0].second;
        if (max_value > 1){
            for (pair<string, int> t : temp) {
                if (t.second == max_value) answer.push_back(t.first);
            }    
        }
        
    }
    sort(answer.begin(), answer.end());
    return answer;
}