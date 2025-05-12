class Solution {
public:
// static bool custom(int a,int b){
//     if(a==0){
//         return a>b;
//     }
//     if(b==0){
//         return b>a;
//     }
//     return a<b;
// }
    vector<int> findEvenNumbers(vector<int>& digits) {
       map<int,int>mp;
       for(auto it:digits){
        mp[it]++;
       }
       map<int,int>check;
       vector<int>ans;
       for(int i=100;i<=999;i++){
        if(i%2==0){

             string str=to_string(i);
        bool find=true;
         check=mp;
        for(int j=0;j<str.size();j++){
           
            if(check.find(str[j]-'0')==check.end()){
               find=false;
               break;
            }else{
                check[str[j]-'0']--;
                if(check[str[j]-'0']==0){
                    check.erase(str[j]-'0');
                }
            }
        }
        if(find==true){
            
            ans.push_back(i);

        }

        }
       
        
       }
       return ans;

        
        
    }
};