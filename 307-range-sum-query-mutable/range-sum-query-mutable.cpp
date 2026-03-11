class NumArray {
public:
   vector<int>bit;
   vector<int>nums;
   int N;
    NumArray(vector<int>& arr) {
        N=arr.size();
        nums=arr;
        bit.resize(nums.size()+1,0);
        for(int i=0;i<nums.size();i++){
           add(i+1,nums[i]);
        }
        
    }
    void add(int i,int diff){
        for(;i<=N;i+=(i & (-i)))bit[i]+=diff;
        
    }
    
    void update(int i, int val) {
        int diff=val-nums[i];
        nums[i]=val;
        add(i+1,diff);
        
    }
    int sum(int i){
        int ans=0;
        for(;i>0;i-=(i & (-i))){
            ans+=bit[i];
        }
        return ans;

    }
    
    int sumRange(int left, int right) {
       
        return sum(right+1)-sum(left);

        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */