#include <bits/stdc++.h>

using namespace std;

const int MN=1e4+1;
vector<int> adj[MN];
int am[MN];
bool v[MN];
int ans;

void dfs(int s) {
    v[s]=1;
    int c=0;
    for (int a : adj[s]) {
        if (!v[a]) dfs(a);
        ans+=abs(am[a]);
        c+=am[a];
    }
    am[s]=c+am[s]-1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b, c, d;
    for (int t=0; t<10; ++t) {
        cin >> n;
        if (!n) return 0;
        for (int i=0; i<n; ++i) {
            cin >> a >> b >> c;
            am[a]=b;
            while (c--) {
                cin >> d;
                adj[a].push_back(d);
            }
        }
        for (int i=1; i<=n; ++i) {
            if (!v[i]) dfs(i);
        }
        cout << ans << "\n";
        for (vector<int>& v : adj) v.clear();
        fill(am, am+MN, 0);
        fill(v, v+MN, 0);
        ans=0;
    }
}

