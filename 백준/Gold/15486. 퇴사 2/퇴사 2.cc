#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n,next;
    long long maxValue=0;
    cin >> n;

    vector<int> T(n+1),P(n+1);
    vector<long long> dp(n+2);

    for(int i =1;i<=n;i++){
        cin >> T[i] >> P[i];
    }

    for (int i=1;i<=n+1;i++){
        maxValue = max(maxValue,dp[i]);
        next = i + T[i];

        if (next <= n+1) dp[next] = max(maxValue + P[i],dp[next]);
    }

    cout << maxValue << endl;
}
