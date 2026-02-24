class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>outdegree(n,0);
        map<int,set<int>>mp;
        for(auto it:roads){
            outdegree[it[0]]++;
            outdegree[it[1]]++;
            mp[it[0]].insert(it[1]);
            mp[it[1]].insert(it[0]);
        }
        for(auto it:outdegree)cout<<it<<" ";
        cout<<endl;
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(mp[i].find(j)!=mp[i].end()){
                    maxi=max(maxi,outdegree[i]+outdegree[j]-1);
                }else{
                    maxi=max(maxi,outdegree[i]+outdegree[j]);
                }
            }
        }
        return maxi;


        
        
    }
};