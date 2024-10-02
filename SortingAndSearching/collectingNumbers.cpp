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
void swap(vector<int>& arr,int a,int b) {
  arr[a] = arr[a] ^ arr[b];
  arr[b] = arr[a] ^ arr[b];
  arr[a] = arr[a] ^ arr[b];
}

int main(){
    init_code();
    int n,m;cin >> n >> m;
    vector<int> values(n);
    vector<int> positions(n);
    for(int i = 0; i<n ;i++){
        int val;cin >> val;
        val--;
        values[i] = val;
        positions[val] = i;
    }
    int round;
    round = 1;
    for(int i = 1; i< n; i++){
        if(positions[i] < positions[i-1]){
            round += 1;
        }
    }
    set<pair<int,int>> uniqueSet;
    for(int i = 0; i<m; i++){
    	int a,b; cin >> a >> b;

        if(values[a-1] - 1 >= 0){
            uniqueSet.insert({values[a-1] -1,values[a-1]});
        }
        if(values[a-1] + 1 < n){
            uniqueSet.insert({values[a-1], values[a-1] + 1});
        }
        if(values[b-1] - 1 >= 0){
            uniqueSet.insert({values[b-1] -1, values[b-1]});
        }
        if(values[b-1] + 1 < n){
            uniqueSet.insert({values[b-1], values[b-1] + 1});
        }
        for(pair<int,int> Pair: uniqueSet){
            round -= (positions[Pair.first] > positions[Pair.second]);
        }

 	  	swap(values[a-1], values[b-1]);
 	  	positions[values[a-1]] = a-1;
 	  	positions[values[b-1]] = b-1;
    	
        for(pair<int,int> Pair: uniqueSet){
            round += (positions[Pair.first] > positions[Pair.second]);
        }
        uniqueSet.clear();
	    cout << round << endl;
    }
    return 0;

}