#include<bits/stdc++.h>
#define ll long long
#define fr(a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define triplet pair<int,pair<int,int>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

bool people[11][101];
ll dp[101][1025];  // N =< 10 which means we have to take number till 2^10. or 10 bits number 

void in(int n)
{
    string s;
    cin.ignore();
    for(int i=0;i<n;i++)
    {
        getline(cin,s);
        stringstream in(s);
        int a;
        while(in>>a)
        {
            people[i+1][a] = 1;
        }
    }
}
void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
// ll solve(int shirt, int mask, int n)
// {

//     if(mask == ((1<<n)-1))
//         return 1;

//     if(shirt > 100)
//         return 0;

//     if(dp[shirt][mask] != -1)
//         return dp[shirt][mask];
//     ll ans = 0;
//     for(int i = 1; i <= n; i++)
//     {
//         if((mask & (1<<(i-1))) != 0)
//             continue;
//         if(people[i][shirt])
//         {
//             int temp_msk = (mask|(1<<(i-1)));
//             ans = (ans + solve(shirt+1, temp_msk, n))%mod;
//         }
//     }

//     ans = (ans + solve(shirt+1, mask, n))%mod;

//     return dp[shirt][mask] = ans;
// }
ll solve(int tShirt, int mask, int numPeople){
    if(mask == ((1 << numPeople) - 1)){
        return 1;
    }
    if(tShirt > 100){
        return 0;
    }
    if(dp[tShirt][mask] != -1){
        return dp[tShirt][mask];
    }
    ll ans = 0;

    // lloop through all people 
    for(int j = 1; j <= numPeople; j++){
        // Check if person j is asssigned a tshirt already.
        if((mask & (1 << j -1)) == 0)
            // Person j is available to assigned a tshirt.
            // Now make a check if given person j owns the given tshirt
            if(people[j][tShirt]){
                // person j has tShirt available
                int temp_msk = (mask|(1<<(j-1)));
                ans = (ans + solve(tShirt + 1, temp_msk, numPeople))%mod;
            }
    }
    ans = (ans + solve(tShirt + 1, mask, numPeople))%mod;
    return dp[tShirt][mask] = ans;

}
int insertVectorIntoBasis(int mask, int K, int basis[]){
    int size = 0;
    for(int i = 0; i< K; i++){
        if(mask & (1 << i) == 0) continue;
        if(!basis[i]){
            basis[i] = mask;
            size++;
            return size;
        }
        mask ^= basis[i];
    }
    return 0;
}
int main(){
    init_code();
    ll i,j,t,n,m,p,k;
    int basis[2];
    cout << insertVectorIntoBasis(0, 2, basis);
    //fast_io;
    // cin >> t;
    // while(t--){
    //     cin>>n;
    //     memset(people, 0, sizeof people);
    //     memset(dp, -1, sizeof dp);
    //     in(n);
    //     // cout << people[1][100] << "\n";
    //     cout << solve(1, 0, n) << '\n';
    // }
    return 0;
}