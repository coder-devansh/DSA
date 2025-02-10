class Solution {
public:
    string clearDigits(string s) {
        stack<char>q;
        for(int i=0;i<s.size();i++){
          if(s[i]>=97 && s[i]<=123){
                q.push(s[i]);
            }
              else if(!q.empty()){
                q.pop();
            }
        }
        s="";
        while(!q.empty()){
            s+=q.top();
            q.pop();
        }
        reverse(s.begin(),s.end());
        return s;

        
    }
};