class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>prefix(A.size(),0);
        map<int,int>mp;
        int ans=0;
       for(int i=0;i<A.size();i++){
       if(A[i]==B[i])
       {
        mp[A[i]]=2;
        if(mp[A[i]]==2){
            ans++;
        }
       }else{
        mp[A[i]]++;
        mp[B[i]]++;
        if(mp[A[i]]==2){
            ans++;
        }
        if(mp[B[i]]==2){
            ans++;
        }
       }
        
        prefix[i]=ans;
        
        
       }
      
       return prefix;
    }
};