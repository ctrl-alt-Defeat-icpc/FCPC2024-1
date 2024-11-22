#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e6 + 5;
int dp[N];
void Main() {
    int n,a,b;
    cin >> n >> a >> b;
    
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if((i - a >= 0 && dp[i - a]) || (i - b >= 0 && dp[i - b]))
            dp[i] = 1;
    }
    for (int i = 1; i* 2 + 1 <= n; i++)
    {
        if(dp[2*i] || dp[2*i+1])
            dp[i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if((i - a >= 0 && dp[i - a]) || (i - b >= 0 && dp[i - b]))
            dp[i] = 1;
    }
    for (int i = n; i >= 0; i--)
    {
        if(dp[i])
        {
            cout << i << endl;
            return;
        }
    }
    
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
