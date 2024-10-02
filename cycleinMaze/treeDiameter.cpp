#include<bits/stdc++.h>
using namespace std;

// #define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
// #define pp pair<int, int>
// int n;
// void init_code(){
//     fast_io;
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif 
// }
// // Approach new: 
// vector<int> graph[200005];
// bool visited[200005];
// pp nodeInfo[200005];

// pp dfs(int index){
// 	int selfDia = 0;
// 	int height = 0;
// 	visited[index] = true;
// 	int nodeCount = 0;
// 	int nodesDia = 0;
// 	int firstMax =0;
// 	int secondMax = 0;
// 	for(int node: graph[index]){
// 		if(!visited[node]){
// 			pp ansNode = dfs(node);
// 			int nodeDia = ansNode.second;
// 			int nodeHgt = ansNode.first;
			
// 			height = max(nodeHgt, height);
// 			nodesDia = max(nodesDia, nodeDia);

// 			if(firstMax < nodeHgt){
// 				int temp = firstMax;
// 				firstMax = nodeHgt;
// 				secondMax = temp;
// 			}
// 			else if(secondMax < nodeHgt) {
//                 secondMax = nodeHgt;
//             }

// 			nodeCount++;
// 		}
// 	}
// 	selfDia = firstMax + secondMax;
// 	if(nodeCount == 0){
// 		nodeInfo[index].first = 1;
// 		nodeInfo[index].second = 1;
// 		return nodeInfo[index];
// 	}
// 	// cout << height << " ";
// 	selfDia = max(nodesDia, selfDia);
// 	nodeInfo[index].second = selfDia;
// 	nodeInfo[index].first = height + 1;
// 	return nodeInfo[index];
// }


// int main(){
// 	init_code();
// 	cin >> n;
// 	if(n == 1){
// 		cout << 0 << endl;
// 		return 0;
// 	}
// 	for(int i = 0; i< n-1; i++){
// 		int a, b;
// 		cin >> a >> b;
// 		graph[a].push_back(b);
// 		graph[b].push_back(a);
// 	}
// 	memset(visited, false, sizeof visited);
// 	pp ans = dfs(1);
// 	// for(int i = 1; i<= 10; i++){
// 	// 	cout << i  << "-" << nodeInfo[i].first << "---" << nodeInfo[i].second << endl;
// 	// }
// 	cout << ans.second;
// 	return 0;

// }


/// Second Approach
// find left most and right most node, and then do dfs from both of them, and at the end take max(d_left_most[i], d_right_most[i]). will give distance from i the nodde to maxDistance.

#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
int n, x, y;
vector<int>graph[200005];
int vis[200005];
int d[200005];
void dfs(int idx, int par, int par_ans){
	vis[idx] = true;
	d[idx] = par_ans;
	for(int node: graph[idx]){
		if(node != par){
			dfs(node, idx, d[idx] + 1);
		}
	}
}
void init_code(){
    fastio;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
#define pb push_back
int main(){
	init_code();
    //cout<<setprecision(20)<<fixed ;
    int t=1;
    // cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n-1;i++){
            int x, y;cin>>x>>y;
            graph[x].pb(y);
            graph[y].pb(x);
        }
        // memset(par, 0, sizeof(par));
        memset(vis, 0, sizeof(vis));
        memset(d, 0, sizeof(d));
        // par[1]=0;
        dfs(1, 0, 0);
        int node1 = -1, node2 = -1, ma = INT_MIN;
        for(int i=2;i<=n;i++){
            if(ma<d[i]){
            	// cout << d[i];
                node1 = i;
                ma = d[i];
            }
        }
        
        
        ma=INT_MIN;
        memset(vis, 0, sizeof(vis));
        memset(d, 0, sizeof(d));
        dfs(node1, 0, 0);

        // int mn = INT_MIN;
        for(int i = 0; i<=n;i++){
        	// cout << d[i] << "--";
        	ma = max(ma, d[i]);
        }
        cout << ma << endl;
        return 0;
	}
}
