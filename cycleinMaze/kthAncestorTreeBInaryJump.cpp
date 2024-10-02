#include<bits/stdc++.h>
using namespace std;
#define SZ 200006
// Company queries 1
int n, m, k, x;
int L[SZ]; //level-array
vector<int> adj[SZ]; 
int jump[21][SZ];
 
void dfs(int u, int p, int l) {
    jump[0][u] = p;
    L[u] = l;
    
    for (int v: adj[u]) 
        if(v != p) 
        dfs(v, u, l+1);
}
 
void preprocess_LCA() { 
    dfs(1, -1, 0);
        
    for (int i = 1; 1<<i <= n ; i++) 
    for (int j = 0; j <= n ; j++)
    jump[i][j] = jump[i-1][jump[i-1][j]];
}
 
int LCA(int p,int q) {
    if(L[p] < L[q])
    swap(p, q);
    
    int diff = L[p] - L[q];
    
    for(int i = 20; i >= 0; i--) 
        if(diff & (1<<i)) 
        p = jump[i][p];
        
    if(p == q) return p;
 
    for (int i = 20; i >= 0; i--) {
        if (jump[i][p] != jump[i][q]) {
            p = jump[i][p];
            q = jump[i][q];
        }
    }
    return jump[0][p];
}
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
int main() {
    init_code();
    int q;
    cin >> n >> q;
    for(int i = 2; i <= n; i++) {
        int u;
        cin >> u;
        adj[i].push_back(u);
        adj[u].push_back(i);
    }
    preprocess_LCA();
    
    while(q--) {
        int a, k;
        cin >> a >> k; // find k ancestor of a
        if(k == 0){
            return a;
        }
        if(a == -1){
          return -1; 
        }
        for(int i = 20; i >= 0; i--){
            if(k & (1 << i)){
                a = jump[i][a];
            }
        }
        cout << a << endl;
    }
}
