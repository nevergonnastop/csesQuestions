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
vector<int> price;
vector<int> pages;
int main(){
    init_code();
    cin >> n >> x;

    price.resize(n + 1);
    pages.resize(n + 1);
    for(int i = 1; i<= n; i++){
        // int a;
        cin >> price[i];
    }
    for(int i = 1; i<= n; i++){
        // int a;
        cin >> pages[i];
    }
    int dp[n+1][x+1];
    // our aim is to create sum x while using one or more element,
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= x; j++){
            if(j == 0 || i == 0){
                dp[i][j] = 0;
                // continue;
            }
            else{
                int op1 = dp[i-1][j];
                int op2 = (j < price[i])? 0 : pages[i] + dp[i-1][j - price[i]];
                dp[i][j] = max(op1, op2);
            }

        }
    }

    cout << dp[n][x] << endl;
}