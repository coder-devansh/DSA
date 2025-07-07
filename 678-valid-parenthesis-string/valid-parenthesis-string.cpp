class Solution {
public:
    bool checkValidString(string s) {
        int mini=0;
        int maxi=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                mini++;
                maxi++;
            }
            if(s[i]==')'){
                if(maxi-1<0)return false;
                mini=(mini-1<0?mini:mini-1);
                maxi=maxi-1;
            }
            if(s[i]=='*'){
                mini=(mini-1<0?mini:mini-1);
                maxi=maxi+1;
            }
        }
        if(mini==0 || maxi==0){
            return true;
        }
        return false;
        
    }
};