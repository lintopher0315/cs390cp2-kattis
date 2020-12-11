#include <bits/stdc++.h>

using namespace std;

void permutation(vector<int>& paint, int n, array<unordered_set<int>, 12>& ugly, vector<int>& fav, int& ans) {
    if (n>=2) {
        if (ugly[paint[n-1]].find(paint[n-2])!=ugly[paint[n-1]].end()) return;
    }
    if (n==paint.size()-1) {
        if (ugly[paint[n]].find(paint[n-1])!=ugly[paint[n]].end()) return;
        //if (fav.size()==1) {
            //fav=paint;
            for (int i=0; i<paint.size(); ++i) {
                if (paint[i]<fav[i]) {
                    fav=paint;
                    break;
                }
                else if (paint[i]>fav[i]) break;
            }
        //}
        ++ans;
        return;
    }
    for (int i=n; i<paint.size(); ++i) {
        swap(paint[n], paint[i]);
        permutation(paint, n+1, ugly, fav, ans);
        swap(paint[n], paint[i]);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string a, b;
        cin >> n;
        unordered_map<string, int> si;
        string str_ind[12];
        vector<int> paint(n);
        for (int i=0; i<n; ++i) {
            cin >> a;
            str_ind[i]=a;
            si.insert({a, i});
            paint[i]=i;
        } 
        cin >> n;
        array<unordered_set<int>, 12> ugly;
        for (int i=0; i<n; ++i) {
            cin >> a >> b;
            ugly[si[a]].insert(si[b]);
            ugly[si[b]].insert(si[a]);
        }
        vector<int> fav{12};
        int ans=0;
        permutation(paint, 0, ugly, fav, ans);
        cout << ans << "\n";
        for (int a : fav) cout << str_ind[a] << " ";
        cout << "\n";
    }
}

