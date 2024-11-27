#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 6e5;
int n, k, idx;
string str[N];
bool num[N];
ll ans3;

struct Node {
    Node() {
        for(int i = 0; i < 3; i++)
            child[i] = nullptr;
    }
    Node *child[3];
};

int give(char a, char b) {
    if(a == '1') {
        if(b == '2') return 2; // '3'
        return 1; // '2'
    }
    if(a == '2') {
        if(b == '1') return 2; // '3'
        return 0; // '1'
    }
    // a == '3'
    if(b == '1') return 1; // '2'
    return 0; // '1'
}

void Main() {
    Node *tree = new Node();
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> str[i];
        Node *curr = tree;
        for(int j = 0; j < k; j++) {
            if(curr->child[str[i][j] - '1'] == nullptr)
                curr->child[str[i][j] - '1'] = new Node();
            curr = curr->child[str[i][j] - '1'];
        }
            
    }
    if(n < 3) {
        cout << 0 << endl;
        return;
    }

    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++) {
            bool exist = 1;
            Node *curr = tree;
            for(int l = 0; l < k; l++, curr = curr->child[idx]) {
                idx = str[i][l] == str[j][l] ? int(str[i][l] - '1') : give(str[i][l], str[j][l]);
                if(curr->child[idx] == nullptr) {
                    exist = 0;
                    break;
                }
            }
            if(exist) ans3++;
        }
    cout << ans3 / 3 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        Main();
    return 0;
}
