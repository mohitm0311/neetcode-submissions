class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<int> freq(26,0);
        vector<int> freq1(26,0);
        for(auto c: s1){
            freq[c-'a']+=1;
        }
        if(n>m) return false;
        for(int i=0; i<n; i++){
            freq1[s2[i]-'a']+=1;
        }
        if(freq == freq1) return true;
        for(int i = n; i<m; i++){
            freq1[s2[i]-'a']+=1;
            freq1[s2[i-n]-'a']-=1;
            if(freq1== freq) return true;
        }
        return false;
    }
};
