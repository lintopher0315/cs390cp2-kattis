#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string l;
    getline(cin, l);
    unordered_map<string, vector<string>> um;
    int n=stoi(l);
    while (n--) {
        getline(cin, l);
        string c, f;
        for (int i=0; i<l.size(); ++i) {
            if (l[i]==':') {
                f=c;
                c="";
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
    queue<string> q;
    unordered_set<string> us;
    q.push(l);
    us.insert(l);
    while (!q.empty()) {
        string t=q.front(); q.pop();
        cout << t << "\n";
        for (string a : um[t]) {
            if (us.find(a)==us.end()) {
                q.push(a);
                us.insert(a);
            }
        }
    }
}

