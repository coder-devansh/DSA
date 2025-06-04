class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros=0;
        int ones=0;
        int two=0;
        for(auto it:nums){
           if(it==0)zeros++;
           if(it==1)ones++;
           if(it==2)two++;

        }
        nums.clear();
        while(zeros>0){
            nums.push_back(0);
            zeros--;

        }
        while(ones>0){
            nums.push_back(1);
            ones--;

        }
        while(two>0){
            nums.push_back(2);
            two--;

        }
       
    }
};