#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, p, n;
    cin >> t;
    while (t--) {
        cin >> p >> n;
        vector<int> v(n); 
        int m=0;
        for (int i=0; i<n; ++i) {
            cin >> v[i];
            m=max(m, v[i]);
        }
        int ans=INT_MAX, am=INT_MAX;
        vector<int> dp(p+m+1, INT_MAX);
        dp[0]=0;
        for (int i=0; i<n; ++i) {
            for (int j=p+m; j>=v[i]; --j) {
                if (dp[j-v[i]]!=INT_MAX) {
                    dp[j]=min(dp[j], dp[j-v[i]]+1);
                    if (j>=p && j<=ans) {
                        am=j==ans ? min(am, dp[j]) : dp[j];
                        ans=j;
                    }
                }
            }
        }
        cout << ans << " " << am << "\n";
    }
}

