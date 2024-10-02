#include<bits/stdc++.h>
#define ll long long
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i, a, b) for(int i = a; i < b; i++)
#define mod 1000000007
#define triplet pair<int,pair<int,int>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

double dp[(1 << 19)];
double prob[20][20];
int arr[5];
int result = 0;
vector<int> subsets;
void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
double pMove(int prevMask, int j, int& n){
	// jth fish has to die,
	int alive = __builtin_popcount(prevMask);
	int den = (alive * (alive - 1)) / 2;
	double moveProb = 0;
	for(int fish = 0; fish < n; fish++){
		if(((1 << fish) & prevMask)){
			moveProb += prob[fish+1][j+1];
		}
	}
	return moveProb*(1.0/den);
}
double solve(int mask, int& n){
	int alive = __builtin_popcount(mask);
	if(alive == n){
		return 1;
	}
	if(dp[mask] > -0.9){
		return dp[mask];
	}
	double answer = 0;
	for(int fish = 0; fish < n; fish++){
		if(!(mask & (1 << fish))){
			int prev_bitMask = mask^(1 << fish);
			double prevProb = solve(prev_bitMask, n);
			answer += pMove(prev_bitMask, fish, n)*prevProb;
		}
	}
	return dp[mask] = answer;

}
bool checkSubsetIsSquare(int mask, int n){
	if(mask == 0) return false;
	int multiplier = 1;
	for(int i = 0; i< n; i++){
		if((mask & (1 << i))){
			multiplier *= arr[i];
		}
	}
	// subsets.push_back(multiplier);

	// Check multiplier is Square Number.
	for(int i = 1; i*i <= multiplier; i++){
		if(i * i == multiplier){
			return true;
		}
	}
	return false;
}

void subsetGeneration(int mask, int i, int n){
	// it will takesh O(sqrt(N)* 2^n) solutions.
	if(i == n){
		// Check Subset is Square number
		if(checkSubsetIsSquare(mask, n)){
			// cout<<mask<<"M\n";
			result += 1;
		}
		return;
	}
	int temp_mask = mask^(1 << i);
	// cout<<temp_mask<<" + ";
	subsetGeneration(temp_mask, i + 1, n);
	subsetGeneration(mask, i + 1, n);
}
int main(){
    init_code();
    int i,j,t,n,m,p,k;
    cin >> n;
    rep(i, 0, n) cin>> arr[i];
    // cout<< arr[4] << "\n";
    cout<< result << " Before\n";
    subsetGeneration(0, 0, n);
    cout << result;
    // for(auto& it: subsets){
    // 	cout << "\n" << it;
    // }
    // cin >> t;
    // while(t--){
    //     cin>>n;
    //     memset(dp, -1, sizeof dp);
    //     rep(i, 1, n+1) rep(j, 1, n+1) cin>>prob[i][j];
    //     rep(i, 0, n)
    //     	cout << solve((1 << i), n) << " ";
    // }
    return 0;
}
