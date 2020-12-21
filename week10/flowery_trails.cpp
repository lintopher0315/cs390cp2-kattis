#include <bits/stdc++.h>

using namespace std;

const int MN=1e5;
vector<pair<int, int>> adj[MN];
vector<pair<int, int>> pa[MN];

void dfs(int s, int& ans, vector<bool>& vi) {
    vi[s]=1;
    for (auto a : pa[s]) {
        ans+=a.second;
        if (vi[a.first]) continue;
        dfs(a.first, ans, vi);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int p, t, a, b, c, ans=0;
    cin >> p >> t;
    vector<int> dist(p, INT_MAX);
    vector<bool> v(p, 0);
    while (t--) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    dist[0]=0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto a=pq.top(); pq.pop();
        if (v[a.second]) continue;
        v[a.second]=1;
        for (auto i : adj[a.second]) {
            int f=i.first, s=i.second;
            if (dist[a.second]+s<dist[f]) {
                dist[f]=dist[a.second]+s;
                pq.push({-dist[f], f});
                pa[f].clear();
                pa[f].push_back({a.second, s});
            }
            else if (dist[a.second]+s==dist[f]) {
                pa[f].push_back({a.second, s});
            }
        }
    }
    vector<bool> vi(p, 0);
    dfs(p-1, ans, vi);
    cout << 2*ans;
}

