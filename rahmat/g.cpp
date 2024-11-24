#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e5 + 5;
const int oo = 1e9 + 5;
vector<int> adj[N];
int n, m, u, v;
int component[N], size_component, component_filled;
int deleted, dis[N];
queue<int> q;

void fillcomponent(int src, int connection, int component_number) {
    component[src] = component_number;
    dis[src] = dis[connection] + 1;
    for(auto u : adj[src]) {
        if(component[u] != component_number)
            fillcomponent(u, src, component_number);
    }
}

// void bfs(int r) {
//     dis[r] = 0;
//     q.push(r);
//     while(!q.empty()) {
//         int v = q.front();
//         q.pop();
//         for(auto u : adj[v]) {
//             if(v == r && u == deleted) continue;
//             if(dis[u] > dis[v] + 1) {
//                 dis[u] = dis[v] + 1;
//                 q.push(u);
//             }
//         }
//     }
// }

// bool checkOddCycle(int src, int u) {
//     deleted = u;
//     bfs(src);
//     if((dis[u] + 1) % 2) return true;
//     return false;
// }

void Main() {
    memset(component, -1, sizeof(component));
    fill(dis, dis + n + 1, oo);
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

        if(component[u] == -1 && component[v] == -1) {
            component[u] = component[v] = size_component++;
            dis[u] = 0;
            dis[v] = 1;
        }
        else if(component[u] != -1 && component[v] == -1) {
            component[v] = component[u];
            dis[v] = dis[u] + 1;
        }
        else if(component[v] != -1 && component[u] == -1) {
            component[u] = component[v];
            dis[u] = dis[v] + 1;
        }
        else if(component[u] != component[v]) {
            if(component[u] < component[v])
                fillcomponent(v, u, component[u]);
            else
                fillcomponent(u, v, component[v]);
        }
        else if(component[u] == component[v] && dis[u] % 2 == dis[v] % 2) {
            cout << i + 1 << '\n';
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    // int t; cin >> t; while(t--) Main();
    Main();
    return 0;
}
