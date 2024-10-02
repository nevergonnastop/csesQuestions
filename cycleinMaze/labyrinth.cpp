// #include<bits/stdc++.h>
// using namespace std;

// #define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
// char graph[1005][1005];
// int dist[1005][1005];
// int n, m;
// char parent[1005][1005];
// typedef pair<int, int> pt;
// // #define x first;
// // #define y second;

// bool isValid(int x, int y){
// 	if(x < 1 || x > n || y < 1 || y > m){
// 		return false;
// 	}
// 	if(graph[x][y] == '#' && visited[x][y] == true) return false;
// 	return true;
// }
// void init_code(){
//     fast_io;
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif 
// }
// void bfs(int x, int y){
// 	queue<pair<int,int>> q;
// 	q.push({x,y});
// 	dist[x][y] = 0;
// 	parent[x][y] = 'S'; // No parent for this element. 
// 	while(!q.empty()){
// 		pair<int,int> node = q.front();
// 		q.pop();
// 		int a,b;
// 		a = node.first;
// 		b = node.second;
// 		// UP
// 		if(graph[a][b] == 'B'){
// 			return;
// 		}
// 		if(isValid(a - 1, b)){
// 			if(dist[a - 1][b] == INT_MAX || dist[a-1][b] > dist[a][b] +1){
// 				dist[a-1][b] = dist[a][b] + 1;
// 				parent[a-1][b] = 'U';
// 				q.push({a-1 , b});
// 			}
// 		}
// 		// Down
// 		if(isValid(a + 1, b)){
// 			if(dist[a+1][b] == INT_MAX || dist[a+1][b] > dist[a][b] + 1){
// 				dist[a+1][b] = dist[a][b] + 1;
// 				parent[a+1][b] = 'D';
// 				q.push({a+1, b});
// 			}
// 		}
// 		// Right
// 		if(isValid(a, b + 1)){
// 			if(dist[a][b+1] == INT_MAX || dist[a][b+1] > dist[a][b] + 1){
// 				dist[a][b+1] = dist[a][b] + 1;
// 				parent[a][b+1] = 'R';
// 				q.push({a, b+1});
// 			}
// 		}
// 		// left
// 		if(isValid(a, b - 1)){
// 			if(dist[a][b-1] == INT_MAX || dist[a][b-1] > dist[a][b] + 1){
// 				dist[a][b-1] = dist[a][b] + 1;
// 				parent[a][b-1] = 'L';
// 				q.push({a, b-1});
// 			}
// 		}
// 	}

// }

// int main(){
// 	init_code();
// 	cin >> n >> m;
// 	int x, y;
// 	int b_x,b_y;

// 	for(int i = 1; i<= n; i++){
// 		for(int j = 1; j<=m; j++){
// 			dist[i][j] = INT_MAX;
// 			parent[i][j] = '$';
// 			char ch;
// 			cin >> ch;
// 			if(ch == 'A'){
// 				x = i;
// 				y = j;
// 			}
// 			if(ch == 'B'){
// 				b_x = i;
// 				b_y = j;
// 			}
// 			graph[i][j] = ch;
// 		}
// 	}
// 	bfs(x, y);
// 	// cout << dist[x][y];
// 	if(dist[b_x][b_y] == INT_MAX){
// 		cout << "NO";
// 		return 0;
// 	}
// 	cout << "YES" << endl;
// 	cout << dist[b_x][b_y] << endl;
// 	vector<char> path;
// 	// cout << x << y;
// 	int y_x = b_x, y_y = b_y;
// 	while(1){
// 		if(parent[y_x][y_y] == 'U'){y_x = y_x -1; path.push_back('D');}
// 		if(parent[y_x][y_y] == 'D'){y_x = y_x +1; path.push_back('U');}
// 		if(parent[y_x][y_y] == 'R'){y_y = y_y +1; path.push_back('L');}
// 		if(parent[y_x][y_y] == 'L'){y_y = y_y -1; path.push_back('R');}
// 		if((y_x == x) && (y_y == y)){
// 			break;
// 		}
// 	}

// 	for(char chr: path){
// 		cout << chr << "";
// 	}
// 	return 0;
// }


///
#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;
 
char ar[1001][1001];
char br[1001][1001];
bool vis[1001][1001];
int n , m;
vector<char> path;
 
bool isValid(int x , int y){
	
	if(x < 1 || x > n || y < 1 || y > m) return false;
	
	if(ar[x][y] == '#' || vis[x][y] == true) return false;
	
	return true;
}
 
bool bfs(int x , int y)
{
	queue<pair<int,int> > q;
	q.push({x , y});
	vis[x][y] = true;
	
	while(!q.empty()){
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		
		if(ar[a][b] == 'B'){
			while(1){
				path.push_back(br[a][b]);
			
				if(path.back() == 'L') b++;
				if(path.back() == 'R') b--;
				if(path.back() == 'U') a++;
				if(path.back() == 'D') a--;
				
				if(a == x && b == y)
				break;
			}
			return true;
		}
		
		//left
		if(isValid(a , b - 1)) br[a][b-1] = 'L' , q.push({a , b-1}) , vis[a][b-1] = true;
		
		//right
		if(isValid(a , b + 1)) br[a][b+1] = 'R' , q.push({a , b+1}) , vis[a][b+1] = true;
		
		//up
		if(isValid(a - 1, b)) br[a - 1][b] = 'U' , q.push({a - 1 , b}) , vis[a-1][b] = true;
		
		//down
		if(isValid(a + 1, b)) br[a + 1][b] = 'D' , q.push({a + 1 , b}) , vis[a+1][b] = true;
		
	}
	
	return false;
}
 
int main()
{
	cin>>n>>m;
	int x;
	int y;
	
	REP(i , n) REP(j , m){
		cin>>ar[i][j];
		if(ar[i][j] == 'A') x = i , y = j;
	}
	
	if(bfs(x , y) == true){
		cout<<"YES"<<endl<<path.size()<<endl;
		while(path.size() > 0) cout<<path.back() , path.pop_back();
	}
	else{
		cout<<"NO";
	}
}
 
