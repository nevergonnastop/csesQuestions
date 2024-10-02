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

struct TrieNode{
    struct TrieNode* child[26];
    bool isEnd;
    TrieNode(){
        isEnd = false;
        for(int i = 0; i<26; i++){
            child[i] = NULL;
        }
    }
};
TrieNode* root;
bool searchString(string st){
    TrieNode* curr = root;
    ll n = st.length();
    for(int i = 0; i<n; i++){
        int idx = st[i] - 'a';
        if(curr->child[idx] == NULL){
            return false;
        }
        curr = curr->child[idx];
    }
    return curr->isEnd;
}
void insertString(string st){
    TrieNode* curr = root;
    ll n = st.length();
    for(int i = 0; i<n; i++){
        int idx = st[i] - 'a';
        if(curr->child[idx] == NULL){
            curr->child[idx] = new TrieNode();
        }
        curr = curr->child[idx];
    }
    curr->isEnd = true;
}
int main(){
    init_code();
    string str;
    int k;
    cin >> str;
    cin >> k;

    root = new TrieNode();

    for(int i = 0; i<k; i++){
        string st;
        cin >> st;
        insertString(st);
    }
    ll len = str.length();
    vector<int> dp(len+1);
 
    //Ways to make complete string from i to n
    dp[len] = 1;
 
    //So the main logic is 
    //If you know that str[i..j1] exists in the dictionary
    //Then number of ways to complete string from i to n can be 
    //dp[i] = dp[i] + dp[j1 + 1];
 
    //If you checked and now again str[i..j2] where j2>j1 exists in the 
    //dictionary.
    //The again add this to dp
    //dp[i] = dp[i] + dp[j2 + 1];
 
    //dp[len] will be 1
    //Suppose you figured str[i..(len-1)] is in the dictionary
    //Then dp[i] = dp[i] + d[len];
    //So dp[len] is base case with value = 1
 
    //Final answer will be dp[0]
    for(int i = len-1; i >= 0; i--){
        TrieNode *test = root;
        for(int j = i; j < len; j++){
            ll idx = str[j] - 'a';
            if(test->child[idx] == NULL){
                break;
            }
            test = test->child[idx];
            if(test->isEnd){
                dp[i] = dp[i]%mod + dp[j + 1]%mod;
                dp[i] = dp[i]%mod;
            }
        }
    }
    cout << dp[0] << endl;
}