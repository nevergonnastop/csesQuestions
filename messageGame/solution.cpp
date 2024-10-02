#include <bits/stdc++.h>
using namespace std;

// int N = 1e5 + 7;
int gcost[100005]; 
// this will give the each group minimum index corresponding the index save in map.
map<string, int> groupMap;
// map stores string as a key and index as a value, index is mapped with minCost indices.
string arr[100005];
int cost[100005];
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}

int main(){
	init_code();
	int n, k, m;
	cin >> n >> k >> m;

	// Words array
	for(int a = 0; a < n; a++){
		cin >> arr[a];
	}
	// cost array
	for(int b = 0; b< n; b++){
		cin >> cost[b];
	}
	// for k groups
	for(int i = 0; i< k; i++){
		gcost[i] = (1 << 30);
		int x;
		cin >> x;
		while(x--){
			int idx;
			cin >> idx;
			idx--;
			gcost[i] = min(gcost[i], cost[idx]);
			groupMap[arr[idx]] = i; // Here for some specific group we are keeping the minimum in gcost array with corresponding index i, when we will interate through final message then for each word we can find minimum cost corresponding to this in index.
		}
	}
	int ans = 0;
	for(int i = 0; i< m; i++){
		string s;
		cin >> s;
		ans += gcost[groupMap[s]];
	}
	cout << ans << endl;
}


