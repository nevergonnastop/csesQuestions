#include <bits/stdc++.h> 
using namespace std;

template <typename T>
class TreeNode {
   public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

// `solve` returns a pair of (distance, count)
pair<int, int> solve(TreeNode<int> *node, int node1, int node2) {
    if(node == NULL){
        return {-1, 0};
    }
    auto leftAns = solve(node->left, node1, node2);
    auto rightAns = solve(node->right, node1, node2);
    int cnt = 0;
    if(node->val == node1 || node->val == node2){
        cnt += 1;
    }
    if(leftAns.first != -1 && rightAns.first != -1){
        return {2 + leftAns.first + rightAns.first, leftAns.second + rightAns.second};
    }
    if(leftAns.first != -1){
        return {1 + leftAns.first, cnt + leftAns.second};
    }
    if(rightAns.first != -1){
        return {1 + rightAns.first, cnt + rightAns.second};
    }

    if(cnt > 0){
        return {0, cnt};
    }
    return {-1, 0};

}

int findDistanceBetweenNodes(TreeNode<int> *root, int node1, int node2) {
    //
    if(root->left == NULL && root->right == NULL){
        if(node1 == node2){
            return 0;
        }else{
            return -1;
        }
    }

    pair<int, int> ans = solve(root, node1, node2);
    cout << ans.first << "--" << ans.second << endl;

    if (ans.second < 2) {
        return -1;
    }
    return ans.first;
}

TreeNode<int>* buildTree(const vector<int>& values) {
    if (values.empty() || values[0] == -1) {
        return NULL;
    }
    
    TreeNode<int>* root = new TreeNode<int>(values[0]);
    queue<TreeNode<int>*> q;
    q.push(root);
    
    int index = 1;
    while (index < values.size()) {
        TreeNode<int>* current = q.front();
        q.pop();
        
        // Left child
        if (values[index] != -1) {
            current->left = new TreeNode<int>(values[index]);
            q.push(current->left);
        }
        index++;
        
        // Right child
        if (index < values.size() && values[index] != -1) {
            current->right = new TreeNode<int>(values[index]);
            q.push(current->right);
        }
        index++;
    }
    
    return root;
}

int main(){

    vector<int> values = {5, 6, 2, 4, 3, -1, -1, 9, 7, -1, -1, -1, -1, -1, -1};

    int node1 = 5;
    int node2 = 9;
    
    // Build the binary tree
    TreeNode<int>* root = buildTree(values);

    int distance = findDistanceBetweenNodes(root, node1, node2);
    cout<< distance << endl;
    return 0;
}