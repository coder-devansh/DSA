class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        map<char,int>mp;
        for(auto it:words2){
            map<char,int>temp;
           string ans=it;
          for(int i=0;i<ans.size();i++){
            temp[ans[i]]++;
           if(mp.find(ans[i])==mp.end()){
            mp[ans[i]]++;
           }
           if(mp[ans[i]]<temp[ans[i]])
           {
            mp[ans[i]]=temp[ans[i]];
           }

            
        }
    }
    vector<string>answer;
    for(int i=0;i<words1.size();i++){
            map<char,int>element;
            string ans=words1[i];
            for(int j=0;j<ans.size();j++){
              
                if(mp.find(ans[j])!=mp.end() && mp[ans[j]]>element[ans[j]]){
                    element[ans[j]]++;
                }
                 }
            if(mp==element){
                answer.push_back(ans);
            }
        }
        return answer;
        
    
        
    }
};