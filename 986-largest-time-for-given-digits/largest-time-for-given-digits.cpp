class Solution {
public:
string find_word(string str,unordered_map<int,int>mp){
    if(str=="2"){
            for(int i=3;i>=0;i--){
                 if(mp[i]<=0)continue;
                str+=to_string(i);
                mp[i]--;
                break;
            }

        }
        else if(str=="1" || str=="0"){
            for(int i=9;i>=0;i--){
                if(mp[i]<=0)continue;
                str+=to_string(i);
                mp[i]--;

                break;
            }


        }
        if(str.size()==2){
            str+=":";
        }else{
            return "";
        }
        for(int i=5;i>=0;i--){
            if(mp[i]<=0)continue;
            str+=to_string(i);
            mp[i]--;
            break;
        }
        for(int i=9;i>=0;i--){
            if(mp[i]<=0)continue;
            str+=to_string(i);
            mp[i]--;
            break;
        }
        if(str.size()==5)return str;
        return "";

}
    string largestTimeFromDigits(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto it:arr)mp[it]++;
        string str="";
        string ans="";
        for(int i=0;i<=2;i++){
            if(mp[i]<=0)continue;
            str=to_string(i);
            mp[i]--;
            string word=find_word(str,mp);
            mp[i]++;
            if(word.size()==5){
                ans=word;
            }
            
        }
        return ans;
        
        
    }
};