/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private: 
    bool leaf(TreeNode* &root){
        return (root->left == nullptr && root->right == nullptr); 
    }
    int dfs(TreeNode* &root, map<TreeNode*, int> &dp){
        // base case
        if(root == nullptr) return 0; 
        if(leaf(root)) return root->val; 
        if(dp.count(root)) return dp[root]; 
        int notTakeLeft = 0 + dfs(root->left, dp); 
        int takeLeft = 0; 
        if(root->left != nullptr) takeLeft = dfs(root->left->left, dp) + dfs(root->left->right, dp); 
        int notTakeRight = 0 + dfs(root->right, dp); 
        int takeRight = 0; 
        if(root->right != nullptr) takeRight = dfs(root->right->right, dp) + dfs(root->right->left, dp); 
        int take = root->val + takeLeft + takeRight; 
        int notTake = notTakeLeft + notTakeRight; 
        // return (max(notTakeLeft, takeLeft) + max(notTakeRight, takeRight)); 
        return dp[root] = max(take, notTake);   
    }
public:
    int rob(TreeNode* root) {
        // bool mark = true; 
        map<TreeNode*, int> dp; 
        return dfs(root, dp); 
    }
};
