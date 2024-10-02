#include<bits/stdc++.h>
using namespace std;

int tilings[1001][1<<10];
int n, m;
#define fast_io ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
const int MOD = 1000000007;

void fill_column(int column, int idx, int cur_mask, int new_mask){
	if(idx == n){
		tilings[column + 1][new_mask] = (tilings[column + 1][new_mask] + tilings[column][cur_mask]) % MOD;
		return;
	}
	if((cur_mask)&(1<<idx)){
		fill_column(column, idx + 1, cur_mask, new_mask);
	}else{
		// Horizontal tile
		fill_column(column, idx + 1, cur_mask, new_mask|(1<<idx));
		// Vertical tile
		if(idx + 1 < n && (!(cur_mask&(1<<(idx + 1))))){
			fill_column(column, idx + 2, cur_mask, new_mask);
		}
	}
}



int main(){
	init_code();
	cin >> n >> m;
	tilings[0][0] = 1;
	for(int column = 0; column < m; column++){
		for(int mask = 0; mask < (1 << n); mask++){
			if(tilings[column][mask] > 0){
				fill_column(column,0, mask, 0);
			}
		}
	}
	cout << tilings[m][0];

}