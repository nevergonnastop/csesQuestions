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
    vector<bool> contains(n);
    vector<bool> contained(n);
    for(int i = 0; i<n; i++){
        cin >> ranges[i].l;
        cin >> ranges[i].r;
        ranges[i].index = i;
    }
    sort(ranges.begin(), ranges.end());
    int max_bnd = 0;
    for(int i = 0; i< n; i++){
        if(ranges[i].r <= max_bnd){
            contained[ranges[i].index] = 1;
        }
        max_bnd = max(max_bnd, ranges[i].r);
    }
    int min_bnd = INT_MAX;
    for(int j = n-1; j >= 0; j--){
        if(ranges[j].r >= min_bnd){
            contains[ranges[j].index] = 1;
        }
        min_bnd = min(min_bnd, ranges[j].r);
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