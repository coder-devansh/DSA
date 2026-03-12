#define ll long long
class Solution {
public:
vector<int>bit;
void update(int i){
    for(;i<bit.size();i+=(i&(-i)))bit[i]++;
}
ll search(int i){
    ll ans=0;
    for(;i>0;i-=(i&(-i)))ans+=bit[i];
    return ans;
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
       int i=1;
       for(auto it:st){
        mp[it]=i;
        i++;
       }
       bit.resize(st.size()+2,0);
       update(mp[0]);
      
       for(int i=1;i<prefix.size();i++){
        int l=mp[prefix[i]-upper];
        int r=mp[prefix[i]-lower];
        if(l==0){
            ans+=search(r);
        }else{
             ans+=(search(r)-search(l-1));

        }
       
        update(mp[prefix[i]]);

       }
       return ans;


        
        
    }
};