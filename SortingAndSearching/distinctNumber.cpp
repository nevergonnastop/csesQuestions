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
	set<int> elements; // Ordered Set
	int n;
	cin >> n;
	for(int i = 0; i<n; i++){
		int ele;
		cin >> ele;
		elements.insert(ele);
	}
	cout << elements.size();
	return 0;
}