#include <bits/stdc++.h>

using namespace std;
// # means consonant; ! means vowel
long long ans=0;

bool isVowel(char a) {
    return (a=='A' || a=='E' || a=='I' || a=='O' || a=='U' || a=='!');
}

void dfs(string& a, int c, string n) {
    if (c==a.size()) {
        bool l=0;
        int v=0, con=0;
        for (char a : n) {
            if (a=='#') ++con;
            else if (a=='!') ++v;
            else if (a=='L') l=1;
        }
        long long num=pow(5, v)*pow(21, con);
        if (!l) {
            if (!con) return;
            num-=pow(5, v)*pow(20, con);
        }
        ans+=num;
        return;
    }
    if (a[c]!='_') {
        if (c>=2 && isVowel(n[c-2])==isVowel(n[c-1]) && (isVowel(n[c-1])==isVowel(a[c]))) return;
        dfs(a, c+1, n+a[c]);
    }
    else {
        if (c>=2) {
            if (isVowel(n[c-2]) && isVowel(n[c-1])) {
                dfs(a, c+1, n+'#');
                return;
            }
            else if (!isVowel(n[c-2]) && !isVowel(n[c-1])) {
                dfs(a, c+1, n+'!');
                return;
            }
        }
        dfs(a, c+1, n+'#');
        dfs(a, c+1, n+'!');
    }
}

int main() {
    string a;
    cin >> a;
    dfs(a, 0, "");
    cout << ans;
}

