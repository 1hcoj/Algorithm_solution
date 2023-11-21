#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m,t,cost,memory,sumCost = 0;
    cin >> n >> m;
    vector<pair<int, int>> app(n+1);

    for (int i = 1; i <= n; i++) {
        cin >> app[i].first;
    }
    for (int i = 1; i <= n; i++) {
        cin >> t;
        sumCost += t;
        app[i].second = t;
    }

    vector<vector<int>> dp(n+1,vector<int>(sumCost+1));

    for (int i =1;i<=n;i++){
        for (int j=0;j<=sumCost;j++){
            cost = app[i].second;

            if ( cost <=j )
                dp[i][j] = max(dp[i-1][j],dp[i-1][j - cost] + app[i].first);
            else
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
    }

    for (int i =0;i<=sumCost;i++){
        if (dp[n][i] >= m) {
            cout << i << endl;
            break;
        }
    }
}