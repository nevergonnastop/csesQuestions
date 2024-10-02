// #include<bits/stdc++.h>
// using namespace std;
// #define int long long int
// #define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// void init_code(){
//     fast_io;
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif 
// }
// // int dist[100005];
// signed main(){
// 	init_code();
// 	int n,m;
// 	cin >> n >> m;
// 	vector<pair<int,int>> edges[n+1];
// 	for(int i = 0; i< m; i++){
// 		int a, b;
// 		int c;
// 		cin >> a >> b >> c;
// 		edges[a].push_back({b, c});
// 		// edges[b].push_back({a, c});
// 	}
//     vector<int> dist(n+1, LLONG_MAX);
// 	// fill(dist, dist+n+1, LLONG_MAX);
// 	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> >>Q;
// 	dist[1] = 0;
// 	Q.push({1,0});
// 	while(!Q.empty()){
// 		int id = Q.top().first;
// 		int weight = Q.top().second;
//         // auto [id, weight] = Q.top();
// 		Q.pop();
//         // if (weight>dist[id]) continue;
// 		for(pair<int,int> child : edges[id]){
// 			if(dist[child.first] > child.second + weight){
// 				dist[child.first] = weight + child.second;
// 				Q.push({child.first, dist[child.first]});
// 			}
// 		}
// 	}
// 	for(int i = 1; i<=n; i++){
// 		cout << dist[i] << " ";
// 	}

// 	return 0;
// }

#include "bits/stdc++.h"
using namespace std;
 
#define int long long int
#define double long double
#define endl '\n'
 
const int MOD = 1000000007;
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
 
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> graph[n+1];
    for (int i = 0; i < m; i++) {
        int u,v,w; cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    vector<int> dist(n+1,LLONG_MAX);
    dist[1]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> >>pq;
    pq.push({0,1});
    vector<int> parents(n + 1);
    fill(parents, parents + n + 1, -1);
    parents[1] = -1;
    while (!pq.empty()) {
        auto [d,node]=pq.top();
        pq.pop();
        if (d>dist[node]) continue;
        for(auto [child,w]: graph[node]) {
            if (dist[child]>dist[node]+w){
                dist[child] = dist[node]+w;
                parents[child] = node;
                pq.push({dist[child],child});
            }
        }
    }
 	// int max_value = 0;
 	// int cur = n;
 	// while(c != -1){
 	// 	max_value = max(dist[cur], max_value);
 	// 	cur = parents[cur];
 	// }

    for (int i = 1; i <= n; i++) {
        cout<<dist[i]<<" ";
    }
 
    return 0;
}