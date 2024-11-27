#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e5 + 5;

int n, q;
char c;
int l, r, x;
set<int> s;

bool gcdCheck(int a, int b) { // always b is bigger
    while(a) {
        int temp = a;
        a = b % a;
        b = temp;
    }
    return b != 1;
}

void findStation() {
    auto it_start = s.lower_bound(l);
    auto it_end = s.upper_bound(r);
    vector<int> elements(it_start, it_end);
    int elements_size = elements.size();

    for(int i = 0; i < elements_size; i++) {
        for(int j = i + 1; j < elements_size; j++)
            if(gcdCheck(elements[i], elements[j])) {
                cout << "DA\n";
                return;
            }
    }
    cout << "NE\n";
}

void Main() {
    cin >> n >> q;
    while(q--) {
        cin >> c;
        if(c == 'S') {
            cin >> x;
            if(s.find(x) == s.end()) s.insert(x);
            else s.erase(x);
        }
        else {
            cin >> l >> r;
            findStation();
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
