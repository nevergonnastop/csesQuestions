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
int n, x;
// int dp[104][maxn];
vector<int> coins;
// dp[x] will show that number of minimum coins to make sum x while array is giving.;
// int dfs(int idx, int sumV, int x, int n){
//     // we are checking for all idx < and > n;
//     if(sumV > x){
//         return maxn;
//     }
//     if(sumV == x){
//         return 0;
//     }
//     if(idx > n){
//         return maxn;
//     }
//     if(dp[idx][sumV] != -1){
//         return dp[idx][sumV];
//     }
//     int ans = maxn;
//     int finalAns = maxn;
//     for(int i = idx; i<=n; i++){
//         ans = min(ans, dfs(i + 1, sumV + coins[i], x ,n));
//         ans = min(ans, dfs(i, sumV + coins[i], x, n));
//         // for above two dfs I have spend one coin so I will add my contri in ans as 1.
//         finalAns = min(finalAns, ans + 1);
//         finalAns = min(finalAns, dfs(i + 1, sumV, x, n));

//     }
//     return dp[idx][sumV] = finalAns;
// }

int main(){
    init_code();
    cin >> n >> x;
    coins.resize(n + 1);
    for(int i = 1; i<= n; i++){
        // int a;
        cin >> coins[i];
    }
    // Initialize dp array with -1
    // for(int i = 0; i <= n; i++){
    //     for(int j = 0; j <= 1000005; j++){
    //         dp[i][j] = -1;
    //     }
    // }
    // int result = dfs(1, 0, x, n);
    vector<int> dp(x + 1, maxn);
    dp[0] = 0;
    // our aim is to create sum x while using one or more element,
    for(int i = 1; i<=n; i++){
        for(int wgt = 0; wgt <=x ; wgt++){
            if(wgt - coins[i] >= 0){
                // it means if I am making some wgt using combination of all the elments.
                dp[wgt] = min(dp[wgt], dp[wgt - coins[i]] + 1);
            }
        }
    }
    // // our aim is to create sum x while using one or more element,
    // for(int wgt = 0; wgt <=x ; wgt++){
    //     for(int i = 1; i<=n; i++){
    //         if(wgt - coins[i] >= 0){
    //             // it means if I am making some wgt using combination of all the elments.
    //             dp[wgt] = min(dp[wgt], dp[wgt - coins[i]] + 1);
    //         }
    //     }
    // }

    if(dp[x] >= maxn) {
        cout << -1 << endl; // If result is maxn or greater, it means it's not possible to form the sum x
    } else {
        cout << dp[x] << endl;
    }

}