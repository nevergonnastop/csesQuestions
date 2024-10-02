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
bool comp(const pair<int,int>& a, const pair<int,int>& b){
    return a.second < b.second;
}
int main(){
    init_code();
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> movies(n);
    for(int i= 0; i < n; i++){
        int start, end;
        cin >> start >> end;
        movies[i] = {start,end};
    }
    sort(movies.begin(),movies.end(), comp);
    set<pair<int,int>> availableClient;
    int count = 0; // bad movies count(not able to watch)
    for(int i = 0; i<n; i++){
        if(availableClient.size() == 0){
            availableClient.insert({movies[i].second*-1, i});
        }else{
            // check if earlier guys are free
            auto it = availableClient.lower_bound({movies[i].first*-1, -1});
            if(it != availableClient.end()){
                availableClient.erase(it);
                availableClient.insert({movies[i].second*-1, i});
            }else if(it == availableClient.end() && availableClient.size() < k){
                availableClient.insert({movies[i].second*-1, i});
            }else{
                count++;
            }
        }
    }
    cout << n - count << endl;
    return 0;
}