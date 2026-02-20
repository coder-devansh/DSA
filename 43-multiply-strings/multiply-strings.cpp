class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")return "0";
        vector<string>temp;
        for(int i=num1.size()-1;i>=0;i--){
            int carry=0;
            string str="";
            for(int j=num2.size()-1;j>=0;j--){
                int mult=(num1[i]-'0')*(num2[j]-'0')+carry;
                 carry=mult/10;
                int number=mult%10;
                str+=to_string(number);

                

            }
            if(carry!=0){
                str+=to_string(carry);
            }
            
            reverse(str.begin(),str.end());
            
            temp.push_back(str);

        }
        int max_size=0;
        for(int i=0;i<temp.size();i++)
        {
            string &str=temp[i];
            for(int j=0;j<i;j++){
                str+='0';

            }
           max_size=max(max_size,(int)str.size());
        }
        for(int i=0;i<temp.size();i++){
            string &str=temp[i];
            while(str.size()<max_size){
                str='0'+str;
            }
        }
        int carry=0;
        string ans="";
        for(int j=temp[0].size()-1;j>=0;j--){
            int sum=0;
            for(int i=0;i<temp.size();i++)
            {
                sum+=temp[i][j]-'0';

            }
            sum+=carry;
            carry=sum/10;
            ans+=to_string(sum%10);

        }
        if(carry!=0)ans+=to_string(carry);
        reverse(ans.begin(),ans.end());
        return ans;
        
       
        
    }
};