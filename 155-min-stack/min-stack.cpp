class MinStack {
public:
map<int,int>mp;
stack<int>st;
    MinStack() {
       

        
        
    }
    
    void push(int val) {
        mp[val]++;
        st.push(val);
            
    }
    
    void pop() {
      mp[st.top()]--;
      if(mp[st.top()]==0){
        mp.erase(st.top());
      }
            st.pop();
        

        
    }
    
    int top() {
        return st.top();
        
    }
    
    int getMin() {
        for(auto it:mp){
            return it.first;
        }
        return -1;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */