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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> apartments(m);
    vector<int> applicants(n);

    for(int i = 0; i<n; i++){
        cin >> applicants[i];
    }
    for(int i = 0; i<m; i++){
        cin >> apartments[i];
    }

    sort(apartments.begin(), apartments.end());
    sort(applicants.begin(), applicants.end());

    int i = 0, j = 0;
    int assign = 0;
    while(i < n){
        while(j < m && apartments[j] < applicants[i] - k){
            j++;
        }
        // applicant does not meet his requirements.
        if(abs(apartments[j] - applicants[i]) <= k){
            i++;
            j++;
            assign += 1;
        }else{
            i++;
        }
    }
    cout << assign;
    return 0;


}