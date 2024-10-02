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
#define INF 1e18;
typedef long long ll;

int main(){
    init_code();
    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> values(n+1);
    for(int i =1 ;i<=n; i++){
        cin >> values[i];
    }
    // Prefix sum array
    for(int i = 1; i<=n; i++){
        values[i] += values[i-1];
    }
    set<pair<ll,int>> rightBoundaries;
    for(int i = a; i<=b; i++){
        rightBoundaries.insert({values[i], i});
    }
    ll maxSum = -INF;
    // O(NLogN)
    for(int i = 1; i<= n-a+1; i++){
        maxSum = max(maxSum, rightBoundaries.rbegin()->first - values[i-1]);
        rightBoundaries.erase({values[i+a-1], i+a-1});
        if(i + b <= n){
            rightBoundaries.insert({values[i+b], i + b});
        }
    }
    rightBoundaries.clear();
    cout << maxSum << endl;
    return 0;
}