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
    map<int, int> occur; // sum with count
    // ll sum = 0;
    ll ans = 0;
    int j = 0;
    for(int i = 0; i< n; i++){
    	while(j < n && ((int)occur.size() < x || occur.count(values[j]) > 0)){
    		occur[values[j]]++;
    		j++;
    	}
    	ans += (j - i);
    	occur[values[i]]--;
    	if(occur[values[i]] == 0){
    		occur.erase(values[i]);
    	}
    }
    cout << ans << endl;
    return 0;
}