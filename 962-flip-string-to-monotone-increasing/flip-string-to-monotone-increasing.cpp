class Solution {
public:
// this approach require o(2^N) approach
// space complexity -O(2^N) recursion stack space
// void find(int i,string s,string str){
//     if(i==s.size()){
//         cout<<str<<endl;
//         return;
//     }
//     find(i+1,s,str+'0');
//     find(i+1,s,str+'1');

// }
    int minFlipsMonoIncr(string s) {
       int one=0;
       int flip=0;
       for(int i=0;i<s.size();i++){
        if(s[i]=='1'){
            one++;
        }
        if(s[i]=='0' && one>=1){
            flip++;
        }
        if(one<flip){
            flip=one;
        }
       }
       return min(flip,one);
        
    }
};