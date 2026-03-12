#define ll long long
class Solution {
public:
void update(int ind,int low,int high,int pos,ll seg[]){
    if(low==high){
        seg[ind]++;
        return;
    }
    int mid=(low+high)/2;
    if(pos<=mid){
        update(2*ind+1,low,mid,pos,seg);
    }else{
        update(2*ind+2,mid+1,high,pos,seg);

    }
    seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}
int find_sum(int ind,int low,int high,int l,int r,ll seg[])
{
    if(low>=l && high<=r)return seg[ind];
    if(l>high || low>r){
        return 0;
    }
    int mid=(low+high)/2;
    ll left=find_sum(2*ind+1,low,mid,l,r,seg);
    ll right=find_sum(2*ind+2,mid+1,high,l,r,seg);
    return left+right;
}
    vector<int> countSmaller(vector<int>& nums) {
        set<int>st;
        for(auto it:nums)st.insert(it);
        vector<int>arr;
        unordered_map<int,int>mp;
        int i=0;
        for(auto it:st){
            mp[it]=i;
            i++;
        }
        vector<int>ans;
        ll seg[4*nums.size()];
        for(int i=0;i<4*nums.size();i++)seg[i]=0;
        for(int i=nums.size()-1;i>=0;i--){
            ans.push_back(find_sum(0,0,nums.size()-1,0,mp[nums[i]]-1,seg));
            update(0,0,nums.size()-1,mp[nums[i]],seg);

        }
        reverse(ans.begin(),ans.end());
        return ans;
        

        
        

        
    }
};