#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define endl "\n"
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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

int main(){
    init_code();
    int n, x;
    cin >> n >> x;
    vector<int> values(n);
    for(int i = 0; i < n; i++){
        cin >> values[i];
    }
    ordered_set<pair<int,int>> window;
    for(int i = 0; i< x; i++){
        ordered_set.insert({values[i], i});
    }
    cout << window.find_by_order((k-1)/2)->first << " ";
    for(int i = 1; i <n-k + 1; i++){
        if(window.count({values[i-1], i-1})){
            window.erase({values[i-1], i - 1});
        }
        window.insert(values[i+k-1], i + k - 1);
        cout << widow.find_by_order((k-1)/ 2)->first << " ";
    }
    return 0;
}