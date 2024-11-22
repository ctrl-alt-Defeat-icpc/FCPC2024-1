#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e5 + 5;

void Main() {
    int n;
    cin >> n;
    ll ans = 0;
    for(int i = 0; i < n;i++){
        int x;
        cin >> x;
        ans+= x;
    }
    cout << ans;

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
