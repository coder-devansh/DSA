class NumArray {
public:
vector<int>segmentTree;
void buildSegmentTree(int i,int l,int r,vector<int>&nums){
    if(l==r)
    {
        segmentTree[i]=nums[l];
        return;
    }
    int mid=l+(r-l)/2;
    buildSegmentTree(2*i+1,l,mid,nums);
    buildSegmentTree(2*i+2,mid+1,r,nums);
    segmentTree[i]=segmentTree[2*i+1]+segmentTree[2*i+2];
}
void updateSegmentTree(int i,int l,int r,int index,int val){
    if(l==r){
        segmentTree[i]=val;
        return;
    }
    int mid=l+(r-l)/2;
    if(mid>=index){
        updateSegmentTree(2*i+1,l,mid,index,val);
    }else{
        updateSegmentTree(2*i+2,mid+1,r,index,val);
    }
    segmentTree[i]=segmentTree[2*i+1]+segmentTree[2*i+2];
}
long long  findSum(int i,int left,int right,int l,int r){
    if(right<l || left>r)return 0;
    if(left<=l && r<=right)return segmentTree[i];
    int mid=l+(r-l)/2;
    long long  left_sum=findSum(2*i+1,left,right,l,mid);
    long long  right_sum=findSum(2*i+2,left,right,mid+1,r);
    return left_sum+right_sum;

}
    NumArray(vector<int>& nums) {
        int n=nums.size();
        segmentTree.resize(4*n,0);
        buildSegmentTree(0,0,n-1,nums);


        
    }
    
    void update(int index, int val) {
        int size=segmentTree.size()/4;
        updateSegmentTree(0,0,size-1,index,val);
    }
    
    int sumRange(int left, int right) {
        int n=segmentTree.size()/4;
        return findSum(0,left,right,0,n-1);
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */