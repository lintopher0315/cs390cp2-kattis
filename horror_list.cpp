#include <bits/stdc++.h>

using namespace std;

const int MN=1000;
int dist[MN];
vector<int> adj[MN];

void dfs(int s, int d) {
    dist[s]=d;
    for (int a : adj[s]) {
        if (dist[a]>dist[s]) {
            dfs(a, d+1);
        }
    }
}

int main() {
    int n, h, l, a, b;
    cin >> n >> h >> l;
    for (int i=0; i<n; ++i) dist[i]=INT_MAX;
    vector<int> s;
    while (h--) {
        cin >> a;
        s.push_back(a);
    }
    while (l--) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=0; i<s.size(); ++i) {
        dfs(s[i], 0);
    }
    int ans=0;
    int ind=0;
    for (int i=0; i<n; ++i) {
        if (dist[i]>ans) {
            ans=dist[i];
            ind=i;
        }
    }
    cout << ind;
}
