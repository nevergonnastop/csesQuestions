#include<bits/stdc++.h>
using namespace std;
#define sz 200005
vector<int> graph[sz], rgraph[sz];
bool visited[sz];
vector<int> scc;
vector<int> order;
int comp[sz];
int n,m;
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
			dfs2(ch);
		}
	}
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
	for(int u: order){
		if(!visited[u]){
			scc.push_back(u);
			dfs2(u, k);
			k++;
		}
	}
	if(scc.size() > 1){
		cout << "NO" << endl;
		cout << scc[1] << " " << scc[0] << endl;
	}else{
		cout << "YES";
	}

}
