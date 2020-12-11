#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m=INT_MIN, a;
    cin >> n;
    stack<int> st;
    while (n--) {
        cin >> a;
        if (a<m) {
            while (!st.empty() && st.top()>a) st.pop();
        }
        else {
            st.push(a);
        }
        m=max(m, a);
    }
    cout << st.size();
}

