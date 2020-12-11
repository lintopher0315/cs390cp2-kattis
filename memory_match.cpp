#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, a, b, op=0, ans=0;
    string c, d;
    cin >> n >> k;
    vector<unordered_set<int>> v(n/2);
    unordered_map<string, int> um;
    int ind=0;
    for (int i=0; i<k; ++i) {
        cin >> a >> b >> c >> d;
        if (um.find(c)==um.end()) um[c]=ind++;
        v[um[c]].insert(a);
        if (um.find(d)==um.end()) um[d]=ind++;
        v[um[d]].insert(b);
        if (c==d) ++op;
    }
    int non=0;
    for (int i=0; i<n/2; ++i) {
        if (v[i].size()==2) ++ans;
        if (!v[i].size()) non=1;
    }
    if (ans==n/2-1 && non) { 
        cout << n/2-op;
    }
    else {
        cout << (non ? ans-op : n/2-op);
    }
}

