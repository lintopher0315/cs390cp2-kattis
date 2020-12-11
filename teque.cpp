#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, b;
    cin >> n;
    string a;
    deque<int> d1;
    deque<int> d2;
    while (n--) {
        cin >> a >> b;
        if (a=="push_back") {
            if (d2.size()==d1.size()) {
                if (d2.empty()) {
                    d1.push_back(b);
                    continue;
                }
                d1.push_back(d2.front());
                d2.pop_front();
            }
            d2.push_back(b);
        }
        else if (a=="push_front") {
            if (d1.size()!=d2.size()) {
                d2.push_front(d1.back());
                d1.pop_back();
            }
            d1.push_front(b);
        }
        else if (a=="push_middle") {
            if (d1.size()==d2.size()) {
                d1.push_back(b);
            }
            else {
                d2.push_front(b);
            }
        }
        else {
            if (b>d1.size()-1) {
                cout << d2.at(b-d1.size()) << "\n";
            }
            else {
                cout << d1.at(b) << "\n";
            }
        }
    }
}

