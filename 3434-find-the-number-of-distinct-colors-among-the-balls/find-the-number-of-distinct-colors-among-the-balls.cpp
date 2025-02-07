class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
       map<long long ,int>color;
       map<long long ,int>mp;
       vector<int >ans;
       for(auto it:queries){
        if(color.find(it[0])==color.end() || color[it[0]]!=it[1]){
              if(mp.find(color[it[0]])!=mp.end()){
               mp[color[it[0]]]--;
               if(mp[color[it[0]]]==0){
                        mp.erase(color[it[0]]);
               }
              }
               
                color[it[0]]=it[1];
               
                mp[it[1]]++;
                
                
        }
        
       
        ans.push_back(mp.size());
        

       }
      
       return ans;
        
    }
};