#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    long long result;
    cin >> N;
    vector<vector<vector<long long>>> dp(N+1,(vector<vector<long long>>(N+1,vector<long long>(3))));
    vector<vector<short>> walls(N+1,vector<short>(N+1));

    dp[1][2][0] = 1;

    for (int i =1;i<=N;i++){
        for (int j=1;j<=N;j++){ cin >> walls[i][j]; }
    }

    for (int i=1;i<=N;i++){
        for (int j=3;j<=N;j++){
            if (walls[i][j]) {
                dp[i][j][0] = 0;
                dp[i][j][1] = 0;
                dp[i][j][2] = 0;
            }
            else {
                dp[i][j][0] = dp[i][j-1][0] + dp[i][j-1][2];
                dp[i][j][1] = dp[i-1][j][1] + dp[i-1][j][2];
                if (!walls[i-1][j] && !walls[i][j-1])
                    dp[i][j][2] = dp[i-1][j-1][0] + dp[i-1][j-1][1] + dp[i-1][j-1][2];
            }
        }
    }
    result = dp[N][N][0] + dp[N][N][1] + dp[N][N][2];
    cout << result << endl;
}
