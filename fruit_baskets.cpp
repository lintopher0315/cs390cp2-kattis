#include <bits/stdc++.h>

using namespace std;

int ans=0;

void dfs(vector<int>& v, int t, int i) {
    if (t>=200) return;
    if (i==v.size()) {
        ans+=t;
        return;
    }
    dfs(v, t+v[i], i+1);
    dfs(v, t, i+1);
}

int main() {
    int n;
    cin >> n;
    long long p=pow(2, n-1), tot=0;
    vector<int> v(n);
    for (int i=0; i<n; ++i) {
        cin >> v[i];
        tot+=p*v[i];
    }
    sort(v.begin(), v.end());
    dfs(v, 0, 0);
    cout << tot-ans;
}

