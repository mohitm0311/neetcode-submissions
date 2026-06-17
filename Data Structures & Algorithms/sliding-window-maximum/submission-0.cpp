class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> ms;
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ms.insert(nums[i]);
        }
        ans.push_back(*ms.rbegin());
        for (int i = k; i < n; i++) {
            auto it = ms.find(nums[i - k]);
            ms.erase(it);
            ms.insert(nums[i]);
            ans.push_back(*ms.rbegin());
        }
        return ans;
    }
};