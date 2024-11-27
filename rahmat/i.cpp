#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
int n;
vector<int> A;
const int MOD = 1e9 + 7;  // Or 998244353 in some cases


// Fenwick Tree (for counting LIS efficiently)
class FenwickTree {
private:
    vector<int> tree;
    int size;

public:
    FenwickTree(int n) : size(n) {
        tree.assign(n + 1, 0);
    }

    // Update Fenwick Tree
    void update(int index, int value) {
        for (; index <= size; index += index & -index) {
            tree[index] = (tree[index] + value) % MOD;
        }
    }

    // Get prefix sum up to index
    int query(int index) {
        int sum = 0;
        for (; index > 0; index -= index & -index) {
            sum = (sum + tree[index]) % MOD;
        }
        return sum;
    }
};

void findLIS() {
    // Track LIS length
    vector<int> ends;  // Smallest end elements for each LIS length
    
    // Fenwick Tree for counting LIS
    FenwickTree fenwick(n);

    // Iterate through array elements
    for (int i = 0; i < n; ++i) {
        // Find position to place A[i] in ends
        int pos = lower_bound(ends.begin(), ends.end(), A[i]) - ends.begin();
        
        // If new length is greater than existing, add it to ends
        if (pos == ends.size()) {
            ends.push_back(A[i]);
        } else {
            ends[pos] = A[i];  // Replace with a smaller end value
        }

        // Update the count of sequences of length `pos + 1` ending at `A[i]`
        int count = 1;  // Each element is an LIS of length 1
        if (pos > 0) {
            count = fenwick.query(A[i] - 1);  // Get count of LIS of length `pos`
        }
        fenwick.update(A[i], count);
    }

    // Output LIS length and count
    int lisLength = ends.size();
    int totalLISCount = fenwick.query(n);
    
    cout << "Length of LIS: " << lisLength << endl;
    cout << "Number of LIS: " << totalLISCount << endl;
}

int main() {
    cin >> n;
    A.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    findLIS();

    return 0;
}
