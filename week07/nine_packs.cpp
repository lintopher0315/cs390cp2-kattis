#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, b, t=0, t2=0;
    cin >> h;
    vector<int> v1(h);
    for (int i=0; i<h; ++i) {
        cin >> v1[i];
        t+=v1[i];
    }
    cin >> b;
    vector<int> v2(b); 
    for (int i=0; i<b; ++i) {
        cin >> v2[i];
        t2+=v2[i];
    }
    t=max(t, t2);
    vector<int> dp(t+1, t+1), dp2(t+1, t+1);
    dp[0]=1;
    dp2[0]=1;
    for (int i=0; i<h; ++i) {
        for (int j=t; j>=v1[i]; --j) {
            dp[j]=min(dp[j], dp[j-v1[i]]+1);
        }
    }
    int ans=t+1;
    for (int i=0; i<b; ++i) {
        for (int j=t; j>=v2[i]; --j) {
            dp2[j]=min(dp2[j], dp2[j-v2[i]]+1);
            if (dp2[j] && dp[j]) {
                ans=min(ans, dp2[j]+dp[j]-2);
            }
        }
    }
    if (ans==t+1) cout << "impossible";
    else cout << ans;
}

