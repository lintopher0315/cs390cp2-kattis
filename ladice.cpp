#include <bits/stdc++.h>

using namespace std;

const int MN=3e5;
int p[MN];
bool v[MN];

int find(int s) {
    if (p[s]==s) return s;
    return p[s]=find(p[s]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, l, a, b;
    cin >> n >> l;
    for (int i=0; i<l; ++i) {
        p[i]=i;
    }
    while (n--) {
        cin >> a >> b; --a; --b;
        int pa=find(a), pb=find(b);
        if (!v[a]) {
            v[a]=1;
            p[pa]=pb;
            cout << "LADICA\n";
        }
        else if (!v[b]) {
            v[b]=1;
            p[pb]=pa;
            cout << "LADICA\n";
        }
        else if (!v[pa]) {
            v[pa]=1;
            p[pa]=pb;
            cout << "LADICA\n";
        }
        else if (!v[pb]) {
            v[pb]=1;
            p[pb]=pa;
            cout << "LADICA\n";
        }
        else {
            cout << "SMECE\n";
        }
    }
}

