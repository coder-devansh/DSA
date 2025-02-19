class Solution {
public:
vector<string>result;
void generate(int i,int n,int k,string ans){
    if(n==ans.size()){
        result.push_back(ans);

        cout<<ans<<endl;
        return;
    }

    for(char ch='a';ch<='c';ch++){
       if(i==0 || ch!=ans[i-1])
       {
        generate(i+1,n,k,ans+ch);

       }
    }
}
    string getHappyString(int n, int k) {
        generate(0,n,k,"");
      
       if(k>result.size()){
        return "";
       }
       return result[k-1];
        
        
    }
};