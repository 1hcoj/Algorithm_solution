#include <string>
#include <vector>

using namespace std;

vector<int> answer(2);
void recurr(string s) {
    if (s == "1") return;
    int one_num = 0;
    for (char c : s) {
        if (c == '1') one_num++;
    }
    answer[1] += s.size() - one_num;
    s = "";
    while (one_num >= 1) {
        int rest = one_num % 2;
        one_num /= 2;
        s = to_string(rest) + s;
    }
    answer[0]++;
    recurr(s);
}

vector<int> solution(string s) {
    recurr(s);
    return answer;
}