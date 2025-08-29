class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      
       map<string,vector<string>>mp;
       for(string str:strs){
        string copy=str;
        sort(copy.begin(),copy.end());
        if(mp.find(copy)!=mp.end()){
            mp[copy].push_back(str);
        }else{
            mp[copy].push_back(str);
        }
       }
     
       vector<vector<string>>result;
       for(auto it:mp){
      vector<string>temp;
      for(auto str:it.second){
        temp.push_back(str);
      }
      result.push_back(temp);

       }
       return result;
       
        
    }
};