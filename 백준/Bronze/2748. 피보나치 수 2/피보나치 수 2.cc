#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    long long answer = 1,b_value=0,temp = 0;
    for (int i =0;i<n-1;i++){
        temp = answer;
        answer += b_value;
        b_value = temp;
    }
    cout << answer;
}