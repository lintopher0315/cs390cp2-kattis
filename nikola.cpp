#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; ++i) {
        cin >> v[i];
    }
    vector<vector<int>> dp(n, vector<int>(n, -1));
    dp[0][0]=0;
    for (int i=1; i<n; ++i) {
        for (int j=n-1; ~j; --j) {
            if (j-i>=0) {
                if (dp[j-i][i-1]>=0) {
                    dp[j][i]=dp[j][i]>=0 ? min(dp[j][i], dp[j-i][i-1]+v[j]) : dp[j-i][i-1]+v[j];
                }
            }
            if (j+i<n) {
                if (dp[j+i][i]>=0) {
                    dp[j][i]=dp[j][i]>=0 ? min(dp[j][i], dp[j+i][i]+v[j]) : dp[j+i][i]+v[j];
                }
            }
        }
    }
    int ans=INT_MAX;
    for (int i=0; i<n; ++i) {
        if (dp[n-1][i]<0) continue;
        ans=min(ans, dp[n-1][i]);
    }
    cout << ans;
}
