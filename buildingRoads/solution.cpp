#include <bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back;

## Defining Pair
#define x first;
#define y second;
#define ii pair<int,int>

void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}

vector<int> arrayList[100005];
int visited[100005];

void dfs(int i){
	visited[i] = 1;
	for(int ngh: arrayList[i]){
		if(visited[ngh] == -1){
			dfs(ngh);
		}
	}
}

int main(){
	init_code();
	int n, m;
	cin >> n >> m;
	for(int i = 0; i< m; i++){
		int a ,b;
		cin >> a >> b;
		arrayList[a].pb(b);
		arrayList[b].pb(a);
	}
	
	memset(visited, -1, sizeof visited);
	int ncomp = 0;
	vector<int> addEdges;
	for(int i = 1; i<= n; i++){
		if(visited[i] == -1){
			addEdges.push_back(i);
			dfs(i);
			ncomp++;
		}
	}
	cout << ncomp -1 << "\n";
	for(int k = 1; k < addEdges.size(); k++){
		int first = addEdges[k-1];
		int second = addEdges[k];
		cout << first << " " << second << "\n";
	}
	return 0;
}