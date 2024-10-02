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
#define maxn 100005
// vector<int> sumVector(maxn, 0);
int n;
int main(){
    init_code();
    cin >> n;
    vector<vector<long long>> dp(n + 1, vector<long long>(maxn, 0));
    vector<int> price(n + 1);
    for(int i = 1;i <=n ;i++){
        cin >> price[i];
    }
    dp[1][price[1]] = 1;
    // cout << price[1] << endl;
    for(int i = 1;i <= n; i++){
        dp[i][0] = 1;
    }
    // dp[1][0] = 1;
    // our aim is to create sum x while using one or more element,
    for(int i = 2; i<= n; i++){
        for(int j = 1; j <=maxn; j++){
                dp[i][j] = dp[i-1][j];
                if(j - price[i] >= 0) dp[i][j] =  dp[i][j] || dp[i-1][j - price[i]];
        }
    }
    int k = 1;
    int count = 0;
    while(k <= maxn){
        if(dp[n][k] == 1){
            count++;
        }
        k++;
    }
    cout << count << endl;
    k = 1;
    while(k <= maxn){
        if(dp[n][k] == 1){
            cout << k << " ";
        }
        k++;
    }
    return 0;
}