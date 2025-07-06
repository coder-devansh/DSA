class FindSumPairs {
public:
vector<int>temp1;
vector<int>temp2;
map<long long ,long long >mp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        temp1=nums1;
        temp2=nums2;
        for(auto it:temp2){
            mp[it]++;
        }
        
        
    }
    
    void add(int index, int val) {
        int val1=temp2[index];
        mp[val1]--;
        temp2[index]+=val;
        val1=temp2[index];
        mp[val1]++;
        
    }
    
    int count(int tot) {
        int count1=0;
        for(auto it:temp1){
            int val=tot-it;
            count1+=mp[val];
        }
        return count1;
      
        
       

        
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */