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
    int solve(TreeNode* root, int &max_dia){
        if(root == nullptr) return 0;
        int left_max = solve(root->left, max_dia);
        int right_max = solve(root->right, max_dia);
        max_dia = max(max_dia, left_max+right_max);
        return 1 + max(left_max, right_max);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int max_dia = 0;
        int k = solve(root, max_dia);
        return max_dia;
    }
};
