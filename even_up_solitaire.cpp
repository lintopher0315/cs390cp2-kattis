#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a;
    cin >> n;
    stack<int> st;
    for (int i=0; i<n; ++i) {
        cin >> a;
        if (!st.empty() && (a+st.top())%2==0) {
            st.pop();
        }
        else st.push(a);
    }
    cout << st.size();
}

