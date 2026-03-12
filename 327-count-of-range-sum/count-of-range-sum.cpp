#define ll long long
class Solution {
public:
void update(int ind,int low,int high,int poss,int seg[]){
    if(low==high){
        seg[ind]++;
        return;
    }
    int mid=(low+high)/2;
    if(mid>=poss){
        update(2*ind+1,low,mid,poss,seg);
    }else{
        update(2*ind+2,mid+1,high,poss,seg);
    }
    seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}
ll find(int ind,ll low,int high,ll l,ll r,int seg[]){
    if(low>=l && high<=r)return seg[ind];
    if(l>high || low>r)return 0;
    int mid=(low+high)/2;
   ll left=find(2*ind+1,low,mid,l,r,seg);
    ll right=find(2*ind+2,mid+1,high,l,r,seg);
    return left+right;
}
    ll countRangeSum(vector<int>& nums, int lower, int upper) {
       set<ll>st;
       vector<ll>prefix(nums.size()+1,0);
       map<ll,int>mp;
       ll ans=0;
       prefix[0]=0;
       
       st.insert(nums[0]);
       st.insert(0);
       st.insert(0-lower);
       st.insert(0-upper);
       for(int i=1;i<=nums.size();i++)
       {
        prefix[i]=prefix[i-1]+nums[i-1];
          st.insert(prefix[i]);
       st.insert(prefix[i]-upper);
       st.insert(prefix[i]-lower);
       }
       int i=0;
       for(auto it:st){
        mp[it]=i;
        i++;
       }
       int seg[4*st.size()];
       for(int i=0;i<4*st.size();i++)seg[i]=0;
       update(0,0,st.size()-1,mp[prefix[0]],seg);
       for(int i=1;i<prefix.size();i++){
        int l=mp[prefix[i]-upper];
        int r=mp[prefix[i]-lower];
        ans+=find(0,0,st.size()-1,l,r,seg);
        update(0,0,st.size()-1,mp[prefix[i]],seg);
       }
       return ans;


        
        
    }
};