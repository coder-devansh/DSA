class Solution {
public:
// a==z 
// mirror=('a'+('z'-a))
// mirror=z;
// "aczzx"
// mirror='a'+('z'-ch)


    long long calculateScore(string s) {
        unordered_map<char,stack<int>>mp;
        vector<bool>used(s.size()+1,false);
        long long score=0;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            char mirror='a'+('z'-ch);
            if(!mp[mirror].empty() && mp.find(mirror)!=mp.end()){
                int j=mp[mirror].top();
                
                if(!used[j] &&  j<i){
                    score+=i-j;
                    used[j]=true;
                    used[i]=true;
                    mp[mirror].pop();

                }
            }if(!used[i]){
                 mp[s[i]].push(i);

            }
               
            
           

        }
        return score;

    
        
    }
};