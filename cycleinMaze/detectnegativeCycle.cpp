#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
 
class triplet{
public:
	int first;
	int second;
	int third;
 
};
 
 
int n, m;	
vector<triplet> edges;
vector<int> dist; // remain 0;
vector<int> relaxant;
// Step1: check n times to figure out that negative cycle exist(bascially if relaxation is still possible in nth time, then cycle exist.)
// step2: keep track of last vertex of last edge in nth iteration.
// step3: go to parents of last vertex till n times x = relaxant[x];
// step31/2: now x is denoting as negative cycle vertex(or vertex which is present in cycle.)
// step4: for(int v = x; ; v = relaxant[v])
		// {
		// 	cycle.push_back(v);
		// 	if(v == x and cycle.size() > 1)
		// 		break;
		// }

void bellman_ford()
{	
	int x;
	for(int i = 1; i <= n; ++i)
	{
		x = -1;
		for(auto e: edges)
		{
 
			int u = e.first;
			int v = e.second;
			int d = e.third;
			if(dist[u]+d < dist[v])
			{
				dist[v] = d+dist[u];
				relaxant[v] = u;
				x = v;
			}
		}
	} // n relaxations
 
	if(x == -1)
		cout << "NO" << endl;
 
	else
	{
		for(int i = 1; i <= n; ++i)
		{
			x = relaxant[x];
		}
 
		vector<int> cycle;
 
		for(int v = x; ; v = relaxant[v])
		{
			cycle.push_back(v);
			if(v == x and cycle.size() > 1)
				break;
		}
 
		reverse(cycle.begin(), cycle.end());
 
		cout << "YES" << endl;
		for(auto v: cycle)
		{
			cout << v << " ";
		}
 
		cout << endl;
	}
 
 
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	dist.resize(n+1);
	relaxant.resize(n+1);
	edges.resize(m);
 
	for(int i = 0; i < m; ++i)
	{
		struct triplet inp;
		cin >> inp.first >> inp.second >> inp.third;
		edges[i] = inp;
	}
 
	for(int i = 1; i <= n; ++i)
	{
		relaxant[i] = -1;
	}
	bellman_ford();	
}
