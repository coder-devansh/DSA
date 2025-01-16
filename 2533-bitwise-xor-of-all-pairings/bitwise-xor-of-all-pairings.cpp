class Solution {
public:
int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
    int result1=0;
    int result=0;
   map<int,int>mp;
   for(int i=0;i<nums1.size();i++){
      mp[nums1[i]]+=nums2.size();
   }
   for(int i=0;i<nums2.size();i++){
    mp[nums2[i]]+=nums1.size();
   }
   int ans=0;
   for(auto it:mp){
    if(it.second % 2!=0){
        ans =ans ^ it.first;
    }
   }
   return ans;

    //      for(int i=0;i<nums2.size();i++){
    //     result1=result1 ^ nums2[i];-
    //    }
    //    for(int i=0;i<nums1.size();i++){
    //     int value=result1 ^ nums1[i];
    //     result=result ^ value;
    //    }
    //     return result;
        
    }
};