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
    int n;// n : number of machines, t = no of products.
    cin >> n;
    ll sumV = 0;
    ll maxV = 0;
    for(int i = 0; i<n; i++){
        ll val;cin >> val;
        maxV = max(maxV, val);
        sumV += val;
    }
    cout << max(2*maxV, sumV) << endl;
    return 0;
}