#include <iostream>
#include <vector>

using namespace std;

int max3(int a,int b,int c){
    a = (a > b)? a:b;
    return (a > c) ? a:c;
}
int min3(int a,int b,int c){
    a = (a < b)? a: b;
    return (a < c)? a : c;
}
int main() {
    int n,a,b,c,temp_0,temp_2;
    cin >> n;
    vector<int> maxDP(3),minDP(3);
    cin >> a >> b >> c;
    maxDP[0] = a; maxDP[1] = b; maxDP[2] = c;
    minDP[0] = a; minDP[1] = b; minDP[2] = c;

    for (int i=1;i<n;i++){
        cin >> a >> b >> c;

        temp_0 = maxDP[0]; temp_2 = maxDP[2];
        maxDP[0] = max(maxDP[0],maxDP[1]) + a;
        maxDP[2] = max(maxDP[1],maxDP[2]) + c;
        maxDP[1] = max3(temp_0,maxDP[1],temp_2) + b;

        temp_0 = minDP[0]; temp_2 = minDP[2];
        minDP[0] = min(minDP[0],minDP[1]) + a;
        minDP[2] = min(minDP[1],minDP[2]) + c;
        minDP[1] = min3(temp_0,minDP[1],temp_2) + b;
    }
    cout << max3(maxDP[0],maxDP[1],maxDP[2]) << ' ' << min3(minDP[0],minDP[1],minDP[2]) << endl;
}
