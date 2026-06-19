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
public:
    int solve(TreeNode* root){
        if(root == nullptr) return 0;
        int left_max = solve(root->left);
        int right_max = solve(root->right);
        if(left_max == -1 || right_max == -1) return -1;
        if(abs(left_max-right_max)>1) return -1;
        return 1 + max(left_max, right_max);
        
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        int ans = solve(root);
        if(ans == -1) return false;
        return true;
    }
};
