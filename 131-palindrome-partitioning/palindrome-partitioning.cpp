class Solution {
public:
vector<vector<string>>ans;
bool isPalindrome(string val){
    int i=0;int j=val.size()-1;
    while(i<j){
        if(val[i]!=val[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
void fun(int index,string s,vector<string>&temp){
    if(index==s.size()){
        ans.push_back(temp);
        return;

    }
    for(int i=index;i<s.size();i++){
        string val=s.substr(index,i-index+1);
        if(isPalindrome(val)){
            temp.push_back(val);
            fun(i+1,s,temp);
            temp.pop_back();

        }

    }
}

    vector<vector<string>> partition(string s) {
        vector<string>temp;
       fun(0,s,temp);
       return ans;

        
    }
};