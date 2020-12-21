#include <bits/stdc++.h>

using namespace std;

const int MN=50;
bool v[MN][MN];
char g[MN][MN];
int w, h;

void dfs(int x, int y, int& ans) {
    if (g[y][x]=='#' || v[y][x]) return;
    v[y][x]=1;
    if (g[y][x]=='G') ++ans;
    if (g[y-1][x]=='T' || g[y+1][x]=='T' || g[y][x+1]=='T' || g[y][x-1]=='T') return;
    dfs(x+1, y, ans);
    dfs(x-1, y, ans);
    dfs(x, y+1, ans);
    dfs(x, y-1, ans);
}

int main() {
    int ans=0, x, y;
    cin >> w >> h;
    for (int i=0; i<h; ++i) {
        for (int j=0; j<w; ++j) {
            cin >> g[i][j];
            if (g[i][j]=='P') {
                y=i;
                x=j;
            }
        }
    }
    dfs(x, y, ans);
    cout << ans;
}

