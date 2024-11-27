#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 6e5;
int n, k, base, idx;
string str[N];
bool num[N];
ll ans3;

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
    cin >> n >> k;
    base = pow(3, k - 1);
    for(int i = 0; i < n; i++) {
        cin >> str[i];
        idx = 0;
        for(int j = 0, b = base; str[i][j]; j++, b /= 3)
            idx += int(str[i][j] - '1') * b;
        num[idx] = 1;
    }
    if(n < 3) {
        cout << 0 << endl;
        return;
    }

    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++) {
            idx = 0;
            for(int l = 0, b = base; l < k; l++, b /= 3)
                if(str[i][l] == str[j][l]) idx += int(str[i][l] - '1') * b;
                else idx += give(str[i][l], str[j][l]) * b;
            if(num[idx]) ans3++;
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
