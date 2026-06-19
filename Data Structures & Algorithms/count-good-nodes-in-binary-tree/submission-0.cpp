class Solution {
public:
    void solve(TreeNode* root, int maxi, int& count) {
        if (root == nullptr) return;
        if (root->val >= maxi) {
            count++;
            maxi = root->val;
        }
        solve(root->left, maxi, count);
        solve(root->right, maxi, count);
    }
    int goodNodes(TreeNode* root) {
        int count = 0;
        solve(root, INT_MIN, count);
        return count;
    }
};