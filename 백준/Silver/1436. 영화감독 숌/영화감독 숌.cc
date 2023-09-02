#include <iostream>
#include <string>

using namespace std;

int main(){
    int N;
    cin >> N;
    int answer =0;
    for (int i =  666; ;i++){
        string i_str = to_string(i);
        if (i_str.find("666") != -1) N -= 1;
        if (!N) {
            answer = i; break;}
    }
    cout << answer <<'\n';
}