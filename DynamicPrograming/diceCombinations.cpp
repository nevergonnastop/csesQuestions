// 1. dicCombination
// 2. Coin Combinations 
    // for each weight you are making changes using 1 to n elemenets one by one.
// 3 Coin Combinations for(int i =1; till n)
                          // for(int j = something til x)
                                // here you are making j or weight till ith element,
                                // means for each weight you are making from 1 element, 2 element and 3 element.
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
int main(){
    init_code();
    cin >> n >> x;
    vector<long long> dp(x + 1, 0);
    vector<int> coins(n + 1);
    for(int i = 1;i <=n ;i++){
        cin >> coins[i];
    }
    dp[0] = 1;
    // our aim is to create sum x while using one or more element,
    for(int i = 1; i<= n; i++){
        for(int wgt = 1; wgt <=x ; wgt++){
            if(wgt-coins[i]>=0){
                dp[wgt] = dp[wgt] + dp[wgt-coins[i]];
                dp[wgt] = dp[wgt]% MOD;
            }
        }
    }
    cout << dp[x] << endl;
    // if(dp[n] >= maxn) {
    //     cout << -1 << endl; // If result is maxn or greater, it means it's not possible to form the sum x
    // } else {
        
    // }

}