#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e6 + 5;
const ll oo = 1e9 + 7;
ll dp[N], seq[N], ans;
pair<int, int> a[N];

pair<int, int> lis(vector<int> &a, int n) {
    fill(dp, dp + n, 1);
    for(int i = 0; i < n; i++) {
        seq[i] = i;
        for(int pre = 0; pre < i; pre++)
            if(a[pre] < a[i] && dp[i] < dp[pre] + 1) {
                dp[i] = dp[pre] + 1;
                seq[i] = pre;
            }
    }

    pair<int, int> ans = {-oo, -1};
    for(int i = 0; i < n; i++) {
        if(ans.first < dp[i]) {
            ans.first = dp[i];
            ans.second = i;
        }
    }
    return ans;
}

bool compare(pair<int, int> &a, pair<int, int> &b) {
    if()
}

void Main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a, a + n, compare);
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
