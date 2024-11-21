class Solution {
public:
int count=0;
void find(int i,vector<int>nums){
    vector<int>copy1;
    vector<int>copy2;
    vector<int>check1(nums.size(),0);
    
    copy1=nums;
    copy2=nums;
    char ch='R';
    int j=i;

    while(i>=0 && i<=nums.size()-1)
    {
      if(copy1[i]==0)
      {
        if(ch=='R')
        {
            i++;
        }
        else{
            i--;
        }
    }else if(copy1[i]>0){
        copy1[i]--;
        if(ch=='R'){
            ch='L';
            i--;
        }else{
            ch='R';
            i++;
        }

    }
}
     ch='L';
     
    while(j>=0 && j<=nums.size()-1)
    {
      if(copy2[j]==0)
      {
        if(ch=='R')
        {
            j++;
        }
        else{
            j--;
        }
    }else if(copy2[j]>0){
        copy2[j]--;
        if(ch=='R'){
            ch='L';
            j--;
        }else{
            ch='R';
            j++;
        }

    }
    }
    if(copy1==check1){
        count++;
    }
    if(copy2==check1){
        count++;
    }

}
    int countValidSelections(vector<int>& nums) {
        vector<int>zeros;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zeros.push_back(i);
            }

        }
        for(int i=0;i<zeros.size();i++){
            find(zeros[i],nums);
        }
       
        return count;
        
    }
};