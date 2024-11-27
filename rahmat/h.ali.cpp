#include <bits/stdc++.h>
using namespace std;

#define ll long long

void check(int n, int a, int b, vector<vector<int>> &mgha, vector<bool>  &active){
    vector<bool>  temp(sqrt(n)+2, false);
    for (int i = a; i <= b; i++)
    {
        if(active[i])
        {
            // cout << mgha[i].size() << endl;
            for(int j = 0; j < mgha[i].size(); j++)
            {
                if(temp[mgha[i][j]])
                {
                    cout << "DA" << endl;
                    return;
                }
                else{
                    temp[mgha[i][j]] = 1;
                }
            }
        }
    }
    cout << "NE" << endl;
    
}



void Main() {
    int n,q;
    cin >> n >> q;
    vector<vector<int>> mgha(n+1);
    vector<bool> active(n+1);

    for (int i = 2; i <= sqrt(n); i++)
    {
        if(mgha[i].size() == 0)
            for (int j = i; j <= n; j+=i)
            {
                mgha[j].push_back(i);
            }
            
    }
    for (int i = 0; i < q; i++)
    {
        char ch;
        cin >> ch;
        if(ch == 'S')
            {
                int x;
                cin >> x;
                // if(active[x])
                    // active[x] = false;
                // else
                    active[x] = true;
            }
        else if(ch == 'C')
        {
            int a,b;
            cin >> a >> b;
            check(n, a,b,mgha,active);
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
