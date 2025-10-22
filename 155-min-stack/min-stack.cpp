class MinStack {
public:
map<int,int>mp;
stack<int>st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        mp[val]++;
        
    }
    
    void pop() {
        int ele=st.top();
        st.pop();
        mp[ele]--;
        if(mp[ele]==0)mp.erase(ele);
        
    }
    
    int top() {
        if(st.empty())return -1;
        return st.top();
    }
    
    int getMin() {
       for(auto it:mp)return it.first;
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