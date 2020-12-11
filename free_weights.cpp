#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a;
    cin >> n;
    vector<int> v[2]={vector<int>(n), vector<int>(n)};
    unordered_map<int, int> um;
    for (int i=0; i<n; ++i) {
        cin >> a;
        v[0][i]=a;
        ++um[a];
    }
    for (int i=0; i<n; ++i) {
        cin >> a;
        v[1][i]=a;
    }
    if (n==1) {
        cout << v[0][0];
        return 0;
    }
    int l=0;
    for (auto a : um) {
        if (a.second==1) l=max(l, a.first);
    }
    int h=1e9;
    while (l<h) {
        int m=l+(h-l)/2;
        bool ok=1;
        int value=-1;
        for (int i=0; i<n; ++i) {
            if (v[0][i]>m) {
                if (value==-1) value=v[0][i];
                else if (value==v[0][i]) value=-1;
                else {
                    ok=0;
                    break;
                }
            }
        }
        if (ok) {
            for (int i=0; i<n; ++i) {
                if (v[1][i]>m) {
                    if (value==-1) value=v[1][i];
                    else if (value==v[1][i]) value=-1;
                    else {
                        ok=0;
                        break;
                    }
                }
            }
        }
        if (ok) {
            h=m;
        }
        else {
            l=m+1;
        }
    }
    cout << l;
}

