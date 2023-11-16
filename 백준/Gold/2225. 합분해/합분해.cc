#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n,k;
    cin >> n >>k;

    vector<vector<long long>> dp(k+1,vector<long long>(n+1));

    for (int i =0;i<=n;i++){
        dp[1][i] = 1;
    }
    for (int i=1;i<=k;i++){
        dp[i][0] = 1;
    }

    for (int i =2;i<=k;i++){
        for (int j = 1;j<=n;j++){
            dp[i][j] = (dp[i][j-1] + dp[i-1][j]) %1000000000;
        }
    }

    cout << dp[k][n] << endl;
}
