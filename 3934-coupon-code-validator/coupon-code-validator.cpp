class Solution {
public:
static bool compare(pair<string,string>&a,pair<string,string>&b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    return a.second<b.second;
}
bool isValid(string str){
    if(str.size()==0)return false;
    for(int i=0;i<str.size();i++){
if(!(('A'<=str[i] && str[i]<='Z') || (str[i]-'0'>=0 && str[i]-'0'<=9))){
    if(str[i]=='_')continue;
    if(str[i]>='a' && str[i]<='z')continue;
    return false;
}
    }
    return true;
}
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<string,string>>ans;
        for(int i=0;i<code.size();i++){
            if(!isActive[i])continue;
            if(isValid(code[i])){
                        if(businessLine[i]=="invalid")continue;
                ans.push_back({code[i],businessLine[i]});
            }


        }
        sort(ans.begin(),ans.end(),compare);
        vector<string>result;
        for(auto it:ans){
            result.push_back(it.first);
        }
        return result;
        
    }
};