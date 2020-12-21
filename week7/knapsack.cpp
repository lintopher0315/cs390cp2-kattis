#include <bits/stdc++.h>

using namespace std;

int main() {
    int c, n;
    while (cin >> c && cin >> n) {
        vector<vector<int>> dp(n+1, vector<int>(c+1, 0));
        vector<pair<int, int>> v(n);
        int a, b;
        for (int i=1; i<n+1; ++i) {
            cin >> a >> b;
            v[i-1].first=a;
            v[i-1].second=b;
            for (int j=1; j<=c; ++j) {
                if (b>j) dp[i][j]=dp[i-1][j];
                else dp[i][j]=max(dp[i-1][j], dp[i-1][j-b]+a);
            }
        }
        vector<int> ans;
        a=n, b=c;
        while (dp[a][b]) {
            if (dp[a-1][b]!=dp[a][b]) {
                ans.push_back(a-1);
                b-=v[a-1].second; 
            }
            --a;
        }
        cout << ans.size() << "\n";
        for (int i : ans) cout << i << " ";
        cout << "\n";
    }
}

