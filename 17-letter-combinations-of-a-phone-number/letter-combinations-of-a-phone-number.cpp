class Solution {
public:
vector<string>list;
vector<string>arr={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void find(string digits,string str){
    if(digits.size()==0){
        list.push_back(str);
        return ;
    }
    int ch=digits[0]-'0';
    string ans=arr[ch];
    for(int i=0;i<arr[ch].size();i++){
        find(digits.substr(1),str+ans[i]);
    }

}
    vector<string> letterCombinations(string digits) {
        string str="";
        if(digits.size()==0){
            return list;
        }
        find(digits,"");
        return list;

    }
};