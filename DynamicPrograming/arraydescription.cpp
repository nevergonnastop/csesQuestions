#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
#define pb push_back
#define pi pair<int, int>
#define f first
#define mp make_pair
#define s second
#define fast_io ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);


ll dp[100001][101];
// dp[i][k] = number of ways till ith index of arr where k is the last element of prefix.
// eg: 2 0 3 0 0 4
const ll MOD = (10e8) + 7;
void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
int main(){
	init_code();
	int n, m;
	cin >> n >> m;
	int arr[n + 1];
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	if(arr[1] == 0){
		fill(dp[1], dp[1] + 101, 1);
	}else{
		dp[1][arr[1]] = 1;
	}
	for(int i = 2; i<=n;i++){
		if(arr[i] == 0){
			for(int k = 1; k<=m; k++){
				dp[i][k] += dp[i-1][k] % MOD;
				if(k - 1 > 0) dp[i][k] += dp[i-1][k-1] % MOD;
				if(k + 1 <= m) dp[i][k] += dp[i-1][k+1] % MOD ;
			}
		}else{
			dp[i][arr[i]] += dp[i-1][arr[i]] % MOD;
			if(arr[i] - 1 > 0) dp[i][arr[i]] += dp[i-1][arr[i] - 1] % MOD;
			if(arr[i] + 1 <= m) dp[i][arr[i]] += dp[i-1][arr[i] + 1] % MOD;
		}
	}
	ll ans = 0;
	for(int i = 1; i <= m; i++){
		ans += dp[n][i];
		ans %= MOD;
	}
	cout << ans << endl;
}