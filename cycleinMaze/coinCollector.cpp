#include<bits/stdc++.h>
using namespace std;
#define sz 200005
vector<int> graph[sz], rgraph[sz];
bool visited[sz];
vector<int> order;
int coins[sz];
int n,m;
int comp[sz];
void dfs1(int node){
	visited[node] = true;
	for(int ch : graph[node]){
		if(!visited[ch]){
			dfs1(ch);
		}
	}
	order.push_back(node);
}
void dfs2(int node, int k){
	visited[node] = true;
	comp[node] = k;
	for(int ch : rgraph[node]){
		if(!visited[ch]){
			dfs2(ch, k);
		}
	}
}
long long dfsMetaGraph(vector<unordered_set<int>> &metagraph, int node, vector<long long> &dp){
	// SImple DFS for DAG graph.(possiblility of cross edges.)
	visited[node] = true;
	long long ans = 0;
	for(int ch: metagraph[node]){
		if(visited[ch]){
			ans = max(ans, dp[ch]);
		}else{
			ans = max(ans, dfsMetaGraph(metagraph, ch, dp));
		}
	}
	return dp[node] += ans;
}

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}


int main(){
	init_code();
	cin >> n >> m;
	// FIll the coins
	for(int i = 1; i<= n; i++){
		int val;
		cin >> val;
		coins[i] = val;
	}
	// fill the graphs 
	for(int i = 1; i<=m; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b); // Directed Graph
		rgraph[b].push_back(a);
	}
	memset(visited, false, sizeof visited);
	for(int i = 1; i<=n; i++){
		if(!visited[i]){
			dfs1(i);
		}
	}
	reverse(order.begin(), order.end());
	memset(visited, false, sizeof visited);
	int k = 0;
	for(int u : order){
		if(!visited[u]){
			// scc.push_back(u);
			k++;
			dfs2(u, k);
		}
	}
	// Create a metagraph/condensed graph;
	vector<long long> dp(200005, 0);
	vector<unordered_set<int>> metagraph(200005); // (size, filling_Value)
	for(int i = 1; i<= n; i++){
		dp[comp[i]] += coins[i];
	}
	// for(int i = 1; i <= k; i++){
	// 	cout << dp[i] << " ";
	// }
	for(int i = 1; i<=n ; i++){
		for(int j : graph[i]){
			if(comp[i] != comp[j]){
				metagraph[comp[i]].insert(comp[j]);
			}
		}
	}
	// for(int i = 0; i<4; i++){
	// 	for(int group: metagraph[i+1]){
	// 		cout << group << " ";
	// 	}
	// }
	memset(visited, false, sizeof(visited));
	long long res= 0;
	for(int i = 1; i <= k; i++){
		if(!visited[i]){
			res = max(res, dfsMetaGraph(metagraph, i, dp));
		}
	}
	cout << res << endl;

	return 0;
}
