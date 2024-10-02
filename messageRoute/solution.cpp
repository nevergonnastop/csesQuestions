#include<bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
vector<int> graph[100005];
int dist[100005];
int n, m;
int parent[100005];

void bfs(int node){
	queue<int> q;
	q.push(node);
	dist[node] = 1;
	parent[node] = node;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int ngh: graph[v]){
			if(dist[ngh] == INT_MAX || dist[ngh] > dist[v] + 1){
				// cout << ngh << " ";
				dist[ngh] = dist[v] + 1;
				q.push(ngh);
				parent[ngh] = v;
			}
		}
	}
}
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
	for(int i = 1; i<= m; i++){
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	// memset(dist, INT_MAX, sizeof dist);
	fill(dist, dist + 100005, INT_MAX);
	memset(parent, -1, sizeof parent);
	bfs(1);
	if(dist[n] == INT_MAX){
		cout << "IMPOSSIBLE";
		return 0;
	}
	cout << dist[n] << endl;
	int val = n;
	vector<int> reverseArray;
	while(val != parent[val]){
		reverseArray.push_back(val);
		val = parent[val];
	}
	reverseArray.push_back(val);
	// reverse(reverseArray.begin(), reverseArray.end());
	for(int i = reverseArray.size()-1; i >=0 ; i--){
		cout << reverseArray[i] << " " ;
	}
	return 0;
}
