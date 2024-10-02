// #Round Trip 1
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
// #define int long long
#define fast_io ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

const int MOD = 1e9 + 7;
// const int INF = 9e15;

void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
vector<int> graph[100005];
vector<bool> visited(100005, false);
vector<int> parents(100005, -1);
int sv, ev;

bool dfs(int node, int parent){
	visited[node] = true;
	parents[node] = parent;

	for(int ngh: graph[node]){
		if(!visited[ngh]){
			if(dfs(ngh, node)){
				return true;
			}
		}
		else if(ngh != parent){
			//Cycle exist
			sv = ngh;
			ev = node;
			return true;
		}
	}
	return false;
}

int main(){
	init_code();
	cin >> n >> m;
	for(int i = 0; i<m;i++){
		int a,b;cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int mark = 0;
	// memset(visited, false, sizeof visited);
	// memset(parents, false, sizeof parents);

	for(int i = 1; i <=n; i++){
		if(!visited[i]){
			if(dfs(i, -1)){
				mark = 1;
				int cur = ev;
				int len = 1;
				vector<int> ans;
				ans.push_back(sv);
				while(cur != sv){
					ans.push_back(cur);
					cur = parents[cur];
				}
				ans.push_back(cur);
				len += 1;

				cout << ans.size() << endl;
				for(int val: ans){
					cout << val << " ";
				}
				break;
			}
			
		}
	}
	if(mark == 0){
		cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}