#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

#define ll long long
#define fast_io ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
vector<int> a(5000 + 1);
const int MOD = 1e9 + 7;
void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
// int a[2];
#define maxn 100005
ll power(ll a, ll b, ll m) {
    ll result = 1;
    a = a % m;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % m;
        }
        b = b >> 1;
        a = (a * a) % m;
    }
    return result;
}

ll powerInverse(ll a, ll m) {
    return power(a, m - 2, m);
}
int main(){
    init_code();
    int n;
    cin >> n;
    if(n == 1){
        cout << 0;
        return 0;
    }
    int getSum = (n*(n + 1))/4;
    vector<vector<long long>> dp(500 + 1, vector<long long>(n*n/2, 0));

    dp[0][0] = 1;
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<=getSum; j++){
            if(j == 0){
                dp[i][j] = 1;
            }else{
                dp[i][j] = dp[i-1][j] % MOD;
                if(j >= i) dp[i][j] = (dp[i][j] + dp[i-1][j-i]) % MOD;
            }
        }
    }
    if((n*(n+1)) % 4 != 0){
        cout << 0;
    }
    else{
        cout << (dp[n][getSum] * powerInverse(2,MOD)) % MOD;
    }
    return 0;
}
