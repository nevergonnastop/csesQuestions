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
string transform(string st){
    string temp;
    temp += "#";
    for(char ch : st){
        temp += ch;
        temp += "#";
    }
    return temp;
}
int main(){
    init_code();
    string str;
    cin >> str;
    int n = str.length();
    int s;
    // O(N) Mancher 'a ALgo'
    string t = transform(str);
    n = t.length();
    int l = 0;
    int r = 0;
    int center = 0;
    int maxLen = 0;
    vector<int>p(n);
    p[0] = 0;
    for(int i =  1; i< n; i++){
        int k;
        if(i > r){
            k = 0;
        }else{
            // j will be the mirror of i
            int j = (r - i) + l;
            if(j - p[j] > l){
                p[i] = p[j];
                continue;
            }else{
                // now you can expand as usual but from k = r -i;
                k = r - i;
            }
        }
        while(i -k >= 0 && i + k < n && t[i-k] == t[i+k]){
            k++;
        }
        k--;
        p[i] = k;
        if(p[i] > maxLen){
            maxLen = p[i];
            center = i / 2;
        }
        if(i + k > r){
            l = i - k;
            r = i + k;
        }

    }
    cout << str.substr(center - (maxLen/2), maxLen);













    // O(N2)
    // for(int i = 0;i <n; i++){
    //     int k = 0;
    //     while(i -k >= 0 && i +k < n && str[i - k] == str[i + k]){
    //         k++;
    //     }
    //     k--;
    //     if((i + k) - (i -k) + 1 > maxLen){
    //         s = i -k;
    //         maxLen = (i + k) - (i -k) + 1;
    //     }
    // }
    // // for even length palindromes
    // // iterate over even centers
    // for(double  i = 0.5; i<n; i++){
    //     double k = 0.5;
    //     while(i -k >= 0 && i + k < n && str[int(i-k)] == str[int(i+k)]){
    //         k++;
    //     }
    //     k--;
    //     if((i+k) -(i-k) + 1 > maxLen){
    //         s = i - k;
    //         maxLen = (i + k) - (i - k) + 1;
    //     }
    // }
    // cout << str.substr(s, maxLen);
    return 0;
}