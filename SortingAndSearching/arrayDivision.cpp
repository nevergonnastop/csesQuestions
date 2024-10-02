#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
// #define int long long
#define fast_io ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

typedef long long ll;
const int MOD = 1e9 + 7;
void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
int main(){
    init_code();
    int n, k;
    cin >> n >> k;
    vector<int> values(n);
    int maxValue = 0;
    for(int i = 0; i < n; i++){
        cin >> values[i];
        maxValue = max(maxValue, values[i]);
    }
    ll hi = 1e18;
    ll lo = maxValue;
    ll maxSum = 1e18;

    while(lo <= hi){
        ll sum = 0;
        ll mid = (lo + hi) / 2;
        int blocks = 1;
        for(int i = 0; i<n ;i++){
            if(sum + values[i] > mid){
                sum = 0;
                blocks += 1;
            }
            sum += values[i];
        }
        if(blocks > k){
            lo = mid + 1;
        }else{
            if(maxSum > mid){
                maxSum = mid;
            }
            hi = mid - 1;
        }
    }
    cout << maxSum << endl;
    return 0;
}