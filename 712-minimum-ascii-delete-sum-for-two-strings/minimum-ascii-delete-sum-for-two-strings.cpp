class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,0));
        for(int i=1;i<=s1.size();i++){
            dp[i][0]=dp[i-1][0]+(int)s1[i-1];
        }
        for(int j=1;j<=s2.size();j++){
            dp[0][j]=dp[0][j-1]+(int)s2[j-1];
        }
        for(int i=1;i<=s1.size();i++){
            for(int j=1;j<=s2.size();j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1];

                }else{
                    dp[i][j]=min(dp[i-1][j]+(int)s1[i-1],dp[i][j-1]+(int)s2[j-1]);
                }
                
            }
        }
        return dp[s1.size()][s2.size()];
    //     int i=s1.size();
    //     int j=s2.size();
    //     string ans="";
    //     while(i>0 && j>0){
    //         if(s1[i-1]==s2[j-1])
    //         {
    //             ans+=s1[i-1];
    //             i--;
    //             j--;
    //         }
    //         else if(dp[i-1][j]==dp[i][j-1])
    //         {
    //             if((int)s1[i-1]>(int)s2[j-1])
    //             {
    //                 j--;
    //             }else{
    //                 i--;
    //             }
    //         }
    //         else if(dp[i-1][j]>dp[i][j-1])
    //         {
    //             i--;
    //         }else{
    //             j--;
    //         }

    //     }
    //    map<char,int>mp;
    //    for(int i=0;i<ans.size();i++){
    //     mp[ans[i]]++;
    //    }
    //    map<char,int>hel;
    //    hel=mp;
    //    int result=0;
    //    cout<<ans<<endl;
    //    for(int i=0;i<s1.size();i++){
    //     if(mp.find(s1[i])!=mp.end()){
    //         mp[s1[i]]--;
    //         if(mp[s1[i]]==0){
    //             mp.erase(s1[i]);
    //         }
           
    //     }
    //      else{
    //           cout<<(int)s1[i]<<" "<<s1[i]<<endl;
    //             result+=(int)s1[i];
    //         }
    //    }
    //    mp=hel;
    //    for(int i=0;i<s2.size();i++){
    //     if(mp.find(s2[i])!=mp.end()){
    //         mp[s2[i]]--;
    //         if(mp[s2[i]]==0){
    //             mp.erase(s2[i]);
    //         }
            
    //     }
    //     else{
    //         cout<<(int)s2[i]<<' '<<s2[i]<<endl;
    //             result+=(int)s2[i];
    //         }
    //    }
    //     return result;
        
    }
};