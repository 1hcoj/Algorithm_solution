#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    queue1.insert(queue1.end(),queue2.begin(),queue2.end());
    long long sum = 0,sum_temp = 0;
    for (int i = 0;i<queue1.size();i++){
        long long n = queue1[i];
        if (i < queue2.size() - 1) sum_temp += n;
        sum += n;
    }
    if (sum % 2 == 1) return -1;
    long long half = sum /2;
    int i = 0;
    int j = queue2.size() - 1;
    for (;j < queue1.size() - 1;j++){
        sum_temp += queue1[j];
        while (i < queue1.size() && sum_temp > half){
            sum_temp -= queue1[i++];
        }
        if (sum_temp == half) {
            answer = i + (j - (queue2.size() - 1));
            return answer;
        }
    }
    
    return answer;
}