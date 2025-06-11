class Solution {
public:
void revers(string&s,int i,int k){
    while(i<k){
        swap(s[i],s[k]);
        i++;
        k--;
    }
    
}
    string reverseWords(string s) {
        int i=0;
        int j=s.size()-1;
        reverse(s.begin(),s.end());
        for(;i<s.size();i++){
            if(s[i]!=' '){
                break;
            }
        }
        for(;j>=0;j--){
            if(s[j]!=' '){
                break;
            }
        }
        int l=i;
        int m=j;
        int k=0;
        string ans="";
        while(i<=j && k<=j){
            while(k<=j && s[k]!=' '){
                k++;
            }
            revers(s,i,k-1);
            while(s[k]==' '){
                k++;
            }
            i=k;
        }
        i=l;

        j=m;
        for(;i<=j;){
            if(s[i]!=' '){
                ans+=s[i];
            }
            if(s[i]==' '){
                while(s[i]==' '){
                i++;
                if(i>=j)break;
            }
            ans+=" ";

            }else{
                i++;
            }
            
           
        }
        return ans;
       

        
    }
};