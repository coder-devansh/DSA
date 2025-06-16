class Solution {
public:
vector<string>ans;
void generate(int n,string s,char last){
    if(n==0){
        ans.push_back(s);
        return;
    }
    if(last!='0'){
        generate(n-1,s+'0','0');
    }
    generate(n-1,s+'1','1');
}
    vector<string> validStrings(int n) {
        generate(n,"",'a');
        return ans;
        
    }
};