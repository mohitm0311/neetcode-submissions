class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int max_len = 0;
        int len = 0;
        for(auto num: nums){
            if(st.find(num-1)==st.end()){
                len = 1;
                int curr = num;
                while(st.find(curr+1)!=st.end()){
                    len++;
                    curr++;
                }
            }
            max_len = max(max_len, len);
        }
        return max_len;
    }
};
