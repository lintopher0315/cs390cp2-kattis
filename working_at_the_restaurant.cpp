#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, b;
    string a;
    while (true) {
        cin >> n;
        if (!n) break;
        int st1=0, st2=0;
        for (int i=0; i<n; ++i) {
            cin >> a >> b;
            if (a=="DROP") {
                st2+=b;
                cout << "DROP 2 " << b << "\n";
            }
            else {
                if (st1>=b) {
                    st1-=b;
                    cout << "TAKE 1 " << b << "\n";
                }
                else {
                    if (!st1) {
                        cout << "MOVE 2->1 " << st2 << "\nTAKE 1 " << b << "\n";
                        st1=st2-b;
                        st2=0;
                    }
                    else {
                        int temp=b-st1;
                        cout << "TAKE 1 " << st1 << "\nMOVE 2->1 " << st2 << "\nTAKE 1 " << temp << "\n";
                        st1=st2-temp;
                        st2=0;
                    }
                }
            }
        }
        cout << "\n";
    }
}

