#include <bits/stdc++.h>

using namespace std;

unordered_map<string, vector<string>> um;
unordered_set<string> us;
vector<string> ans;

void dfs(string s) {
    for (string a : um[s]) {
        if (us.find(a)!=us.end()) continue;
        dfs(a);
    }
    us.insert(s);
    ans.push_back(s);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string l;
    getline(cin, l);
    int n=stoi(l);
    while (n--) {
        getline(cin, l);
        string c, f;
        for (int i=0; i<l.size(); ++i) {
            if (l[i]==':') {
                f=c;
                c="";
                ++i;
            }
            else if (l[i]==' ') {
                um[c].push_back(f);
                c="";
            }
            else {
                c+=l[i];
            }
        }
        um[c].push_back(f);
    }
    getline(cin, l);
    dfs(l);
    for (int i=ans.size()-1; ~i; --i) {
        cout << ans[i] << "\n";
    }
}

