#include <bits/stdc++.h>

using namespace std;

const int MN=1e5;
vector<int> adj[MN];
bool dir[MN];
bool v[MN];

void dfs(int s, bool d) {
    dir[s]=d;
    v[s]=1;
    for (int a : adj[s]) {
        if (!v[a]) dfs(a, !d);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b;
    cin >> n;
    vector<pair<int, int>> o(n-1);
    for (int i=0; i<n-1; ++i) {
        cin >> a >> b;
        o[i]={a-1, b-1};
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    dfs(0, 0);
    for (int i=0; i<n-1; ++i) {
        cout << dir[o[i].first] << "\n";
    }
}

