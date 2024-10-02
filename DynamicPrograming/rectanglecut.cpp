#include<bits/stdc++.h>
using namespace std;
#define int long long
// int dp[5001][5001];
#define fast_io ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
signed main(){
    init_code();
    int a,b; // a = width, b = length;
    cin >> a >> b;
    int dp[a+1][b+1];// minimum number of moves require to make it square.
    for(int i = 1; i<= a; i++){
        for(int j = 1; j <=b; j++){
            if(i == j){
                dp[i][j] = 0;
                continue;
            }
            int minV = LLONG_MAX;
            // horizontal cut while making edges integers
            for(int k = 1; k < i; k++){
                minV = min(minV, dp[k][j] + dp[i-k][j]);
            }
            // vertical cutting.
            for(int k = 1; k <j; k++){
                minV = min(minV, dp[i][k] + dp[i][j-k]);
            }   
            dp[i][j] = 1 + minV;
        }
    }
    cout << dp[a][b];
}