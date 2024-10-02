#include<bits/stdc++.h>
using namespace std;
int N;
vector<int> graph[100005];
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
int sets[2];

void dfs(int node, bool color, int parent){
	sets[color] += 1;
	for(int ngh : graph[node]){
		if(ngh != parent){
			dfs(ngh, !color, node);
		}
	}
}

int main(){
	cin >> N;
	for(int i = 1; i<= N-1;i++){
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	dfs(1,0,-1);
	long long l = sets[0];
	long long r = sets[1];
	// set1 and set2 has l and r elements total edges possible l*r and graph will still be bipartite as vertices of one set do not make any edges to each other.
	// given already n -1 edges
	// int ans = l*r - N + 1;
	cout << l*(N-l) - N + 1 << endl;
	return 0;
}