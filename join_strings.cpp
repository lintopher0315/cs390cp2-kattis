#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
    string data;
    Node* next;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a=0, b;
    cin >> n;
    array<Node*, 2> arr[n];
    for (int i=0; i<n; ++i) {
        arr[i][0]=new Node();
        cin >> arr[i][0]->data;
        arr[i][1]=arr[i][0];
    }
    for (int i=0; i<n-1; ++i) {
        cin >> a >> b; --a; --b;
        arr[a][1]->next=arr[b][0];
        arr[a][1]=arr[b][1];
    }
    Node* temp=arr[a][0];
    while (temp) {
        cout << temp->data;
        temp=temp->next;
    }
}

