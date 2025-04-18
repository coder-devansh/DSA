class Solution {
public:
// string find(int n,string s){
//     if(n==0){
//         return s;
//     }
//     int count=1;
//     string ans="";
//     char ch=s[0];
//     for(int i=0;i<s.size()-1;i++)
//     {
       
//         if(ch==s[i+1]){
//             count++;
//         }else if(ch!=s[i+1])
//         {
//             ans+=to_string(count);
//             ans+=ch;
//             ch=s[i+1];
//             count=1;

//         }
        

        
        
//     }
//     ans+=to_string(count);
//     ans+=ch;

//     return find(n-1,ans);
    
// }
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        if(n==2)return "11";
        if(n==3) return "21";
        int val=n-3;
        string s="21";

 while(val>0){
    
    int count=1;
    string ans="";
    char ch=s[0];
    for(int i=0;i<s.size()-1;i++)
    {
       
        if(ch==s[i+1]){
            count++;
        }else if(ch!=s[i+1])
        {
            ans+=to_string(count);
            ans+=ch;
            ch=s[i+1];
            count=1;

        }
        

        
        
    }
    ans+=to_string(count);
    ans+=ch;
    s=ans;
    val--;

        }
        return s;
      
        
        
    }
};