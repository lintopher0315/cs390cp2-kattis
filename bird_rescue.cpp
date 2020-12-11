#include <bits/stdc++.h>

using namespace std;

const int MD=2e6+1;
int g[MD];

int main() {
    int n, q, x, y, a, b, c, d, z;
    cin >> n >> q >> x >> y;
    while (n--) {
        cin >> a >> b >> c >> d;
        if (a>c) swap(a, c);
        if (b>d) swap(b, d);
        int minx=x>=a && x<=c ? 0 : (max(x-c, a-x));
        int maxx=max(c-x, x-a);
        int miny=y>=b && y<=d ? 0 : (max(y-d, b-y));
        int maxy=max(d-y, y-b);
        ++g[minx+miny];
        --g[maxx+maxy+1];
    }
    for (int i=1; i<MD; ++i) {
        g[i]+=g[i-1];
    }
    while (q--) {
        cin >> z;
        cout << g[z] << "\n";
    }
}
