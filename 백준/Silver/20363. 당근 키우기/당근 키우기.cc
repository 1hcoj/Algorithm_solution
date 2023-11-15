#include <iostream>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    int p = (N > M) ? M / 10 : N / 10;
    int result = N + M + p;
    cout << result << endl;
}