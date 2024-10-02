#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)


vector<int> graph[200005];
int subordinats[200005];
int visited[200005];

int dfs(int i){
	visited[i] = 1;
	int temp = 0;
	for(int ngh: graph[i]){
		if(visited[ngh] == 0){
			int ans = dfs(ngh);
			temp += ans + 1;
		}
	}
	subordinats[i] = temp;
	return temp;
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
	int n;
	cin >> n;
	for(int i = 2; i <= n; i++){
		int a;
		cin >> a;
		graph[i].push_back(a);
		graph[a].push_back(i);
	}
	// for(int i = 1; i<=3; i++){
	// 	cout << graph[i][0] << graph[i][1];
	// }
	memset(subordinats, 0, sizeof subordinats);
	memset(visited, 0, sizeof visited);
	dfs(1);
	// for(int i = 1; i <= n; i++){
	// 	if(!visited[i]){
	// 	int val = 
	// 	}
	// }
	for(int i = 1; i<= n; i++){
		cout << subordinats[i] << " ";
	}
	return 0;
}