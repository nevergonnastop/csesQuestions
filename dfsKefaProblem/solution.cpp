#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

// Define Pair Here.
typedef pair<int, int> pt;
#define x first;
#define y second;
int N, M;
vector<int> graph[100005];
bool hasCat[100005];
bool visited[100005];
void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}

int dfs(int node, int count){
	
	visited[node] = true;
	int numOfpaths = 0;
	int selfCount = 0;
	if(hasCat[node]){
		selfCount += 1;
	}
	if(count > 0 && count + selfCount > M){
		return 0;
	}
	int totalCount = count + selfCount;
	if(selfCount == 0){
		totalCount = 0;
	}
	int numOfNodes = 0;
	for(int ngh : graph[node]){
		if(!visited[ngh]){
			int ans = dfs(ngh, totalCount);
			numOfpaths += ans;
			numOfNodes +=1;
		}
	}
	if(numOfNodes == 0){
		// leaf Node
		return 1;
	}
	return numOfpaths;

}

int main(){
	init_code();
	cin >> N >> M;
	memset(hasCat, false, sizeof hasCat);
	memset(visited, false, sizeof visited);
	// Array to check if vertices has cat.
	for(int i = 1; i<=N; i++){
		int b;
		cin >> b;
		if(b == 1){
			hasCat[i] = true;
		}
	}
	// Create graph from inputs.
	for(int i = 0; i< N-1; i++){
		int v1,v2;
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	int count = 0;
	// if(hasCat[1]){
	// 	count += 1;
	// }
	int ans = dfs(1, count);
	cout << ans << endl;
	return 0;
}