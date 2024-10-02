#include<bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pp pair<int,int>
typedef long long int ll;
map<pp, int> dist;
map<pp, bool> visited;
map<pp, char> graph;
int n, m,k;
// lexigraphical order
char lorder[] = {'D', 'L', 'R', 'U'};
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};  //dx and dy shows d, l, r, u in order.
void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
bool isValid(int x, int y){
	if(x < 1 || y < 1 || x > n || y > m){return false;}
	if(graph[{x,y}] == '*' || visited[{x,y}] == true){return false;}
	return true;
}
bool isValidModified(int x, int y){
	if(x < 1 || y < 1 || x > n || y > m){return false;}
	if(graph[{x,y}] == '*'){return false;}
	return true;
}
void bfs(int x, int y){
	queue<pp> q;
	dist[{x, y}] = 0;
	q.push({x,y});
	// visited[{x,y}] = true;
	while(!q.empty()){
		int v1,v2;
		v1 = q.front().first;
		v2 = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++){
			int new_x, new_y;
			new_x = v1 + dx[i];
			new_y = v2 + dy[i];
			if(isValidModified(new_x, new_y) && visited[{new_x,new_y}] == false){
				dist[{new_x,new_y}] = dist[{v1,v2}] + 1;
				q.push({new_x, new_y});
			}
		}
		visited[{v1, v2}] = true;
	}
}



int main(){
	init_code();
	cin >> n >> m >> k;
	int x0, y0;
	for(int i= 1; i<=n; i++){
		for(int j = 1; j <= m; j++){
			char ch;
			cin >> ch;
			if(ch == 'X'){
				x0 = i;
				y0 = j;
			}
			graph[{i, j}] = ch;
		}
	}
	bfs(x0,y0);
	int sr, sc;
	sr = x0;
	sc = y0;
	string ans = "";
	for(int i = 0; i < k; i++){
		for(int j = 0; j < 4; j++){
			// Move D, L, R, U in order to lexigraphically alphabets order.
			int new_x = sr + dx[j];
			int new_y = sc + dy[j];
			if(isValidModified(new_x, new_y)){
				if(dist[{new_x, new_y}] < k - i){
					sr = new_x;
					sc = new_y;
					ans += lorder[j];
					break;
				}
			}
		}
	}
    // cout << ans << endl;
	if(k % 2 == 1 || ans.size() != k){
		cout << "IMPOSSIBLE" << endl;
	}
	else{
		cout << ans << endl;
	}
	return 0;

}









//// Optimized Version

// #include <bits/stdc++.h>
// #define INF (int) 1e9
// using namespace std;

// const char dl[] = {'D', 'L', 'R', 'U'};
// const int dr[] = {1, 0, 0, -1};
// const int dc[] = {0, -1, 1, 0};

// int n, m, k;
// vector<vector<char>> g;
// vector<vector<int>> dist, color;

// void bfs(int sr, int sc) {
//   queue<tuple<int, int, int>> q;
//   q.push({sr, sc, 0});
//   while (!q.empty()) {
//     auto [r, c, d] = q.front(); q.pop();
//     bool roob = r < 0 or r >= n;
//     bool coob = c < 0 or c >= m;
//     if (roob or coob or g[r][c] == '*' or color[r][c] == 1) {
//       continue;
//     }
//     q.push({r + 1, c, d + 1});
//     q.push({r - 1, c, d + 1});
//     q.push({r, c + 1, d + 1});
//     q.push({r, c - 1, d + 1});
//     dist[r][c] = d;
//     color[r][c] = 1;
//   }
// }

// int main() {
//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cin >> n >> m >> k;
//   g.assign(n, vector<char>(m));
//   dist.assign(n, vector<int>(m, INF));
//   color.assign(n, vector<int>(m, 0));
//   int sr, sc;
//   for (int r = 0; r < n; r++) {
//     for (int c = 0; c < m; c++) {
//       cin >> g[r][c];
//       if (g[r][c] == 'X') {
//         sr = r, sc = c;
//         g[r][c] = '.';
//       }
//     }
//   }
//   bfs(sr, sc);
//   string ans;
//   int r = sr, c = sc;
//   for (int i = 0; i < k; i++) {
//     for (int j = 0; j < 4; j++) {
//       int nr = r + dr[j], nc = c + dc[j];
//       bool roob = nr < 0 or nr >= n;
//       bool coob = nc < 0 or nc >= m;
//       if (roob or coob or g[nr][nc] == '*') {
//         continue;
//       }
//       if (dist[nr][nc] < k - i) {
//         r = nr, c = nc;
//         ans += dl[j];
//         break;
//       }
//     }
//   }
//   if (k % 2 == 1 or ans.size() != k) {
//     cout << "IMPOSSIBLE" << endl;
//   } else {
//     cout << ans << endl;
//   }
//   return 0;
// }