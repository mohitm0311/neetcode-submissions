class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        int n = nums.size();
        for(int i=0; i<n-1; i++){
            int new_tar = - nums[i];
            int left = i+1;
            int right = n-1;
            while(left<right){
                int sum = nums[left] + nums[right];
                if(sum == new_tar){
                    vector<int> arr ={nums[i], nums[left], nums[right]};
                    st.insert(arr);
                    left++;
                }
                else if(sum<new_tar){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return vector<vector<int>>(st.begin(), st.end());
    }
};
