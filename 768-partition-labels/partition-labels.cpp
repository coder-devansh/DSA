class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]=i;

        }
        vector<int>result;
        map<char,int>temp;
        vector<int>last;
        for(int i=0;i<s.size();i++){
            temp[s[i]]++;
            if(i==mp[s[i]])
            {
                temp.erase(s[i]);
                
                if(temp.size()==0){
                    if(result.size()==0){
                        result.push_back(i+1);
                    }
                    else{
                        result.push_back(i-last[last.size()-1]);
                    }
                    last.push_back(i);
                    
                    
                }
            }

        }
        for(auto it:last) cout<<it<<" ";
        return result;
        


        
    }
};