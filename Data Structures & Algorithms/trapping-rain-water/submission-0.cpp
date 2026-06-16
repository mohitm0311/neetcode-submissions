class Solution {
public:
    int trap(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;
        vector<int> left_max(n);
        vector<int> right_max(n);
        left_max[0] = 0;
        int maxi = heights[0];
        for (int i = 1; i < n; i++) {
            left_max[i] = maxi;
            maxi = max(maxi, heights[i]);
        }
        right_max[n - 1] = 0;
        int maxi_ = heights[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right_max[i] = maxi_;
            maxi_ = max(maxi_, heights[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int waterLevel = min(left_max[i], right_max[i]);
            if (waterLevel > heights[i]) {
                ans += waterLevel - heights[i];
            }
        }
        return ans;
    }
};