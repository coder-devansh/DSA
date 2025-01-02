class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int i=0;
        int count=0;
        vector<int>prefix(words.size(),0);
        for(auto it:words){
          if((it[0]=='a' || it[0]=='e'|| it[0]=='i'||it[0]=='o'|| it[0]=='u') && (it[it.size()-1]=='a' || it[it.size()-1]=='e'|| it[it.size()-1]=='i'||it[it.size()-1]=='o'|| it[it.size()-1]=='u' )){
            count++;
          }
          cout<<count;
          if(i<words.size()){
            prefix[i]=count;
          }
          i++;

        }
        vector<int>ans;
        for(auto it:queries){
            if(it[0]==0){
                 ans.push_back(prefix[it[1]]-0);

            }else{
                 ans.push_back(prefix[it[1]]-prefix[it[0]-1]);

            }
           
            
           

        }
        return ans;
        
    }
};