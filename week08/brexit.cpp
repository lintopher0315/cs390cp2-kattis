#include <bits/stdc++.h>

using namespace std;

const int MN=2e5+1;
vector<int> adj[MN];
int am[MN];
bool v[MN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int c, p, x, l, a, b;
    cin >> c >> p >> x >> l;
    if (x==l) {
        cout << "leave";
        return 0;
    }
    for (int i=0; i<p; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        ++am[a];
        ++am[b];
    }
    queue<int> q;
    q.push(l);
    v[l]=1;
    while (!q.empty()) {
        int t=q.front(); q.pop();
        for (int a : adj[t]) {
            if (v[a]) continue;
            if (--am[a]<=adj[a].size()/2) {
                if (a==x) {
                    cout << "leave";
                    return 0;
                }
                q.push(a);
                v[a]=1;
            }
        }
    }
    cout << "stay";
}

