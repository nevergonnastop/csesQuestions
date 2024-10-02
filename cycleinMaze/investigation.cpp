#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long
 
int n, m;
vector<vector<pair<int,int>>> g;
vector<int> dist;
vector<int> minFlights;
vector<int> maxFlights;
vector<int> ways;

const int MOD = 1e9 + 7;
const int INF = 9e15;

void dij(int node, vector<vector<pair<int,int>>> &graph)
{
    priority_queue <
      pair<int,int>, 
      vector<pair<int,int>>, 
      greater<pair<int,int>>
    > pq; 
 
    pq.push({0,1});
 	minFlights[node] = 0;
 	dist[node] = 0;
 	maxFlights[node] = 0;
 	ways[node] = 1;
    while(!pq.empty())
    {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        for(auto e: graph[u])
        {
            int v = e.first;
            int c = e.second;
 
            if(dist[v] > c + d) 
            {
                dist[v] = c+d;
                minFlights[v] = minFlights[u] + 1;
                maxFlights[v] = maxFlights[u] + 1;
                ways[v] = ways[u] % MOD;
                pq.push({dist[v], v});
            }else if(dist[v] == c + d){
            	maxFlights[v] = max(maxFlights[v], maxFlights[u] + 1);
            	minFlights[v] = min(minFlights[v], minFlights[u] + 1);
            	ways[v] += ways[u] % MOD;
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    g.resize(n+1);
    dist.resize(n+1);
    ways.resize(n+1);
    minFlights.resize(n+1);
    maxFlights.resize(n+1);
    for(int i = 1; i <= n; i++)
    {
    	dist[i] = INF;
    	minFlights[i] = 0;
    	maxFlights[i] = 0;
    	ways[i] = 0;
    }

    for(int i =0; i<m; i++){
    	int a,b,c;
    	cin >> a >> b >> c;
    	g[a].push_back({b,c});
    }

    dij(1, g);
    cout << dist[n] << " " << ways[n] << " " << minFlights[n] << " " << maxFlights[n] << endl;

    return 0;
}