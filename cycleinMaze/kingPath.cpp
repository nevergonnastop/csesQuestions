#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define pb push_back
#define pp pair<int,int>
typedef long long int ll;
using namespace std;

map<pp, bool> allow;
map<pp, bool> visited;
map<pp, ll> dist;
int n;
void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
int main(){
	init_code();
	int x0,y0,x1,y1;
	cin >> x0 >> y0 >> x1 >> y1;
	cin >> n;

	for(int i = 0; i< n; i++){
		int r, a ,b;
		cin >> r >> a >> b;
		for(int j = a; j <= b; j++){
			allow[{r, j}] = true;
			visited[{r, j}] = false;
		}
	}
	allow[{x0, y0}] = true;
	allow[{x1, y1}] = true;

	queue<pp> q;
	q.push({x0,y0});
	dist[{x0,y0}] = 0;
	// total 8 position you can go from current;
	int dx[] = {-1,-1, -1, 1, 1, 1, 0, 0};
	int dy[] = {-1, 0, 1, -1, 0, 1, -1, 1};

	while(!q.empty()){
		pp u = q.front(); q.pop();

		int u_x = u.first;
		int u_y = u.second;

		for(int i = 0; i < 8; i++){
			int new_x = u_x + dx[i];
			int new_y = u_y + dy[i];
			if(allow[{new_x, new_y}] && visited[{new_x, new_y}] == false){
				// here dist[{somex,somey}] will always give 0 if value not exist in map.
				if(!dist[{new_x, new_y}] || dist[{new_x,new_y}] > dist[{u_x, u_y}] + 1){
					dist[{new_x,new_y}] = dist[{u_x, u_y}] + 1;
					q.push({new_x, new_y});
				}
			}

		}
		visited[{u_x, u_y}] = true;
	}
	if(visited[{x1, y1}]){
		cout << dist[{x1,y1}];
	}
	else{
		cout << -1;
	}
	return 0;

}