class Solution {
public:
    int totalWaviness(int num1, int num2) {
        
        int count=0;
        for(int i=num1;i<=num2;i++){
            string str=to_string(i);
            for(int i=1;i<str.size()-1;i++){
            if(str[i]-'0'>str[i-1]-'0' && str[i]-'0'>str[i+1]-'0'){
                    count++;
}else if(str[i]-'0'<str[i-1]-'0' && str[i]-'0'<str[i+1]-'0')       {
                count++;
        }
                
            }
            
        }
        return count;
        
        
    }
};