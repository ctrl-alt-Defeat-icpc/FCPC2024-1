#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e5 + 5;
int n, temp, pre;
void Main() {
    cin >> n;
    
    cin >> pre;
    for(int i = 2; i <= n; i++) {
        cin >> temp;
        
        if(temp > pre) {
            cout << i << '\n';
            return;
        }
        pre = temp;
    }
    cout << -1 << '\n';
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
