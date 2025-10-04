class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string second=to_string(high);
        string first=to_string(low);
        int min_length=first.size();
        int max_length=second.size();
        vector<int>ans;
       for(int i=1;i<=9;i++){
        string res="";
        res+=to_string(i);
        for(int j=i+1;j<=9;j++){
            res+=to_string(j);
            if(res.size()>=min_length){
            if(stoi(res)>=low && stoi(res)<=high){
                ans.push_back(stoi(res));

            }
            if(res.length()>max_length){
                break;

            }
            }

        }
       }
       sort(ans.begin(),ans.end());
       return ans;
        
    }
};