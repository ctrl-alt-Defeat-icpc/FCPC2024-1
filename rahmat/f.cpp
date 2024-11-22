#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e5 + 5;
int n, k, c, ans;
ll m;
void Main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> k >> c;
        if(c == 0) {
            if(k <= m)
                ans++;
        }
        else {
            if(k > m)
                ans++;
        }
    }
    cout << ans << '\n';
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
