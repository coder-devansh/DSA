class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       string ans="";
      
       bool match=true;
       for(int i=0;i<strs[0].size();i++)
       {
        char ch=strs[0][i];
        for(int j=1;j<strs.size();j++)
        {
            if(strs[j][i]==ch)
            {
              

                
            }
            else{
                match=false;

                break;
            }
        }
        if(match==true)
        {
            ans.push_back(ch);
        }

          
       }
       
       return ans;
        
    }
};