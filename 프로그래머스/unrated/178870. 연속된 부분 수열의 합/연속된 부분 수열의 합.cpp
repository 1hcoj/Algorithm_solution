#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2);
    int i = 0;
    int sum = 0;
    priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> av_answer;
    for (int j = 0; j < sequence.size(); j++) {
        sum += sequence[j];
        if (sum == k) av_answer.push({ i,j });
        while (sum > k) {
            sum -= sequence[i++];
            if (sum == k) av_answer.push({ i,j });
        }
    }
    pair<int, int> value = av_answer.top();
    av_answer.pop();
    int min_value = value.second - value.first;
    answer[0] = value.first; answer[1] = value.second;
    while (!av_answer.empty()) {
        pair<int, int> temp = av_answer.top();
        av_answer.pop();
        int length = temp.second - temp.first;
        if (min_value > length) {
            min_value = length;
            answer[0] = temp.first; answer[1] = temp.second;
        }
    }
    return answer;
}
