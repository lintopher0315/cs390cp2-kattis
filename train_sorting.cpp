#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; ++i) cin >> v[i];

    int ans=0;
    vector<int> ilis;
    vector<int> dlis;
    for (int i=n-1; i>0; --i) {
        auto it=lower_bound(ilis.begin(), ilis.end(), -v[i]);
        if (it==ilis.end()) ilis.push_back(-v[i]);
        else *it=-v[i];
        it=lower_bound(dlis.begin(), dlis.end(), v[i]);
        if (it==dlis.end()) dlis.push_back(v[i]);
        else *it=v[i];
        int ldist=distance(ilis.begin(), lower_bound(ilis.begin(), ilis.end(), -v[i-1]));
        int ddist=distance(dlis.begin(), lower_bound(dlis.begin(), dlis.end(), v[i-1]));
        ans=max(ans, 1+ldist+ddist);
    }
    cout << (n==1 ? 1 : ans);
}
