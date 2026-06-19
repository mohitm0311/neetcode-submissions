
class Solution {
public:
    int solve(TreeNode* root, int& max_sum) {
        if (root == nullptr)
            return 0;
        int left_max = max(0, solve(root->left, max_sum));
        int right_max = max(0, solve(root->right, max_sum));
        max_sum = max(max_sum, root->val + left_max + right_max);
        return root->val + max(left_max, right_max);
    }
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        solve(root, max_sum);
        return max_sum;
    }
};