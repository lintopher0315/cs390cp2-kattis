#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string line;
    getline(cin, line);
    int sp=line.find(" ", 0);
    int h=stoi(line.substr(0, sp+1));
    string p=line.substr(sp+1);
    int t=pow(2, h+1)-1;
    if (p!="") {
        t-=pow(2, p.size()+1)-2;
        int b=0;
        for (int i=0; i<p.size(); ++i) {
            if (p[i]=='L') b+=pow(2, p.size()-i-1);
        }
        cout << t+b;
    }
    else cout << t;
}

