#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
typedef long long ll;

struct project{
    int start,end,value;
    bool operator<(const project &other)const{
        return end < other.end; // Ascending order
    }
};

int main(){
    init_code();
    int n;cin >> n;
    vector<project> projects(n);
    for(int i = 0; i<n;i++){
        int a,b,c;cin >> a>>b>>c;
        projects[i]= {a,b,c};
    }
    sort(projects.begin(), projects.end());
    // ordered set
    set<pair<int, ll>> ends;
    ends.insert({0,0});
    ll answer = 0;
    for(int i = 0; i<n; i++){
        // Higher and Equal.
        auto t = ends.lower_bound({projects[i].start,-1});
        t--;
        answer = max(answer, projects[i].value + t->second);
        ends.insert({projects[i].end, answer});
    }
    cout << answer << endl;
}