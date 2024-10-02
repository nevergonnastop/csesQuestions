#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
// #define int long long
#define fast_io ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define mod 1000000007
typedef long long ll;
const int MOD = 1e9 + 7;
void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
void kmpPreprocess(int reset[], string pat){
    int i = 0,j = -1;
    reset[0] = -1;
    int plen = pat.length();
    while(i < plen) {
        while(j >= 0 && pat[i] != pat[j]) {
            j = reset[j];
        }
        i++; j++;
        reset[i] = j;
    }
}
int main(){
    init_code();
    string haystack,needle;
    cin >> haystack >> needle;
    int h = haystack.length();
    int n = needle.length();
    
    if(n == 0){
        return 0;
    }
    int lps[n+1];
    kmpPreprocess(lps, needle);
    
    int i = 0;
    int j = 0;
    int count = 0;
    while(i < h){
        while(j >= 0 && haystack[i] != needle[j]){
            j = lps[j];
        }
        i++;j++;
        if(j == n) {
            count++;
        }
    }
    cout << count << endl;
    return 0;

}   