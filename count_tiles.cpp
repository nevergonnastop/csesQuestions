count_tiles.cpp
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define goog(tno) cout << "Case #" << tno <<": "
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin >> x
using namespace std;
int dp[1001][1<<11];
int main() {
   init_code();
   int t = 1; //cin >> t;
   while(t--){
        read(n); read(m);
        memset(dp, -1, sizeof dp);
        cout << solve(0, 0, m, n); 
   }
   return 0;
}
void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}

int solve(int col, int mask, int m, int n){
	// m and n cols and rows respectively.
	// BaseCAse
	if(col == m){
		if(mask == 0){
			return 1;
		}
		return 0;
	}

	if(dp[col][mask]!= -1){
		return dp[col][mask];
	}
	vector<int> next_masks;
	generate_masks_next_col(0, mask, 0, next_masks, n);
	int answer = 0;
	for(int next_col_mask : next_masks){
		answer += (solve(col + 1, mask, m, n)) % mod;
	}
	return dp[col][mask] = answer;
}

void generate_masks_next_col(int row, int current_mask, int next_mask, vector<int> next_masks, int n){
	if(row >= n){
		next_masks.push_back(next_mask);
		return;
	}
	// First condition check if that specific row, col vlaue is empty.
	if(current_mask & (1 << row) != 0){
		generate_masks_next_col(row + 1, current_mask, next_mask, next_masks, n);
	}
	// if it is not last row you can add 2*1 tile.
	if(row != n-1){
		// adding the 2*1 tile
		if(current_mask & (1 << row) == 0 && current_mask & (1 << row + 1) == 0){
			generate_masks_next_col(row + 2, current_mask, next_mask, next_masks, n)
		}
	}
	// inserting the 1*2 tile.
	if(current_mask & (1 << row) == 0){
		generate_masks_next_col(row + 1, current_mask, next_mask + (1 << row), next_masks, n);
	}
}