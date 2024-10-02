// #include<bits/stdc++.h>
// using namespace std;

// // #define int long long
// #define pb push_back
// #define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
// // #define inf 1e17
// #define rep(i, n) for(int i = 0; i<n;i++)

// int vis[100005];
// int dis1[100005], dis2[100005];

// void dij(int s, int dis[], vector<pair<int, int>> graphs[]){
//     rep(i,100003)dis[i+1]= INT_MAX;
// 	dis[s] = 0;
// 	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
// 	q.push({s,0});
// 	memset(vis, 0, sizeof vis);
// 	while(!q.empty()){
// 		int x = q.top().first;
// 		// int wgt = q.top().second;
// 		q.pop();
// 		if(vis[x]) continue;
// 		vis[x] = 1;
// 		for(pair<int,int> pr: graphs[x]){
// 			int v = pr.first;
// 			int y = pr.second;
// 			if(dis[v] > dis[x] + y){
// 				dis[v] = dis[x] + y;
// 				q.push({v, dis[v]});
// 			}
// 		}
// 	}
// }


// int32_t main(){
// 	fast
// 	int n, m; cin >> n >> m;
// 	// prepare the graph.
// 	vector<pair<int, pair<int,int>>> edges;
// 	vector<pair<int, int>> graph[100005];
// 	vector<pair<int, int>> rgraph[100005];
// 	for(int i = 0; i < m; i++){
// 		int a, b,c;cin>>a>>b>>c;
// 		edges.push_back({a,{b,c}});
// 		graph[a].push_back({b,c});
// 		rgraph[b].push_back({a,c});
// 	}
// 	dij(1, dis1, graph);
// 	dij(n, dis2, rgraph);

// 	int ans = 0;
// 	for(pair<int, pair<int,int>> pr: edges){
// 		// Access elements using std::get
//         int a = pr.first;
//         int b = pr.second.first;
//         int c = pr.second.second;
//         ans = min(ans, dis1[a]+dis2[b]+c/2);
// 	}
// 	cout << ans<< endl;
// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define rep(i, n) for(int i = 0; i < n; i++)
#define int long long

const int MAXN = 100005;
const int INF = LLONG_MAX;

int vis[MAXN];
int dis1[MAXN], dis2[MAXN];

void dij(int s, int dis[], vector<pair<int, int>> graph[]) {
    fill(dis, dis + MAXN, INF);
    dis[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, s});
    memset(vis, false, sizeof vis);

    while (!q.empty()) {
        int x = q.top().second;
        int wgt = q.top().first;
        q.pop();
        if (vis[x]) continue;
        vis[x] = 1;
        for (auto [v, y] : graph[x]) {
            if (dis[v] > dis[x] + y) {
                dis[v] = dis[x] + y;
                q.push({dis[v], v});
            }
        }
    }
}

int32_t main() {
    fast
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> edges;
    vector<pair<int, int>> graph[MAXN];
    vector<pair<int, int>> rgraph[MAXN];

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
        graph[a].push_back({b, c});
        rgraph[b].push_back({a, c});
    }

    dij(1, dis1, graph);
    dij(n, dis2, rgraph);

    int ans = INF;
    for (const auto& t : edges) {
        // Access elements using std::get
        int a = get<0>(t);
        int b = get<1>(t);
        int c = get<2>(t);
        if (dis1[a] != INF && dis2[b] != INF) {
            ans = min(ans, dis1[a] + dis2[b] + c / 2);
        }
    }

    cout << ans << endl;
    return 0;
}
