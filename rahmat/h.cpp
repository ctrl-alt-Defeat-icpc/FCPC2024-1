#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5; // Maximum number of elements
#define ll long long

int nn, q;
char c;
int l, r, x;

class GCDSegmentTree {
public:
    std::vector<int> segTree;
    int n;

    GCDSegmentTree(int size) : n(size) {
        segTree.resize(4 * n, 0); // Initialize segment tree with zeros
    }

    void update(int idx, int value, int node, int start, int end) {
        if (start == end) {
            segTree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(idx, value, 2 * node + 1, start, mid);
            } else {
                update(idx, value, 2 * node + 2, mid + 1, end);
            }
            segTree[node] = __gcd(segTree[2 * node + 1], segTree[2 * node + 2]);
        }
    }

    int query(int l, int r, int node, int start, int end) {
        if (r < start || l > end) {
            return 0; // Out of range
        }
        if (l <= start && end <= r) {
            return segTree[node]; // Completely within range
        }
        int mid = (start + end) / 2;
        int leftGCD = query(l, r, 2 * node + 1, start, mid);
        int rightGCD = query(l, r, 2 * node + 2, mid + 1, end);
        return __gcd(leftGCD, rightGCD);
    }
};



void Main() {
    int n = 0; // Current size of elements
    GCDSegmentTree tree(MAX_N);
    set<int> elements;
    vector<int> position(MAX_N, -1);

    auto insertNumber = [&](int num) {
        if (elements.count(num) == 0) {
            elements.insert(num);
            position[num] = n;
            tree.update(n++, num, 0, 0, MAX_N - 1);
        }
    };

    auto removeNumber = [&](int num) {
        if (elements.count(num)) {
            elements.erase(num);
            tree.update(position[num], 0, 0, 0, MAX_N - 1); // Set to 0 (like "erase")
            --n;
        }
    };

    auto queryRange = [&](int l, int r) {
        return tree.query(l, r, 0, 0, MAX_N - 1);
    };


    cin >> nn >> q;
    while(q--) {
        cin >> c;
        if(c == 'S') {
            cin >> x;
            if(elements.count(x)) removeNumber(x);
            else insertNumber(x);
        }
        else {
            cin >> l >> r;
            if(queryRange(l, r) > 1)
                cout << "DA" << '\n';
            else
                cout << "NE" << '\n';
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
