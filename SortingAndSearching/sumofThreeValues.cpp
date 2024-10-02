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
    int n;ll x;
    cin >> n >> x;
    int i,j,k;
    vector<pair<ll,int>> values(n); // pair.first value and pair.second index.
    for(i = 0; i<n; i++){
        cin >> values[i].first;
        values[i].second = i + 1;
    }
    sort(values.begin(), values.end());
    for(i = 0; i<n; i++){
        j = i + 1;
        k = n - 1;
        while(j < k){
            ll curSum = values[i].first + values[j].first + values[k].first;
            if(curSum == x){
                cout << values[i].second << " " << values[j].second << " " << values[k].second;
                return 0;
            }else if(curSum < x){
                j++;
            }else{
                k--;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}