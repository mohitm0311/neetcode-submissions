class MinStack {
    stack<pair<long long,long long>> st;
public:
    MinStack() {}
    
    void push(int val) {
        if(st.empty()){
            st.push({val,val});
        }
        else{
            int min = st.top().second;
            if(val<min){
                st.push({val,val});
            }
            else{
                st.push({val, min});
            }
        }
    }
    void pop() {
        st.pop();   
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
