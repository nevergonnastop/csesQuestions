#include<bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
int n, m;
vector<int> ans;
vector<int> graph[100005];
bool visited[100005];
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
	memset(visited, false, sizeof visited);
	int inorder[n+1];
	memset(inorder, 0, sizeof inorder);
	for(int i= 1; i<=m; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		inorder[b]++;
	}
	queue<int> q;
	for(int i = 1; i<= n; i++){
		if(inorder[i] == 0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int val = q.front(); q.pop();
		ans.push_back(val);
		for(int node: graph[val]){
			inorder[node]--;
			if(inorder[node] == 0){
				q.push(node);
			}
		}
	}

	if(ans.size() != n){
		cout << "IMPOSSIBLE";
	}else{
		for(int val: ans){
			cout << val << " ";
		}
	}
}
