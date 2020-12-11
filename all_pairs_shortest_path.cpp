#include <bits/stdc++.h>

using namespace std;

const int INF=1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q, a, b, c;
    while (cin >> n >> m >> q) {
        if (!n && !m && !q) return 0;
        vector<vector<int>> mat(n, vector<int>(n, INF));
        while (m--) {
            cin >> a >> b >> c;
            mat[a][b]=min(mat[a][b], c);
        }
        for (int i=0; i<n; ++i) mat[i][i]=0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                for (int k=0; k<n; ++k) {
                    if (mat[j][i]<INF && mat[i][k]<INF) mat[j][k]=min(mat[j][k], mat[j][i]+mat[i][k]);
                }
            }
        }
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                for (int k=0; k<n; ++k) {
                    if (mat[i][k]<INF && mat[k][j]<INF && mat[k][k]<0) mat[i][j]=-INF;
                }
            }
        }
        while (q--) {
            cin >> a >> b;
            if (mat[a][b]==INF) cout << "Impossible\n";
            else if (mat[a][b]==-INF) cout << "-Infinity\n";
            else cout << mat[a][b] << "\n";
        }
        cout << "\n";
    }
}

