#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c, a;
    string b;
    cin >> c;
    while (c--) {
        int n, t, m;
        cin >> n >> t >> m;
        queue<pair<int, int>> left;
        queue<pair<int, int>> right;
        vector<int> ans(m);
        for (int i=0; i<m; ++i) {
            cin >> a >> b;
            if (b=="left") left.push({a, i});
            else right.push({a, i});
        }
        int cl=0;
        bool side=0;    //left=0; right=1
        int am=0;
        int ne=0;
        bool ns=0;
        while (!left.empty() || !right.empty()) {
            if (right.empty()) {
                ne=left.front().first;
                ns=0;
            }
            else if (left.empty()) {
                ne=right.front().first;
                ns=1;
            }
            else {
                ne=left.front().first;
                if (right.front().first<left.front().first) {
                    ne=right.front().first;
                    ns=1;
                }
                else if (right.front().first>left.front().first) {
                    ne=left.front().first;
                    ns=0;
                }
            }
            if ((right.empty() || right.front().first>cl) && (left.empty() || left.front().first>cl)) {
                cl=ns==side ? ne : ne+t;
                side=ns;
                continue;
            }
            if (side) {
                while (!right.empty() && right.front().first<=cl && am<n) {
                    ans[right.front().second]=cl+t;
                    right.pop();
                    ++am;
                }
            }
            else {
                while (!left.empty() && left.front().first<=cl && am<n) {
                    ans[left.front().second]=cl+t;
                    left.pop();
                    ++am;
                }
            }
            cl+=t;
            side=!side;
            am=0;
        }
        for (int a : ans) cout << a << "\n";
        cout << "\n";
    }
}

