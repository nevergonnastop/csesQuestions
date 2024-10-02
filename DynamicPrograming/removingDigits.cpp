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
vector<int> dp(maxn, -1);

// here dfs will return number of minimum steps.
// dp[n] will count to make it zero.
int dfs(int val){
    if(val == 0){
        return 0;
    }
    if(dp[val] != -1){
        return dp[val];
    }
    int ans = maxn;
    // removing each digits
    int digit = val;
    while(digit > 0){
        int d = digit % 10;
        if(d != 0){
            int new_val = val - digit % 10;
            ans = min(ans, dfs(new_val));
        }
        digit = digit / 10;
    }
    return dp[val] = ans + 1;
}

int main(){
    init_code();
    int n;
    cin >> n;
    // int len = getLen(n);
    cout << dfs(n) << endl;
}