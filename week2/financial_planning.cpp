#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v(n);
    long long t=m;
    int c=0;
    for (int i=0; i<n; ++i) {
        cin >> v[i].first >> v[i].second;
        if (!i) {
            t+=v[i].second;
            c=v[i].first;
        }
    }
    int l=1;
    int h=t/c+1;
    while (l<h) {
        int mi=l+(h-l)/2;
        long long am=0;
        for (int i=0; i<n; ++i) {
            long long val=mi*v[i].first-v[i].second;
            if (val>0) am+=val;
        }
        if (am==m) {
            cout << mi;
            return 0;
        }
        else if (am<m) {
            l=mi+1;
        }
        else {
            h=mi;
        }
    }
    cout << l;
}

