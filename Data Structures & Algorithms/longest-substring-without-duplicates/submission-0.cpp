class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        unordered_map<char,int> mp;
        int max_len= 0;
        int len = 0;
        int n = s.size();
        while(left<=right && right<n){
            mp[s[right]]++;
            while(left<=right && mp.size()<(right - left+1)){
                mp[s[left]]--;
                if(mp[s[left]]==0){
                    mp.erase(s[left]);
                }
                left++;
            }
            len = right - left + 1;
            max_len = max(max_len, len);
            right++;
        }
        return max_len;
    }
};
