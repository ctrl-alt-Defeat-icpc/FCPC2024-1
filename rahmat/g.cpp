#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e5 + 5;
vector<int> adj[N];
int n, m, u, v;
int component[N], size_component, component_filled;
bool tempvisited[N];

void fillcomponent(int src, int component_number) {
    component[src] = component_number;
    for(auto u : adj[src]) {
        if(component[u] != component_number)
            fillcomponent(u, component_number);
    }
}

int parent[N];
int dfs(int x) {
    for(auto u : adj[x]) {
        if(parent[u] == -1) {
            parent[u] = x;
            return dfs(u);
        }
        else {
            int result = 1;
            int curr = x;
            while(curr != u) {
                result++;
                curr = parent[x];
            }
            return result;
        }
    }
    return -1;
}

int getcycle(int r) {
    memset(parent, -1, sizeof(parent));
    parent[r] = r;
    return dfs(r);
}

void Main() {
    memset(component, -1, sizeof(component));
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << getcycle(1) << endl;
    
    // for(int i = 0; i < m; i++) {
    //     cin >> u >> v;
    //     adj[u].push_back(v);
    //     adj[v].push_back(u);

    //     if(component[u] == component[v] == -1)
    //         component[u] = component[v] = size_component++;
    //     else if(component[u] != -1 && component[v] == -1)
    //         component[v] = component[u];
    //     else if(component[v] != -1 && component[u] == -1)
    //         component[u] = component[v];
    //     else if(component[u] != component[v]) {
    //         if(component[u] < component[v])
    //             fillcomponent(v, component[u]);
    //         else
    //             fillcomponent(u, component[v]);
    //     }
    //     if(getcycle(u) % 2) {
    //         cout << i + 1 << endl;
    //         return;
    //     }
        
    // }
    // cout << -1 << endl;

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
