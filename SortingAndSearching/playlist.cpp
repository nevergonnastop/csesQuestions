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

int main(){
    init_code();
    int n;cin >> n;
    vector<int> values(n);
    for(int i = 0; i<n; i++){
        cin >> values[i];
    }
    int i = 0, j= 0;
    set<int> uniSet; // Ordered set
    int ans = INT_MIN;
    while(i < n){
        while(j < n && !uniSet.count(values[j])){
            uniSet.insert(values[j]);
            j = j + 1;
        }
        int siz = uniSet.size();
        ans = max(ans, siz);
        if(j == n){
            break;
        }
        // Now reduce the i pointer.
        while(i < j && uniSet.count(values[j])){
            uniSet.erase(values[i]);
            i = i + 1;
        }
    }
    cout << ans << endl;
}