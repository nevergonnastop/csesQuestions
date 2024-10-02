#include <bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

// const int N = 1e5 + 10;
// int mod = 1e9 + 7;
// // int size = 0;

// int power(int a, int b){
//     if(b == 0){
//         return 1;
//     }
//     int X = power(a, b/2);
//     if(b % 2 == 0){
//         return (X * X) % mod;
//     }else{
//         return (a*(X*X) % mod)% mod;
//     }
// }
// void init_code(){
//     fast_io;
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif 
// }
// int insertVectorIntoBasis(int mask, int K, int basis[]){
//     int siz = 0;
//     for(int i = 0; i< K; i++){
//         if((mask & (1 << i)) == 0) continue;
//         if(!basis[i]){
//             basis[i] = mask;
//             siz++;
//             return siz;
//         }
//         mask ^= basis[i];
//     }
//     return siz;
// }
// void highestXorSubsetValue(){
// 	int ans = 0;

// 	for (int i = 20 - 1; i >= 0; i--) {
// 		if (!basis[i]) continue;

// 		if (ans & 1 << i) continue;

// 		ans ^= basis[i];
// 	}

// 	cout << ans << endl;
// }

int main() {


	int arr[] = {4,5,6,2,3};
	int prefXorSum[5];
	int pref = 0;
	for(int i = 0; i< 5; i++){
		pref = pref^arr[i];
		prefXorSum[i] = pref;
	}
	for(int ele: prefXorSum){
		cout << ele << " ";
	}
	// your code goes here

	// int T, K, M, val;
	// cin >> T;
	// while(T--){
	//     cin >> K >> M;
	//     int basis[K];
	//     int size = 0;
	//     memset(basis, 0, sizeof basis);
	//     for(int i = 0; i< M; i++){
	//         cin >> val;
	//         size += insertVectorIntoBasis(val, K, basis);
	//        // cout << size << K << val << "\n";
	//     }
	//     int ans = power(2, K-size);
	//     cout << (1 << k) / (1 << bs.get_sz()) << "\n";
	//     cout << ans << "\n";
	// }

}
