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
    multiset<int> towers; // Ordered duplicate set.
    for(int i = 0; i < n ; i++){
    	auto base = towers.upper_bound(values[i]);
    	if(towers.size() == 0){
    		towers.insert(values[i]);
    	}else{
    		if(base == towers.end()){
    			towers.insert(values[i]);
    		}else{
    			towers.erase(base);
    			towers.insert(values[i]);
    		}
    	}
    }
    cout << towers.size() << endl;
    return 0;
}