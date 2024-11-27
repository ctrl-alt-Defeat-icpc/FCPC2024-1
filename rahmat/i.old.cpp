#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e6 + 5;
int n, a[N];
int seq[N], dp[N];
void Main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    fill(dp, dp + n, 1);
    
    int lis = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        lis = max(lis, dp[i]);
    }
    cout << lis << endl;

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
