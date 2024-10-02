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
struct range{
    int l, r , index;
    bool operator <(const range&other) const{
        if(other.l == l){
            return r > other.r;
        }
        return l < other.l;
    }
};

int main(){
    init_code();
    int n;
    cin >> n;
    vector<range> ranges(n);
    vector<int> contains(n);
    vector<int> contained(n);
    ordered_set<pair<int,int>> rightBoundaries;

    for(int i = 0; i<n; i++){
        cin >> ranges[i].l;
        cin >> ranges[i].r;
        ranges[i].index = i;
    }
    sort(ranges.begin(), ranges.end());
    // int max_bnd = 0;
    for(int i = 0; i< n; i++){
        // it helps finding the kth smallest element.
        rightBoundaries.insert({ranges[i].r, -1*i});
        contained[ranges[i].index] = 
                    rightBoundaries.size() - rightBoundaries.order_of_key({ranges[i].r, -1*i}) - 1;
    }
    rightBoundaries.clear();
    // int min_bnd = INT_MAX;
    for(int j = n-1; j >= 0; j--){
        rightBoundaries.insert({ranges[j].r, -1*j});
        contains[ranges[j].index] = rightBoundaries.order_of_key({ranges[j].r, -1*j});
    }
    for(int i = 0; i<n;i++){
        cout << contains[i] << " ";
    }
    cout << endl;
    for(int i = 0; i<n; i++){
        cout << contained[i] << " ";
    }
    return 0;
}