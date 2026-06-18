class Solution {
public:
    bool solve(vector<int> &piles, int cap, int h){
        int count_hr = 0;
        for(int i=0; i<piles.size(); i++){
            count_hr+= (piles[i]+cap-1)/cap;
        }
        if(count_hr<=h) return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = INT_MIN;
        for(auto it: piles){
            high = max(high, it);
        }
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(solve(piles, mid, h)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};
