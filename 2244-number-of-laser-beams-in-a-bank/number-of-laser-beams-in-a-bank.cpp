class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int total=0;
        int count=0;
        int new_count=0;
        for(int i=0;i<bank.size();i++){
            if(count==0){
                string str=bank[i];
                for(int j=0;j<str.size();j++){
                    if(str[j]=='1'){
                        count++;
                    }
                }
            }
            else{
                new_count=0;
                string temp=bank[i];
                for(int j=0;j<temp.size();j++){
                    if(temp[j]=='1'){
                        total+=count;
                        new_count++;
                    }
                }
                if(new_count>0){
                    count=new_count;
                }
            }
        }
        return total;
        
    }
};