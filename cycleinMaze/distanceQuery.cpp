#include<bits/stdc++.h>
using namespace std;
vector<int> tree[200005];
int ancestor[200005][21];
int depth[200005];
int n;
void dfs(int node, int par, int level){
    ancestor[node][0] = par;
    depth[node] =  level;
    for(int ch : tree[node]){
        if(ch != par){
            dfs(ch, node, level + 1);
        }
    }
}
// Olog(N) solution for LCA.
int get_lca(int a, int b){
    if(depth[a] < depth[b]){
        // swap the values.
        swap(a,b);
    }
    // 1) Get same depth.
    int k = depth[a] - depth[b];

    for(int j = 20; j >= 0; j--) {
        if(k & (1 << j)) {
            a = ancestor[a][j]; // parent of a
        }
    }
    // 2) if b was ancestor of a then now a==b
    if(a == b) {
        return a;
    }
    // 3) move both a and b with powers of two
    for(int j = 20; j >= 0; j--) {
        if(ancestor[a][j] != ancestor[b][j]) {
            a = ancestor[a][j];
            b = ancestor[b][j];
        }
    }
    // while(depth[a] > depth[b]){
    //     a = ancestor[a][0];
    // }
    // now a and b are at the same level.
    // now move a and b altogether up while they are not equal.
    // while(a!= b){
    //     a = ancestor[a][0];
    //     b = ancestor[b][0];
    // }
    
    return ancestor[a][0];
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
    int n, q ;
    cin>>n>>q;
    for(int i = 0; i < n-1; i++){
      int a,b; 
      cin >> a>> b;
      // ancestor[a][0] = b;
      tree[a].push_back(b);
      tree[b].push_back(a);
    }
    dfs(1, -1, 0);
    for(int i = 1; i <= 20; i++){
        for(int j = 0; j<=n; j++){
            ancestor[j][i] = ancestor[ancestor[j][i-1]][i-1];    
        }
    }
    // pre_process_ancestor();
    for(int i = 0 ; i < q ; i++){
      int a, b;
      cin>>a>>b;
      // cout << depth[a] << "-" << depth[b] << endl;
      // each query will take O(LogN) == 20,
      // Q*Log(N) + preCOmputed array(Logn* N)
      // cout << a<< " - " << b << " : ";
      cout << depth[a] + depth[b] - 2*depth[get_lca(a,b)]<<endl;
    }
    return 0;
}