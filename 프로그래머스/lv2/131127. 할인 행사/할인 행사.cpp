#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int num = 10;
    map<string, int> discount_map;
    for (int i = 0; i < num; i++) {
        string d = discount[i];
        discount_map[d]++;
    }
    for (int i = 0; i <= discount.size() - num; i++) {
        bool toggle = true;
        for (int j = 0; j < want.size(); j++) {
            if (discount_map[want[j]] != number[j]) {
                toggle = false; break;
            }
        }
        if (toggle) answer++;
        if (i != discount.size() - num) { discount_map[discount[i]]--; discount_map[discount[num + i]]++; }
    }
    return answer;
}

int main() {
    vector<string> want = { "banana","apple","rice","pork","pot" };
    vector<int> number = { 3,2,2,2,1 };
    vector<string> discount = 
    { "chicken", "apple", "apple", "banana", "rice", "apple", "pork", 
        "banana", "pork", "rice", "pot", "banana", "apple", "banana" };
    int answer = solution(want, number, discount);
    cout << answer;

}