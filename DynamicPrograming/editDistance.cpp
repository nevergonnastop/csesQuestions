#include<bits/stdc++.h>
using namespace std;

// int dp[5001][5001];
#define fast_io ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
// int dfs(int i, int j, int m, int n, string word1, string word2){
// 	if(i == m){
// 		return n - j; // add every element of other word.
// 	}
// 	if(j == n){
// 		return m-i;
// 	}
// 	if(dp[i][j] != -1){
// 		return dp[i][j];
// 	}
// 	if(word1[i] == word2[j]){
// 		return dfs(i + 1, j + 1, m , n, word1, word2);
// 	}
// 	int ans1 = dfs(i + 1, j + 1, m , n, word1, word2); // replace
// 	int ans2 = dfs(i, j + 1, m, n, word1, word2 ); // Insert
// 	int ans3 = dfs(i + 1, j, m , n, word1, word2); // Delete
// 	int ans = 1 + min(ans1, min(ans2, ans3));
// 	return dp[i][j] = ans;
// }
// const int maxn = 1e9+7;
// int main(){
// 	init_code();
// 	string word1, word2;
// 	cin >> word1;
// 	cin >> word2;
// 	int m = word1.size();
// 	int n = word2.size();
// 	int dp[m+1][n+1];

// 	for(int i = 0; i <= m; i++){
// 		for(int j = 0; j <= n; j++){
// 			dp[i][j] = maxn;
// 		}		
// 	}
// 	dp[0][0] = 0
// 	for(int i = 0; i <= m; i++){
// 		for(int j = 0; j <= n; j++){
// 			if(i == 0){
// 				dp[i][j] = j; // if word1 has 0 len then add j elements
// 			}
// 			else if(j == 0){
// 				dp[i][j] = i;
// 			}
// 			else if (word1[i] == word2[j]){
// 				dp[i][j] = dp[i -1][j-1];
// 			}else{
// 				dp[i][j] = min(dp[i][j], 1 + min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])));
// 			}
// 		}		
// 	}
// 	cout << dp[m][n];
// }

int main() {
  string a, b;
  cin >> a >> b;
  int na = a.size(), nb = b.size();
  vector<vector<int>> dp(na+1, vector<int>(nb+1,1e9));
  dp[0][0] = 0;
  for (int i = 0; i <= na; i++) {
    for (int j = 0; j <= nb; j++) {
      if (i) {
	dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
      }
      if (j) {
	dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
      }
      if (i && j) {
	dp[i][j] = min(dp[i][j], dp[i-1][j-1]+(a[i-1] != b[j-1]));
      }
    }
  }
  cout << dp[na][nb] << endl;
}
