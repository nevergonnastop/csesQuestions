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

#define ll long long
#define fast_io ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
vector<int> a(5000 + 1);
const int MOD = 1e9 + 1;
void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
// int a[2];
#define maxn 100005
vector<vector<long long>> dp(5000 + 1, vector<long long>(5000 + 1, -1));
// 
ll dfs(int first, int last, int source){
    if(first > last){
        return 0;
    }
    if(dp[first][last] != -1){
        return dp[first][last];
    }
    ll ans = 0;
    if(source == 0){
        ans = max(a[first] + dfs(first + 1, last, !source), a[last] + dfs(first, last - 1, !source));
    }else{
        ans = min(dfs(first + 1, last, 0), dfs(first, last - 1, 0));
    }
    dp[first][last] = ans;
    return dp[first][last];
}

int main(){
    init_code();    
    int n;
    cin >> n;
    for(int i = 1;i <=n ;i++){
        cin >> a[i];
    }
    cout << dfs(1, n, 0);
    return 0;
}