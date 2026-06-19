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
    bool LCA(TreeNode* root, TreeNode* p, vector<TreeNode*> &arr){
        if(root == nullptr) return false;
        arr.push_back(root);
        if(root == p) return true;
        if(LCA(root->left, p,arr)|| LCA(root->right,p, arr)){
            return true;
        }
        arr.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> arr1, arr2;
        bool l = LCA(root, p,arr1);
        bool k = LCA(root, q, arr2);
        TreeNode* ans = root;
        for(int i=0; i<min(arr1.size(), arr2.size()); i++){
            if(arr1[i] == arr2[i]){
                ans = arr1[i];
            }
        }
        return ans;
    }
};
