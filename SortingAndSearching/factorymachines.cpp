#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
// using namespace __gnu_pbds;
// template <typename T>
// using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
    int n,t; // n : number of machines, t = no of products.
    cin >> n >> t;
    vector<int> machines(n);
    for(int i = 0; i<n; i++){
        cin >> machines[i];
    }
    ll lo = 0,hi = 1e18; // lo time 1 to time 1e18
    ll ans = 1e18;
    while(lo <= hi){
        ll mid = (lo + hi) / 2;
        ll products = 0;
        for(int i = 0; i< n; i++){
            products += min(mid/machines[i], (ll)1e9);
        }
        if(products >= t){
            if(mid < ans){
                ans = mid;
            }
            hi = mid - 1;

        }else{
            lo = mid + 1;
        }

    }
    cout << ans << endl;
    return 0;
}