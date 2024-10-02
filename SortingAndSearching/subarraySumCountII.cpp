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
    int n, x;
    cin >> n >> x;
    vector<int> values(n);
    for(int i = 0; i < n; i++){
        cin >> values[i];
    }
    map<ll, int> seen; // sum with count
    seen[0]++;
    ll sum = 0;
    ll count = 0;
    for(int i = 0; i < n; i++){
        sum += values[i];
        count += seen[sum-x];
        seen[sum]++;
    }
    cout << count << endl;
    return 0;
}