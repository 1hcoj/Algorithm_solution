#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    vector<pair<int,int>> items(n+1);
    vector<vector<long long>> dp(n+1,vector<long long>(k+1));
    
    for (int i =1;i<=n;i++){
        cin >> items[i].first >> items[i].second;   // 무게, 가치
    }
    /* 
     * maxWeight : 배낭의 최대 무게
     * items[i].first : 물건의 무게
     * items[i].second : 물건의 가치
     * dp[i][j] : j가 배낭의 최대 무게 & i 물건을 넣을 때, 최대 가능한 배낭의 가치
     * */
    for (int i=1;i<=n;i++){
        for (int maxWeight = 1;maxWeight<=k;maxWeight++){
            if (items[i].first <= maxWeight) dp[i][maxWeight] = max(dp[i-1][maxWeight - items[i].first] +  items[i].second, dp[i-1][maxWeight]);
            else dp[i][maxWeight] = dp[i-1][maxWeight];
        }
    }
    cout << dp[n][k] << endl;
}
