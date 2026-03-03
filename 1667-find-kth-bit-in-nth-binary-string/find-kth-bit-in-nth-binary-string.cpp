class Solution {
public:
string invert(string str){
    for(auto &it:str){
        if(it=='0'){
            it='1';
        }else if(it=='1'){
            it='0';
        }
    }
    return str;
}
string reverse1(string str){
    reverse(str.begin(),str.end());
    return str;
}
    char findKthBit(int n, int k) {
        string str="0";
        for(int i=2;i<=n;i++){
            str=str+"1"+reverse1(invert(str));
        }
        return str[k-1];

        
    }
};