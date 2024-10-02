//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    struct minCmp{
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
            return a.second < b.second;
        }
    };
    struct maxCmp{
        bool operator()(const pair<int,int> &a, const pair<int,int>& b) const{
            return a.second > b.second;
        }
    };
    priority_queue<pair<int,int>, vector<pair<int,int>>, minCmp> maxQ;
    priority_queue<pair<int,int>, vector<pair<int,int>>, maxCmp> minQ;
    
    
    void createMinQAMaxQ(int amount[], int n){
        for(int i = 0; i<n; i++){
            if(amount[i] == 0){
                continue;
            }else if(amount[i] < 0){
                minQ.push({i, amount[i]});
            }else{
                maxQ.push({i, amount[i]});
            }
        }
    }
    vector<vector<int>> solveTransaction(int amount[], int n){
        // Defind transaction array.
        vector<vector<int>> transactions(n, vector<int>(n, 0));
        while(!minQ.empty() && !maxQ.empty()){
            pair<int,int> debtPerson = minQ.top(); minQ.pop();
            pair<int,int> creditPerson = maxQ.top(); maxQ.pop();
            
            int transaction_val = creditPerson.second
                                  + debtPerson.second;

            int debtor = debtPerson.first,
                creditor = creditPerson.first,
                owed_amount = 0;
            if(transaction_val == 0){
                owed_amount = creditPerson.second;
            }else if(transaction_val < 0){
                owed_amount = creditPerson.second;
                minQ.push({debtor , transaction_val});
            }else{
                owed_amount = -(debtPerson.second);
                maxQ.push({creditor, transaction_val});
            }
            transactions[debtor][creditor] = owed_amount;
        }
        return transactions;
    }
    vector<vector<int>> minCashFlow(vector<vector<int>> &transaction, int n) {
        // code here
        int amount[n] = {0};
        for(int p = 0; p<n; p++){
            for(int i = 0; i<n; i++){
                // p will give money to i;
                amount[p] += (transaction[i][p] - transaction[p][i]);
            }
        }
        
        // CReate min and maxQ for retrival of negative and positive value
        createMinQAMaxQ(amount, n);
        
        // solve Transaction function
        return solveTransaction(amount, n);
    }
};


//{ Driver Code Starts.

vector<int> balance(vector<vector<int>>& v, int n) {
    vector<int> bal(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bal[i] -= v[i][j];
            bal[j] += v[i][j];
        }
    }
    return bal;
}

bool isValid(vector<vector<int>>& g, vector<vector<int>>& r, int n) {
    return balance(g, n) == balance(r, n);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> g(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cin >> g[i][j];
        }
        Solution obj;
        vector<vector<int>> r = obj.minCashFlow(g, n);
        if (isValid(g, r, n) == false) {
            cout << "-1\n";
            continue;
        }
        int flow = 0;
        for (auto j : r) {
            for (auto i : j) {
                if (i > 0)
                    flow++;
            }
        }
        cout << flow << "\n";
    }
    return 0;
}
// } Driver Code Ends