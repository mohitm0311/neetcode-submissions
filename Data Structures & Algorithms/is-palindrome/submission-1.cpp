class Solution {
public:
    bool isPalindrome(string s) {
        int right = s.size() - 1;
        for (int i = 0; i <= right; i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = s[i] - 'A' + 'a';
            }
        }
        string ans = "";
        for (int i = 0; i <= right; i++) {
            if ((s[i] >= 'a' && s[i] <= 'z') ||
                (s[i] >= '0' && s[i] <= '9')) {
                ans.push_back(s[i]);
            }
        }
        int left = 0;
        right = ans.size() - 1;
        while (left < right) {
            if (ans[left] != ans[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};