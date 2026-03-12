#define ll long long
class Solution {
public:
vector<ll>bit;
void update(ll i){
    for(;i<bit.size();i+=(i&(-i)))bit[i]++;
}
ll search(ll i){
    ll ans=0;
    for(;i>0;i-=(i&(-i)))ans+=bit[i];
    return ans;
}
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        set<ll>st;
        for(int i=0;i<nums1.size();i++){
            st.insert(nums1[i]-nums2[i]);
            st.insert(nums1[i]-nums2[i]+diff);
        }
        map<ll,int>mp;
        int i=1;
        for(auto it:st){
            mp[it]=i;
            i++;
        }
        bit.resize(st.size()+1,0);
        ll ans=0;
        for(int i=0;i<nums1.size();i++){
            ans+=search(mp[nums1[i]-nums2[i]+diff]);
            update(mp[nums1[i]-nums2[i]]);
        }
        return ans;


        
    }
};