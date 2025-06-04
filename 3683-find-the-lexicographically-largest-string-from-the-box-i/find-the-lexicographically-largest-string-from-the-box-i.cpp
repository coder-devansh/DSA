class Solution {
public:
    string answerString(string word, int numFriends) {
        int length=word.size()-numFriends+1;
        string final="";
        if(numFriends==1){
            return word;
        }
        for(int i=0;i<word.size();i++){
            if(i+length<=word.size()){
                string ans=word.substr(i,length);
                final=max(final,ans);

            }else if(i+length>word.size()){
                string ans=word.substr(i);
                final=max(final,ans);
            }


        }
        
        return final;
        
    }
};