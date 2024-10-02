
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
// #define int long long
#define fast_io ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

const int MOD = 1e9 + 7;
void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
#define maxn 1000005
int n;
vector<vector<long long>> dp; //(1000, vector<long long>(1000,-1));
vector<vector<char>> arr;

bool isValid(int x, int y){
	if(x < 1 || y < 1 || x > n || y > n){return false;}
	if(arr[x][y] == '*'){return false;}
	return true;
}
int dx[] = {1, 0};
int dy[] = {0, 1};
int dfs(int x, int y){
	if(x == n && y == n){
		return 1;
	}
	if(dp[x][y] != -1) return dp[x][y];
	long long ans = 0;
	for(int i = 0; i<2;i++){
		int new_x = x + dx[i];
		int new_y = y + dy[i];
		if(isValid(new_x, new_y)){
			ans += dfs(new_x, new_y);
			ans %= MOD;
		}
	}
	return dp[x][y] = ans;
}

int main(){
	init_code();
	cin >> n;
	arr.resize(n + 1, vector<char>(n + 1));
    dp.resize(n + 1, vector<long long>(n + 1, -1));
	for(int i = 1; i <=n; i++){
		for(int j = 1; j <=n; j++){
			// char ch
			cin >> arr[i][j];
		}
	}
	if(arr[1][1] == '*'){
		cout << 0 << endl;
		return 0;
	}
	cout << dfs(1, 1) << endl;
	return 0 ;
}