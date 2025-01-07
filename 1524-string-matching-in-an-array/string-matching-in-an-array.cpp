class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string>answer;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words.size();j++){
                string ans=words[i];
                
                if(i!=j){
                     string fin=words[j];
                
                if(ans.size()>fin.size()){
                    continue;
                }
            
               
                if(fin.find(ans)!=-1){
                    if(find(answer.begin(),answer.end(),ans)==answer.end()){
                         answer.push_back(ans);

                    }
                   
                }
                }
                
            }
        }
        return answer;
       
        
    }
};