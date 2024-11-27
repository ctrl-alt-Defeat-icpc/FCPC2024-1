#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 6e5;
int n, k, idx;
string str[N];
bool num[N];
ll ans3;

struct Node {
    Node(Node *p, short v) : parent(p), value(v) {
        for(int i = 0; i < 3; i++)
            child[i] = nullptr;
    }
    short value;
    Node *parent;
    Node *child[3];
};

ll solve(vector<int> &num, Node *a, Node *b, int curIdx) {
    if(curIdx < 0) return 1;
    ll result = 0;
    if(a->child[num[curIdx]] != nullptr && b->child[num[curIdx]] != nullptr)
        result += solve(num, a->child[num[curIdx]], b->child[num[curIdx]], curIdx - 1);
    if(num[curIdx] == 0) {
        if(a->child[1] != nullptr && b->child[2] != nullptr) result += solve(num, a->child[1], b->child[2], curIdx - 1);
        else if(a->child[2] != nullptr && b->child[1] != nullptr) result += solve(num, a->child[2], b->child[1], curIdx - 1);
    }
    else if(num[curIdx] == 1) {
        if(a->child[0] != nullptr && b->child[2] != nullptr) result += solve(num, a->child[0], b->child[2], curIdx - 1);
        else if(a->child[2] != nullptr && b->child[0] != nullptr) result += solve(num, a->child[2], b->child[0], curIdx - 1);
    }
    else { // num[curIdx] == 2
        if(a->child[0] != nullptr && b->child[1] != nullptr) result += solve(num, a->child[0], b->child[1], curIdx - 1);
        else if(a->child[1] != nullptr && b->child[0] != nullptr) result += solve(num, a->child[1], b->child[0], curIdx - 1);
    }
    return result;
}

void Main() {
    vector<Node *> nums;
    Node *tree = new Node(nullptr, 0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> str[i];
        Node *curr = tree;
        for(int j = 0; j < k; j++) {
            if(curr->child[str[i][j] - '1'] == nullptr)
                curr->child[str[i][j] - '1'] = new Node(curr, str[i][j] - '1');
            curr = curr->child[str[i][j] - '1'];
        }
        nums.push_back(curr);
    }
    if(n < 3) {
        cout << 0 << endl;
        return;
    }

    for(auto num : nums) {
        if(num->value) continue;  // avoiding replica by starting form 1 digit
        vector<int> numValue;
        for(Node *digit = num; digit->parent != nullptr; digit = digit->parent) {
            numValue.push_back(digit->value);
            vector<Node *> sibling;
            for(int i = 0; i < 3; i++) { // iterate to all siblings -> we have 3 sibling maximum
                if(digit->parent->child[i] == nullptr) continue; // this isn't any digit
                if(digit->parent->child[i]->value == digit->value) continue; // your digit
                sibling.push_back(digit->parent->child[i]);
            }
            if(sibling.size() != 2) continue; // it isn't standard
            ans3 += solve(numValue, sibling[0] , sibling[1], numValue.size() - 2);
        }
    }

    cout << ans3 << endl;
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
