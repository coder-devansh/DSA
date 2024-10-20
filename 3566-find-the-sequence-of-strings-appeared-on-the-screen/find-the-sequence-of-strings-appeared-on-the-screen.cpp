class Solution {
public:
void find(string target){

}
    vector<string> stringSequence(string target) {
        string ans="a";
         vector<string>result;

        while(ans!=target){
            if(ans==target.substr(0,ans.size()))
            {
                result.push_back(ans);
                ans+='a';

            }else{
                result.push_back(ans);
                ans[ans.size()-1]+=1;
                
            }

        }
        result.push_back(target);
        return result;
                     
        
    }
};