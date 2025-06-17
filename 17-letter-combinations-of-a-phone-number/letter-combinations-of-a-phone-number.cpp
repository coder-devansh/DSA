class Solution {
public:
vector<string>alpha={"0","0","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
vector<string>ans;
void find(int i,string digits,string temp){
    if(i==digits.size()){
        ans.push_back(temp);
        return;
    }
    string val=alpha[digits[i]-'0'];
    for(int k=0;k<val.size();k++){
        find(i+1,digits,temp+val[k]);
    }


}

    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return {};
        find(0,digits,"");
        return ans;
        
    
        
    }
};