class Solution {
public:
vector<string>ans;
void find(int n,string str){
    if(str.size()==n){
        ans.push_back(str);
        return;
    }
    if(str.empty() || str[str.size()-1]!='a'){
    str.push_back('a');
    find(n,str);
    str.pop_back();
    }
     if(str.empty() || str[str.size()-1]!='b'){
    str.push_back('b');
    find(n,str);
    str.pop_back();
     }
     if(str.empty() || str[str.size()-1]!='c'){
    str.push_back('c');
    find(n,str);
    str.pop_back();
     }
}
    string getHappyString(int n, int k) {
       find(n,"");
       sort(ans.begin(),ans.end());
        if(ans.size()<k)return "";
        return ans[k-1];
    }
};