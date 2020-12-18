#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n));
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cin >> m[i][j];
        }
    }
    vector<bool> v(n, 0);
    int c=1;
    v[0]=1;
    priority_queue<array<int, 3>> pq;
    for (int i=1; i<n; ++i) {
        pq.push({-m[0][i], 0, i});
    }
    while (!pq.empty()) {
        auto t=pq.top(); pq.pop();
        if (v[t[2]]) continue;
        cout << t[1]+1 << " " << t[2]+1 << "\n";
        for (int i=0; i<n; ++i) {
            if (t[2]==i || v[i]) continue;
            pq.push({-m[t[2]][i], t[2], i});
        }
        v[t[2]]=1;
        if (++c==n) return 0;
    }
}

