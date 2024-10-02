#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
 
int n, m;
vector<set<int>> g;
 
vector<int> vis;
 
stack<int> recursionStack;
 
vector<bool> rsFlag;
 
bool dfs(int u)
{
    vis[u] = true;
    recursionStack.push(u);
    rsFlag[u] = true;
    for(auto v: g[u])
    {
        if(!vis[v])
            if(dfs(v))
                return true;
 
        if(rsFlag[v])
        {
            recursionStack.push(v);
            return true;
            //no more dfs;
        }
    }
    recursionStack.pop();
    rsFlag[u] = false;
    return false;
    //no cycle was detected
}
 
 
void visit_all()
{
    for(int u = 1; u <= n; ++u)
    {
        if(!vis[u])
        {
            if(dfs(u))
                break;
        }
    }
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    g.resize(n+1);
    vis.resize(n+1);
    rsFlag.resize(n+1);
    for(int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].insert(v);
    }
    visit_all();
    if(recursionStack.empty())
    {       
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
 
    vector<int> ans;
    int temp = recursionStack.top();
    while(!recursionStack.empty())
    {
        ans.push_back(recursionStack.top());
        recursionStack.pop();
        if(ans.back() == temp and ans.size() != 1)
            break;
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(auto u: ans)
    {
        cout << u << " ";
    }
 
    
}






// #include <bits/stdc++.h>
// #define endl "\n"
// using namespace std;
// // #define int long long
// #define fast_io ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

// const int MOD = 1e9 + 7;
// // const int INF = 9e15;

// void init_code(){
//     fast_io;
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif 
// }
// vector<int> graph[100005];
// vector<bool> visited(100005, false);
// vector<bool> recursionStack(100005, false);
// stack<int> stk;

// bool dfs(int node){
//     visited[node] = true;
//     recursionStack[node] = true;
//     stk.push(node);
//     for(int ngh : graph[node]){
//         if(!visited[ngh]){
//             if(dfs(ngh)){
//                 return true;
//             }
//         }
//         else if(recursionStack[ngh]){
//             // cycle present
//             stk.push(ngh);
//             return true;
//         }
//     }
//     recursionStack[node] = false;
//     stk.pop();
//     return false;
// }

// int main(){
//     init_code();
//     int n, m;
//     cin >> n >> m;
//     for(int i = 0; i< m; i++){
//         int a, b;
//         cin >> a >> b;
//         graph[a].push_back(b);
//     }
//     vector<int> ans;
//     // ans.push_back(temp);
//     for(int i = 1; i<=n; i++){
//         if(!visited[i]){
//             if(dfs(i)){
//                 int temp = stk.top();
//                 while(!stk.empty()){
//                     int val = stk.top();
//                     ans.push_back(val);
//                     stk.pop();
//                     if(stk.top() == temp){
//                         break;
//                     }
//                 }
//                 ans.push_back(temp);
//                 reverse(ans.begin(),ans.end());
//             }
//         }
//     }
//     if(stk.empty()){
//         cout << "IMPOSSIBLE" << endl;
//         return 0;
//     }
//     // int temp = stk.top();
//     cout << ans.size() << endl;
//     for(int v: ans){
//         cout << v << " ";
//     }
//     return 0;
// }