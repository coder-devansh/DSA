class Solution {
public:
static bool compare(const string&a,const string&b){
    if(a.size()==b.size()){
        return a<b;
    }
    return a.size()>b.size();
}
bool canbePossible(string str,set<string>&st){
    string word="";
    
    for(int i=0;i<str.size()-1;i++){
        word+=str[i];
        if(st.find(word)==st.end())return false;
    }
    return true;

}
    string longestWord(vector<string>& words) {
    set<string>st;
    vector<string>ans;
    for(int i=0;i<words.size();i++){
        st.insert(words[i]);
    }
    for(int i=0;i<words.size();i++){
        string str=words[i];
        if(canbePossible(str,st)){
            ans.push_back(str);
        }
    
    }
    sort(ans.begin(),ans.end(),compare);
    return ans.size()>0?ans[0]:"";

        
    }
};