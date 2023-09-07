#include <string>
#include <vector>

using namespace std;

vector<int> answer(2);
vector<vector<int>> my_arr;
void divide_quad(pair<int, int> coordinate, const int size) {
    int value = my_arr[coordinate.first][coordinate.second];
    // coordi.first 는 행 , second 는 열
    if (size == 1) {
        answer[value]++; return;
    }
    bool toggle = true;
    for (int i = coordinate.first; i < coordinate.first + size; i++) {
        if (!toggle) break;
        for (int j = coordinate.second; j < coordinate.second + size; j++) {
            if (value != my_arr[i][j]) {
                toggle = false;
                break;
            }
        }
    }
    if (toggle) answer[value]++;
    else {
        divide_quad(coordinate, size / 2);
        divide_quad({ coordinate.first + size / 2,coordinate.second }, size / 2);
        divide_quad({ coordinate.first ,coordinate.second + size/2}, size / 2);
        divide_quad({ coordinate.first + size / 2,coordinate.second + size/2}, size / 2);
    }
}

vector<int> solution(vector<vector<int>> arr) {
    my_arr = arr;
    divide_quad({ 0,0 }, arr.size());
    return answer;
}