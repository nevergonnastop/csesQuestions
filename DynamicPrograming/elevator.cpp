#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
int main(){
	init_code();
	int n, limit;
	cin >> n >> limit;
	vector<int> weights(n);
	for(int i = 0; i < n; i++){
		cin >> weights[i];
	}
	vector<pair<int,int>> dp(1<<n,{1e9, 1e9});
	dp[0] = {1,0}; // (no of rides, space_taken)
	for(int mask = 1; mask < (1<<n); mask++){
		for(int bit = 0; bit < n; bit++){
			if((mask&(1<<bit))){
				// make this bit last bit and find the answer by unsetting it.
				int space_taken = dp[mask^(1<<bit)].second;
				if(space_taken + weights[bit] <= limit){
					dp[mask] = min(dp[mask], {dp[mask^(1<<bit)].first, space_taken + weights[bit]});
				}else{
					dp[mask] = min(dp[mask], {dp[mask^(1<<bit)].first + 1, weights[bit]});
				}
			}
		}
	}
	cout << dp[(1<<n) - 1].first;
	return 0;
}