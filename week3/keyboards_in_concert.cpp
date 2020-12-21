#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, a, b;
    cin >> n >> m;
    unordered_set<int> us[1001];
    for (int i=0; i<n; ++i) {
        cin >> a;
        while (a--) {
            cin >> b;
            us[b].insert(i);
        }
    }
    vector<vector<int>> dp(n, vector<int>(m+1, 0));
    int mi=0;
    for (int i=1; i<=m; ++i) {
        cin >> a;
        int tmin=INT_MAX;
        for (int j=0; j<n; ++j) {
            if (us[a].find(j)==us[a].end()) {
                dp[j][i]=INT_MAX;
            }
            else {
                dp[j][i]=min(mi+1, dp[j][i-1]);
            }
            tmin=min(tmin, dp[j][i]);
        }
        mi=tmin;
    }
    cout << mi;
}

