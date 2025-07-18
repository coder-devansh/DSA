class Solution {
public:
bool createGroup(int num,int count,map<int,int>&mp,int k){
    int start_val=num;
    mp[start_val]--;
    int next_val=num+1;
    for(int i=1;i<k;i++){
        if(mp[next_val]>0){
            mp[next_val]--;
        }else{
            return false;
        }
        next_val++;
    }
    return true;
}
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto it:mp){
            int val=it.second;
            while(val>0){
                if(!createGroup(it.first,it.second,mp,k))return false;
                val--;
            }
        }
        return true;


        
    }
};