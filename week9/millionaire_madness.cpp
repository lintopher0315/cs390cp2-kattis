#include <bits/stdc++.h>

using namespace std;

const int cX[]={0, 0, -1, 1};
const int cY[]={1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m, n;
    cin >> m >>n;
    vector<vector<int>> v(m, vector<int>(n));
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            cin >> v[i][j];
        }
    }
    int ans=0;
    bool vi[m*n]={0};
    priority_queue<array<int, 3>> pq;
    pq.push({0, 0, 0});
    vi[0]=1;
    while (!pq.empty()) {
        array<int, 3> t=pq.top(); pq.pop();
        ans=max(ans, abs(t[0])); 
        int x=t[1], y=t[2];
        vi[y*n+x]=1;
        if (x==n-1 && y==m-1) {
            cout << ans;
            return 0;
        }
        for (int i=0; i<4; ++i) {
            int nX=x+cX[i], nY=y+cY[i];
            if (nX<0 || nX>=n || nY<0 || nY>=m || vi[nY*n+nX]) continue;
            pq.push({-1*max(0, v[nY][nX]-v[y][x]), nX, nY});
        }
    }
}

