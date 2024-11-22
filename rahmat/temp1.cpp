#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e6 + 5;
const ll oo = 1e18;
ll n, c[N], cost, suff[N], minidx, minimum = oo;

void Main() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    for(int i = n; i >= 0; i--) {
        suff[i] = minidx;
        if(minimum > c[i]) {
            minimum = c[i];
            minidx = i;
        }
    }
    
    int cur = 0;
    while(cur != n) {
        cost += (suff[cur] - cur) * c[suff[cur]];
        cur = suff[cur];
    }
    
    cout << cost << endl;   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Main();
    return 0;
}