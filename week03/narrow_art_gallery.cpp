#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v(n+1);
    int tot=0;
    for (int i=0; i<=n; ++i) {
        cin >> v[i].first >> v[i].second;
        tot+=v[i].first+v[i].second;
    }
    int dp[201][201][3];    // 0 - left; 1 - right; 2 - none
    for (int i=0; i<=n; ++i) {
        for (int j=0; j<=i; ++j) {
            if (j) {
                dp[i][j][2]=max({dp[i-1][j][0], dp[i-1][j][1], dp[i-1][j][2]});
                dp[i][j][1]=max(dp[i-1][j-1][2], dp[i-1][j-1][1])-v[i-1].second;
                dp[i][j][0]=max(dp[i-1][j-1][2], dp[i-1][j-1][0])-v[i-1].first;
            }
            else {
                dp[i][0][0]=tot;
                dp[i][0][1]=tot;
                dp[i][0][2]=tot;
            }
        }
    }
    cout << max({dp[n][k][0], dp[n][k][1], dp[n][k][2]});
}

