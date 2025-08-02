class Solution {
public:
static bool custom(vector<int>a,vector<int>b){
    return a[2]<b[2];
}
    bool carPooling(vector<vector<int>>& trips, int capacity) {
      vector<int>prefix(1001,0);
      int maxValue=0;
      for(auto it:trips){
        prefix[it[1]]+=it[0];
        prefix[it[2]]-=it[0];
        maxValue=max(maxValue,max(it[1],it[2]));
      }
      int ans=0;
      for(int i=0;i<=maxValue;i++){
        ans+=prefix[i];
        if(ans>capacity)return false;
        
      }
      return true;
        
        
    }
};