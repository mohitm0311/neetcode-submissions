class Solution {
public:
    vector<int> previous_smallest_element(vector<int> &heights){
        int n = heights.size();
        vector<int> pse(n);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                pse[i] = -1;
            }
            else{
                pse[i] = st.top();
            }
            st.push(i);
        }
        return pse;
    }
    vector<int> next_smallest_element(vector<int> &heights){
        int n = heights.size();
        stack<int> st;
        vector<int> nse(n);
        for(int i=n-1; i>=0; i--){
            while(!st.empty()&& heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                nse[i] = n;
            }
            else{
                nse[i] = st.top();
            }
            st.push(i);
        }
        return nse;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> pse = previous_smallest_element(heights);
        vector<int> nse = next_smallest_element(heights);
        int maxi = 0;
        for(int i=0; i<heights.size(); i++){
            int h = heights[i];
            int len = nse[i] - pse[i]-1;
            int area = h*len;
            maxi = max(area, maxi);
        }
        return maxi;
    }
};
