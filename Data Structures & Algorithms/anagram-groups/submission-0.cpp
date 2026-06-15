class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<int>> mp;
        int n = strs.size();
        for(int i=0; i<n; i++){
            vector<int> hash(26,0);
            for(int j=0; j<strs[i].size(); j++){
                hash[strs[i][j]-'a']++;
            }
            mp[hash].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto it: mp){
            vector<string> arr;
            for(auto itt: it.second){
                arr.push_back(strs[itt]);
            }
            ans.push_back(arr);
        }
        return ans;
    }
};
