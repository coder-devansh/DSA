class Solution {
public:
    int compress(vector<char>& chars) {
        string s="";
       
        for(int i=0;i<chars.size();){
           long  count=1;
            int j=i+1;
            s+=chars[i];
            
            while(j<chars.size() && chars[j]==chars[i]){
                count++;
                j++;
            }
            i=j;
            if(count>1){
                s+=to_string(count);

            }
            

            
        }
      cout<<s<<endl;
      vector<char>result;
      for(auto it:s){
        result.push_back(it);
      }
      chars=result;
      return s.size();
        
    }
};