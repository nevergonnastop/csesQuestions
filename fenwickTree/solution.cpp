#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> bit;

void update(int id, int val){
	while(id <= n){
		bit[id] += val;
		id += (id & -id); 
		// this step will make changes to all effective positions like at id and till all the values where id position value make impact.
	
}
int query(int id){
	int ans = 0;
	while(id > 0){
		ans += bit[id];
		id -= (id & -id);
	}
	return ans;
}

int main(){
	cin >> n;
	vector<int> bit(n+1, 0);
	vector<int> a(n+1);
	for(int i = 1; i<= n; i++){
		cin >> a[i];
		update(i, a[i]);  // (1, 2 ,4,8)in bit array it will be added
	}
	int q;
	cin >> q;
	while(q--){
		int typeOfQuery;
		cin >> typeOfQuery;
		if(typeOfQuery == 1){ //find the sum of range L to R...
			int L, R; cin >> L >> R;
			int ans = query[R] - query[L-1];
			cout << ans << endl;
		}else{
			// update the val at index 
			int id,val; cin >> id >> val;
			update(id, -a[id]);
			a[id] = val;
			update(id, a[id]);
		}
	}
}